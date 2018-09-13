'''
hdInterface.py created by Witold on 2/1/2017 under the pygametrial project

OUTDATA:
'%PCLL0101$'
'%STRM0000$'
'STOP0000$'
INDATA:
everytime he gets valid command he sends out following:
'%PCLLRECE$'
'%STRMRECE$'
'%STOPRECE$'
for per call and stream, he sends:
'%[N][:[DATA_TYPE][DATA]]$'
where:
N = length of entire string
DATA_TYPE = any of 'TI', 'LO', 'TE', 'HU'
For GPS TIME:
'Time: 23:16:15.999Date: 15/12/2017'


'''
import serial
import threading as t
import time as tm
import re
#commands and special chars
PER_CALL = 'PCLL'
STREAM = 'STRM'
STOP = 'STOP'
RECEIVED = 'RECE'
START_CHAR = '%'
END_CHAR = '$'
COLON = ':'
#codes for incoming data
NO_GPS = 'No GPS'
#regex constants
MATCH_BEG = '^'
MATCH_END = '$'
ESCAPE = '\\'
OR = '|'
PAR_BEG = '('
PAR_END = ')'
#regex strings
ACK_COMM = MATCH_BEG + PAR_BEG + START_CHAR + PAR_BEG + STREAM + OR + PER_CALL + OR + STOP + PAR_END + RECEIVED + ESCAPE + END_CHAR + PAR_END + MATCH_END
ACK_COMM = '^(%(STRM|PCLL|STOP)RECE\$)$'
DATA_IN_COMM = '^(%([0-9]+(:(TI|LO|TE|HU|AN|FO|MI)[No GPS0-9.]+)+)\$)$'
N_NUM_SUB = '^%[0-9]+'
DATA_SUB = ':(TI|LO|TE|HU|AN|FO|MI)([0-9.,-]+|No GPS|Time: [0-9:.]+Date: [0-9/]+)'
#regex patterns
ack_comm_pat = re.compile(ACK_COMM)
data_in_comm_pat = re.compile(DATA_IN_COMM)
m = ack_comm_pat.match('sdf')
#data types
TI = 'TI'
LO = 'LO'
TE = 'TE'
HU = 'HU'
AN = 'AN'
FO = 'FO'
MI = 'MI'
maxretries = 100
class HardWare:
    def __init__(self, app):
        self.retries = 0
        self.threadLock = t.Lock()
        self.app = app
        self.initConnThread()
    def initConnThread(self):
        connThread = t.Thread(target = self.establishConnection)
        connThread.daemon = True
        connThread.start()
        
    def establishConnection(self):
        self.arduino = None
        self.connected = False
        with self.threadLock:
            try:
                self.arduino = serial.Serial(
                    port='/dev/ttyUSB0',
                    baudrate = 19200,
                    timeout=0.1
                )
                self.establishedConnection()
                print('Established connection on port USB0')
            except Exception as e:
                print('serial USB 0 establish error:', str(e))
                try:
                    self.arduino = serial.Serial(
                        port='/dev/ttyUSB1',
                        baudrate = 19200,
                        timeout=0.1
                    )
                    self.establishedConnection()
                    print('Established connection on port USB1')
                except Exception as e:
                    print('serial USB 1 establish error:', str(e))
                if not self.isConnected():
                    self.connectionFailed()
    def establishedConnection(self):
        self.connected = True
        while not self.app.running:
            tm.sleep(0.1)
        self.app.view.connectionEstablished()
    def connectionFailed(self):
        self.connected = False
    def isConnected(self):
        #with self.threadLock:
        return self.connected
    def initStreamReadThread(self):
        streamReadThread = t.Thread(target = self.readStreamData)
        streamReadThread.daemon = True
        streamReadThread.setDaemon(True)
        streamReadThread.start()
    def startStream(self):
        self.sendCommand(STREAM)
        while self.retries < maxretries:
            self.retries += 1
            if self.ardUnderstood(STREAM):
                print('in startStream arduino understood, starting thread')
                self.retries = 0
                self.setStream(True)
                self.initStreamReadThread()
                break
    def setStream(self, bool):
        with self.threadLock:
            self.streaming = bool
    def isStreaming(self):
        with self.threadLock:
            return self.streaming
    def stopStream(self):
        self.sendCommand(STOP)
        while self.retries < maxretries:
            self.retries += 1
            if self.ardUnderstood(STOP):
                print('understood stop')
                self.setStream(False)
                self.retries = 0
                break
            else:
                pass

    def sendCommand(self, comm):
        if self.isConnected():  
            command = START_CHAR + comm + '0000' + END_CHAR
            self.writeToArd(command)

    def readStreamData(self):
        while self.isStreaming():
            tm.sleep(0.1)
            dataIn = self.readFromArd()
            self.parseData(dataIn)
    def parseData(self, ard_input):
        act_len = len(ard_input)
        info_lenMatchObj = re.match(N_NUM_SUB, ard_input)
        if info_lenMatchObj == None:
            return
        info_len = int(info_lenMatchObj.group(0)[1:])
        if act_len != info_len:
            print('actual length: '+str(act_len))
            print('informed length: '+str(info_len))
            print('Lengths do not match.')
            return
        data_list = re.findall(DATA_SUB, ard_input)
        print(data_list)
        ttl_list = []
        for data in data_list:
            ttl_list.append(data[0])
        if FO in ttl_list and AN in ttl_list and MI in ttl_list:
            with self.threadLock:
                self.processStreamData(data_list)
        else:
            for data in data_list:
                self.processData(data)
    def processStreamData(self, data_list):
        print('processing streamin data')
        for data in data_list:
            print(data[0], data[1])
            if data[0] == FO:
                forceValue = data[1]
            elif data[0] == AN:
                angleValue = data[1]
            elif data[0] == MI:
                timeValue = data[1]
        self.app.view.fullStreamDataIn(angleValue, forceValue, timeValue)

    def processData(self, data):
        print('processing data')
        print('tag: '+data[0]+ ', value: '+ data[1])
        tag = data[0]
        value = data[1]
        if tag == TI:
            # 'Time: 23:16:15.999Date: 15/12/2017'
            [timeHeader, time, date] = value.split(' ')
            [hour, minute, second] = time[:-5].split(':')
            [second, milli] = second.split('.')
            [day, month, year] = date.split('/')
            print(year, month, day, hour, minute, second, milli)
            self.app.view.timeIn(year, month, day, hour, minute, second, milli)
        elif tag == LO:
            if value == NO_GPS:
                self.app.view.noGPS()
            else:
                [xString, yString] = data[1].split(',')
                x = float(xString)
                y = float(yString)
                self.app.view.locationIn(x, y)
        elif tag == TE:
            self.app.view.temperatureIn(value)
        elif tag == HU:
            self.app.view.humidityIn(value)
        elif tag == AN:
            self.app.view.angleIn(value)
        elif tag == FO:
            self.app.view.forceIn(value)
        elif tag == MI:
            self.app.view.millisIn(value)

    def getHumidity(self):
        self.getPerCall(hum = '1')
    def getTime(self):
        self.getPerCall(time = '1')
    def getTemperature(self):
        print('in hd: get temp')
        self.getPerCall(temp = '1')
    def getLocation(self):
        self.getPerCall(loc = '1')
    def getAll(self):
        self.getPerCall('1','1','1','1')
    def getPerCall(self, temp = '0', hum = '0', loc ='0', time ='0'):
        if self.isConnected():
            perCallThread = t.Thread(target = self.getPerCallThread, args = (temp, hum, loc, time))# kwargs={'temp': temp, 'hum': hum,'loc': loc,'time': time})
            perCallThread.daemon = True
            perCallThread.start()
    def getPerCallThread(self, temp = '0', hum = '0', loc ='0', time ='0'):
        print('in: getPercallThread', self.retries)
        command = START_CHAR + PER_CALL + time +loc + hum + temp + END_CHAR
        self.writeToArd(command)
        understood = False
        while not understood and self.retries < maxretries:
            understood = self.ardUnderstood(PER_CALL)
            self.retries += 1
        self.retries = 0           
        if understood:
            self.parseData(self.readFromArd())                   
    def ardUnderstood(self, comm):
        ard_inp = self.readFromArd()
        #if re.match('^(%' + comm + 'RECE\$)$', ard_inp) != None:
        if ard_inp[1:5] == comm:
            print('UNDERSTAND:', comm)
            return True
        else:
            print('NOT UNDERSTAND:', comm)
            return False
    def writeToArd(self, comm):
        print('Writing command of length ' +str(len(comm))+':', comm)
        with self.threadLock:
            self.arduino.flush()
            self.arduino.flushInput()
            self.arduino.flushOutput()
            self.arduino.write((comm + '\n').encode())
    def readFromArd(self):
        with self.threadLock:
            incomingByte = self.arduino.readline()
        incomingString = incomingByte.decode()
        incoming = incomingString.rstrip()
        print('...')
        print(incoming)
        print('...')
        #self.arduino.flushInput()
        return incoming
#     def readFromArd(self):
#         #incomingByte = self.arduino.read()
#         print('in waiting', self.arduino.inWaiting())
#         incomingString = ''
#         #incomingChar = incomingByte.decode('utf-8')
#         #print(incomingChar)
#         #if incomingChar == '%':
#             #incomingString+=incomingChar
#         gotMSG = False
#         while not gotMSG and self.arduino.inWaiting():
#             incomingByte = self.arduino.read()
#             incomingChar = incomingByte.decode('utf-8')
#             print(incomingChar)
#             incomingString += incomingChar
#             if incomingChar == '$':
#                 gotMSG = True
#         print('...')
#         print(incomingString)
#         print('...')
#         return incomingString