'''
hdInterface2.py created by Witold under the cropDevice2 project
THIS HDINTERFACE CONTINUOUSLY RUNS DATA READING
'''
import pygame as pg
import defs as d
import serial
import threading as thr
import time as t
import os
import re
#commands and special chars
PER_CALL = 'PCLL'
STREAM = 'STRM'
LIVE = 'LIVE'
STOP = 'STOP'
READY = 'RDDY'
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
#ACK_COMM = MATCH_BEG + PAR_BEG + START_CHAR + PAR_BEG + STREAM + OR + PER_CALL + OR + STOP + PAR_END + RECEIVED + ESCAPE + END_CHAR + PAR_END + MATCH_END
ACK_COMM = '^(?:%(STRM|PCLL|STOP|RDDY|LIVE)RECE\$)$'
DATA_IN_COMM = '^(%[0-9]+(:(TI|LO|TE|HU|AI|AP|FX|FY|MI)(No GPS|[0-9.,-]+| NAN|Time: [0-9:.]+Date: [0-9/]+))+\$)$'
N_NUM_SUB = '^%[0-9]+'
DATA_SUB = ':(TI|LO|TE|HU|AI|AP|FX|FY|MI)([0-9.,-]+|No GPS| NAN|Time: [0-9:.]+Date: [0-9/]+)'
#regex patterns
# ack_comm_pat = re.compile(ACK_COMM)
# data_in_comm_pat = re.compile(DATA_IN_COMM)
# m = ack_comm_pat.match('sdf')
#data types
TI = 'TI'
LO = 'LO'
TE = 'TE'
HU = 'HU'
#AN = 'AN'
AI = 'AI'
AP = 'AP'
FX = 'FX'
FY = 'FY'
MI = 'MI'
# Connection tries
MAX_CONN_TRIES = 1
CONN_TIMEOUT = 3
class HardWare:
    def __init__(self, app):
        self.lastPerCall = t.time()
        self.lastIn = t.time()
        self.threadLock = app.threadLock#thr.Lock()
        self.app = app
        self.connected = False
        self.initConnThread()
    def initConnThread(self):
        
        if os.path.exists(d.SERIAL_LOG_FILE + d.LOG_FORMAT):
            logPath = d.SERIAL_LOG_FILE
            i = 2
            while os.path.exists(logPath +'(' + str(i) + ')' + d.LOG_FORMAT):
                i+=1
            logPath = logPath +'(' + str(i) + ')' + d.LOG_FORMAT
        else:
            logPath = d.SERIAL_LOG_FILE + d.LOG_FORMAT
            
#         self.logFile = open(logPath,'a')

        connThread = thr.Thread(target = self.establishConnection)
        connThread.setName('CONNECTION THREAD')
        connThread.daemon = True
        connThread.start()
    def startReadThread(self):
        self.readFromSerial = True
        readThread = thr.Thread(target = self.readSerial)
        readThread.setName('READ THREAD')
        readThread.daemon = True
        readThread.start()
        print('started read thread')
    def stopReadThread(self):
        self.readFromSerial = False
    def establishConnection(self):
        self.arduino = None
        tries = 0
        while not self.isConnected() and tries < MAX_CONN_TRIES:
            tries +=1
            #with self.threadLock:
            try:
                self.arduino = serial.Serial(
                    port='/dev/serial0',
                    baudrate = 19200,
                    timeout=0.005
                )
                print('Established connection on port USB0')
                self.startReadThread()

                self.confirmConnection()
                return
            except Exception as e:
                print('serial USB 0 establish error:', str(e))
                try:
                    self.arduino = serial.Serial(
                        port='/dev/serial1',
                        baudrate = 19200,
                        timeout=0.005
                    )
                    print('Established connection on port USB1')
                    self.startReadThread()

                    self.confirmConnection()
                    return
                except Exception as e:
                    print('serial USB 1 establish error:', str(e))
        self.connectionFailed()
    def closeConnection(self):
#         self.logFile.close()
        print('closeConnection()')
        if self.arduino is not None:
            self.stopReadThread()
#             self.stopStream()
            self.connected = False
            self.arduino.close()
            self.arduino = None
            
    def confirmConnection(self):
        print('connection made, waiting for confirmation')
        self.stopStream()

        initQueryT = t.time()
        while t.time() - initQueryT < CONN_TIMEOUT:
#             print('waiting for readiness')
            if self.isConnected():
                return
        if not self.isConnected():
            self.connectionFailed()    
    def connectionConfirmed(self):
        if not self.isConnected():
            print('connection confirmed')
            self.connected = True
            if self.app.view is not None:
                msgInd = self.app.view.getMsgIndexByTtl('Serial connection failed')
                if msgInd != -1:
                    self.app.view.deleteMsgByIndex(msgInd)
            self.getAll()

    def connectionFailed(self):
        print('connection failed')
        self.connected = False
        self.app.serialConnFail()

    def isConnected(self):
        #with self.threadLock:
        return self.connected
###########################################################
#READING DATA
########################################################## 
    def readSerial(self):
        while self.readFromSerial:
            #if self.app.streaming:
            ard_input = self.readFromArd()
#             print('READ THREAD: |' + ard_input + '|')

            if len(ard_input) > 0:
#                 self.logFile.write('READ: |' + ard_input + '|\n')
#                 if not self.app.streaming:
#                     print('not self.app.streaming: |' + ard_input + '|')
                 
#                 print('READ THREAD: |' + ard_input + '|')
                #check if acknowledgement
                if re.match(ACK_COMM, ard_input) != None:        #check if dataIn
                    #we have an acknowledgement
#                     print('ACKNOWLEDGEMENT: |' + ard_input + '|')
#                     print('T diff', t.time() - self.lastPerCall)   
                
                                     
                    ack_comm = re.findall(ACK_COMM, ard_input)[0]
                    self.parseAck(ack_comm)
                elif re.match(DATA_IN_COMM, ard_input) != None:
#                     print('DATA IN: |' + ard_input + '|')
#                     if not self.app.streaming:
#                         print('T diff 2', t.time() - self.lastPerCall)                    
#                         self.lastPerCall = t.time()
                    if self.app.view is not None:
                        self.parseData(ard_input)
                    else:
                        if not self.isConnected():
                            self.connectionConfirmed()
                else:
#                     print('NOT DATA IN: |' + ard_input + '|')
                    pass
                #t.sleep(0.01)
#             print('4a')

###########################################################
#PARSING DATA
########################################################## 
    def parseAck(self, ack_comm):
        if not self.isConnected():
            print('CONN MADE ANCKNOWLEDGEMENT:', ack_comm)
            self.connectionConfirmed()

#         if ack_comm == READY:
        print('ANCKNOWLEDGEMENT:', ack_comm)
    def parseData(self, ard_input):

        act_len = len(ard_input)
        info_lenMatchObj = re.match(N_NUM_SUB, ard_input)
        if info_lenMatchObj == None:
            return
        info_len = int(info_lenMatchObj.group(0)[1:])
        if act_len != info_len:
            print('actual length: '+str(act_len))
            print(ard_input)
            print('informed length: '+str(info_len))
            print('Lengths do not match.')
            return
        data_list = re.findall(DATA_SUB, ard_input)
        #print(data_list)
#         ttl_list = []
#         for data in data_list:
#             ttl_list.append(data[0])
#         if FX in ttl_list and FY in ttl_list and AI in ttl_list and AP in ttl_list and MI in ttl_list:
#             self.processStreamData(data_list)
#         else:
        with self.threadLock:
            for data in data_list:
                self.processData(data)
#     def processStreamData(self, data_list):
#         print('processing streamin data')
#         for data in data_list:
#             #print(data[0], data[1])
#             if data[0] == FX:
#                 forceValueX = data[1]
#             elif data[0] == FY:
#                 forceValueY = data[1]
# #             elif data[0] == AN:
# #                 angleValue = data[1]
#             elif data[0] == AP:
#                 anglePot = data[1]
#             elif data[0] == AI:
#                 angleImu = data[1]
#             elif data[0] == MI:
#                 timeValue = data[1]
#         if self.app.streaming:
#             self.app.view.fullStreamDataIn(anglePot, angleImu, forceValueX, forceValueY, timeValue)
#         else:
#             self.stopStream()

    def processData(self, data):
        #print('processing data')
        #print('tag: '+data[0]+ ', value: '+ data[1])
        tag = data[0]
        value = data[1].strip()
        if tag == TI:
            # 'Time: 23:16:15.999Date: 15/12/2017'
            [timeHeader, time, date] = value.split(' ')
            [hour, minute, second] = time[:-5].split(':')
            [second, milli] = second.split('.')
            [day, month, year] = date.split('/')
            #print(year, month, day, hour, minute, second, milli)
            self.app.view.timeIn(year, month, day, hour, minute, second, milli)
        elif tag == LO:
            if value == NO_GPS:
                self.app.view.noGPS()
            else:
                print(data[1])
                [xString, yString] = data[1].split(',')
                x = float(xString)
                y = float(yString)
                self.app.view.locationIn(x, y)
        elif tag == TE:
            self.app.view.temperatureIn(value)
        elif tag == HU:
            self.app.view.humidityIn(value)
        elif tag == AP:
            self.app.view.anglePotIn(value)
        elif tag == AI:
            self.app.view.angleImuIn(value)
        elif tag == FX:
            self.app.view.forceXIn(value)
        elif tag == FY:
            self.app.view.forceYIn(value)
        elif tag == MI:
            self.app.view.millisIn(value)
###########################################################
#REQUESTING DATA
########################################################## 

    def getHumidity(self):
        self.getPerCall(hum = '1')
    def getTime(self):
        self.getPerCall(time = '1')
    def getTemperature(self):
        self.getPerCall(temp = '1')
    def getLocation(self):
        self.getPerCall(loc = '1')
    def getAll(self):
        self.lastPerCall = t.time()
        self.getPerCall('1','1','1','1')
    def getPerCall(self, temp = '0', hum = '0', loc ='0', time ='0'):
        command =  PER_CALL+time +loc + hum + temp
        self.sendCommand(command)
    def startStream(self, angle = '1', force = '1', millis = '1'):
        command = STREAM+'0'+angle+force+millis
        self.sendCommand(command)
    def startLive(self):
        command = LIVE+'0000'
        self.sendCommand(command)
        
    def stopStream(self):
        command = STOP+'0000'
        self.sendCommand(command)
    def sendCommand(self, command):
        ardCommand = START_CHAR+command+END_CHAR

        cmdThread = thr.Thread(target = self.writeToArd, args = (ardCommand,))
        cmdThread.setName('SEND COMMAND THREAD')
        cmdThread.daemon = True
        cmdThread.start()
        #self.writeToArd(ardCommand)
    def writeToArd(self, comm):
        with self.threadLock:
            try:
#             if self.arduino is not None:
                print('Writing command of length ' +str(len(comm))+':', comm)
#                 self.logFile.write('WRITE: |' + comm + '|\n')

                self.arduino.flushInput()
                self.arduino.flushOutput()
                self.arduino.write((comm + '\n').encode('utf-8'))
#             else:
            except Exception as e:
                print('Cannot write command of length ' +str(len(comm))+': ' + comm + '. Error:', str(e))
#                 print('Arduino is none. Cannot write command of length ' +str(len(comm))+':', comm)
                if self.app.running:
                    self.closeConnection()
                    self.initConnThread()

                
    def readFromArd(self):
        with self.threadLock:
            try:
    #             print('reading line')                
                incomingBytes = self.arduino.readline()
    #             print('read line')                
    
                incomingString = incomingBytes.decode()
                incoming = incomingString.rstrip()
                return incoming
            except Exception as e:
                print('Invaid data received: ' + str(e))
                print('most likely due to constant streaming')
                print('closing connection')
                self.closeConnection()
                self.initConnThread()
                return ''
    
    
    def startThread(self, name, funct, args = None):
        thread = thr.Thread()
        thread.setDaemon(True)
