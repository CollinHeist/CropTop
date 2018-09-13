import pygame as pg
import views.view as v
import defs as d
import time as t
import numpy as np
from items import noteList as nl
from items import graph as g
from items import message as msg
from views import keyboardView as kbv
from items import rectLabel as rl
from items import viewBtn as vb
from utils import dateParse as dp
import threading as thr
import time as t
ADC = 'ADC'
REAL = 'REAL'
A = 'a'
B = 'b'

preTest = 0
inTest = 1

class CalibrationView(v.View):
    def __init__(self, app, sensorType, sensorName, prevView = None):
        self.title = 'CALIBRATION: ' + sensorName
        self.btnDefs = [
                (
                    {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
                    {'label': 'NEW\nVALUE', 'id': 'newValBtn', 'funct': self.newValue},
                    {'label': 'ADD\nPOINT', 'id': 'addPointBtn', 'funct': self.startSampling},#self.addPoint},
                    {'label': 'CANCEL', 'id': 'cancelBtn', 'funct': self.cancel}
                )
            ]

        super().__init__(app, prevView)

        self.sensorType = sensorType
        self.sensorName = sensorName
                
        self.sensorData = self.app.getSetting(d.SENSOR_BANK)[self.sensorType][self.sensorName]
        
        self.numBtnX = self.cax
        self.numBtnY = self.cay
        
        self.adcVals = np.array([])#dependent var
        self.realVals = np.array([])#independent var
        
        self.resetVectors()
        self.initLayout()
        
        self.startQuerying()
    def initLayout(self):
        self.nls = []       
        self.nls.append(nl.NoteList(self.app, self.disp,
                                    {'x':self.cax - self.caxdim/2 + 2*d.px,'y':self.cay, 'xdim':10*d.px, 'ydim': 45*d.py},
                                    list = [],
                                    listName='REAL',
                                    hasFocus = True)
                        )
        self.nls.append(nl.NoteList(self.app, self.disp,
                                    {'x':self.cax - self.caxdim/2 + 13*d.px,'y':self.cay, 'xdim':10*d.px, 'ydim': 45*d.py},
                                    list = [],
                                    listName='ADC',
                                    hasFocus = True)
                        )

        self.infoBtnDefs = (
            {'label': 'REAL', 'id': REAL, 'value': '_','funct': None},
            {'label': 'ADC', 'id': ADC,'value': '_','funct': None},
            {'label': 'a', 'id': 'a','value': '_', 'funct': None},
            {'label': 'b', 'id': 'b','value': '_', 'funct': None}
        )

        self. infoBtns = []
        
        self.infoBtnsCols = (self.cax - self.caxdim/2 + 1*self.caxdim/8, self.cax - self.caxdim/2 + 3*self.caxdim/8,
                             self.cax - self.caxdim/2 + 5*self.caxdim/8, self.cax - self.caxdim/2 + 7*self.caxdim/8)
        self.infoBtnsRows = [self.cay + 42*d.py]

        self.numInfoBtnRow = len(self.infoBtnsRows)
        self.numInfoBtnCom = len(self.infoBtnsCols)
        for i in range(len(self.infoBtnDefs)):
            row = self.infoBtnsRows[i // self.numInfoBtnCom]
            col = self.infoBtnsCols[i % self.numInfoBtnCom]
            self.infoBtns.append(vb.ViewBtn(app = self.app,
                                            pos = (col, row),
                                            dim = (16*d.px, 14*d.py),
                                            label = self.infoBtnDefs[i]['label'],
                                            value = self.infoBtnDefs[i]['value'],
                                            id = self.infoBtnDefs[i]['id'],
                                            formating = lambda lab, val: lab + ':\n' +(str("%.2f" % val) if type(val) == type(0.0) else str(val)) + (self.sensorData['unit'] if self.infoBtnDefs[i]['id'] == REAL or self.infoBtnDefs[i]['id'] == ADC else '')
                                            )
                                 )
#             self.infoBtns.append(self.SettingBtn(self.app, {'x': col, 'y': row}, self.infoBtnDefs[i], self.sensorData['unit'] if self.infoBtnDefs[i]['label'] == REAL else ''))
        
        self.inPrRect = rl.RectLabel(app = self.app,
                             pos = (self.cax,  self.cay),
                             dim = (70*d.px, 70*d.py),
                             text = 'DATA COLLECTION\nIN PROGRESS',
                             font = self.app.viewTtlFont,
                             fontCol = self.app.font_col,
                             bcgCol = d.light_green,
                             scaleFactor = 0.7
                             )#in progress rectangle

        self.graph = self.app.testingView.graph
        self.graph.updatePlot(                    
                    xlabel = 'REAL ' + self.sensorType + ' [' + self.sensorData['unit'] + ']',
                    ylabel = self.sensorType + ' ADC'
)
#         self.startGraph()
#     def startGraph(self):
#         self.graph = g.Graph(self.disp, {'x':self.cax+10*d.px, 'y':self.cay-8*d.py, 'xdim': 50, 'ydim':63})
    
    def save(self):
        
        a = self.getBtnValById(A)
        b = self.getBtnValById(B)
        if type(a) != type(0.0) or type(b) != type(0.0):#invalid a or b parameters (not floats)
        
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Cannot save.',
                                    'Incomplete calibration. Add at least two points.',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            return
        self.stopQuerying()

        self.sensorData[d.SENSOR_A] = a
        self.sensorData[d.SENSOR_B] = b
        self.sensorData[d.SENSOR_LAST] = dp.DateParse(self.app.getEnvData(d.TIME)).getDateTime()
        
        #make it more efficient - access only needed data fields
        allSensors = self.app.getSetting(d.SENSOR_BANK)
        allSensors[self.sensorType][self.sensorName] = self.sensorData
        self.app.saveSetting(d.SENSOR_BANK, allSensors)
        self.goBack()      
        
          
    def addPoint(self):
        realVal = self.getBtnValById(REAL)
        if type(realVal) != type(0.0):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Invalid real value.',
                                    'Add a valid real value',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            return
        adcVal = self.getBtnValById(ADC)
        self.nls[0].appendNote(str(realVal))
        self.nls[1].appendNote(str(adcVal))

        self.adcVals = np.append(self.adcVals, float(adcVal))    
        self.realVals = np.append(self.realVals, float(realVal))
        
        if len(self.realVals) >= 2:
            try:
                self.computeBestFit()
                    #update with best fit line
                self.graph.updatePlot(
                    x = self.realVals,
                    y1 = self.adcVals,
                    xlabel = 'REAL ' + self.sensorType + ' [' + self.sensorData['unit'] + ']',
                    ylabel = self.sensorType + ' ADC',
                    a = float(self.getBtnValById(A)),
                    b = float(self.getBtnValById(B))
                )
            except Exception as e:
                self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Best fit calculation error',
                                        'Error: ' + str(e),
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                        )
                             )
 
        else:
            self.graph.updatePlot(
                x = self.realVals,
                y1 = self.adcVals,
                xlabel = 'REAL ' + self.sensorType + ' [' + self.sensorData['unit'] + ']',
                ylabel = self.sensorType + ' ADC'
            )
#     def checkRealVal(self):
        
    def addPoint2(self):
        realVal = self.getBtnValById(REAL)
        if type(realVal) != type(0.0):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Invalid real value.',
                                    'Add a valid real value',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            return

        adcVal = np.mean(self.dataVector)
        self.resetVectors()
        
        self.nls[0].appendNote(str(realVal))
        self.nls[1].appendNote(str(adcVal))
        
        self.adcVals = np.append(self.adcVals, float(adcVal))    
        self.realVals = np.append(self.realVals, float(realVal))
        print('finished adding to notelists')
        if len(self.realVals) >= 2:
            try:
                self.computeBestFit()
                    #update with best fit line
                self.graph.updatePlot(
                    x = self.realVals,
                    y1 = self.adcVals,
                    xlabel = 'REAL ' + self.sensorType + ' [' + self.sensorData['unit'] + ']',
                    ylabel = self.sensorType + ' ADC',
                    a = float(self.getBtnValById(A)),
                    b = float(self.getBtnValById(B))
                )
            except Exception as e:
                self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Best fit calculation error',
                                        'Error: ' + str(e),
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                        )
                             )
 
        else:
            self.graph.updatePlot(
                x = self.realVals,
                y1 = self.adcVals,
                xlabel = 'REAL ' + self.sensorType + ' [' + self.sensorData['unit'] + ']',
                ylabel = self.sensorType + ' ADC'
            )
            
    def newValue(self):
#         from views import realInputView as riv
        self.app.setView(kbv.KeyboardView(self.app, self,
                                             d.NUM,
                                             'Applied real value',
                                             REAL,
                                             suffix = self.sensorData['unit']
                                             ))

#         self.app.setView(riv.RealInputView(self.app, self, self.sensor, self.sensorData['unit']))

    def cancel(self):
        self.stopQuerying()
        self.goBack()
        
    def keyboardReturn(self, key, value, status = 1):
        if key ==REAL:
            try:
                self.setLabelById(REAL, self.sensorType, float(value))    
            except Exception as e:
                self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Invalid input',
                                        'Error: ' + str(e),
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {'label': 'RETRY', 'id': 'noBtn', 'funct': self.retryInput},
                                            {},
                                            {}
                                        )
                                        )
                             )
            
          
    def retryInput(self):
        self.popMsg()
        self.newValue()        
    def resetVectors(self):
        self.dataVector = np.array([])
    def getBtnValById(self, id):
        return next((x for x in self.infoBtns if x.id == id), None).getValue()

    def setLabelById(self, id, sensor, value):
        if (sensor == self.sensorType):
            next((x for x in self.infoBtns if x.id == id), None).setValue(value)

    def displayView(self):
        self.graph.display()
        for nl in self.nls:
            nl.display()
        for infoBtn in self.infoBtns:
            infoBtn.display()
        if self.focusNum == inTest:
            self.inPrRect.display()
            
    def startQuerying(self):
        self.querying = True
        self.app.streaming = True
        self.app.hd.startLive()
    def stopQuerying(self):
        self.querying = False
        self.app.streaming = False
        self.app.hd.stopStream()
            
#     def timeIn(self, year, month, day, hour, minute, second, millis):
#         super().timeIn(year, month, day, hour, minute, second, millis)
#         value = hour+':'+str(minute)+':'+str(second)+'.'+str(millis)+', '+ str(day)+'/'+str(month)+'/'+str(year)
#         self.setLabel('TIME', value)
#     
#     def locationIn(self, x, y):
#         super().locationIn(x, y)
#         self.setDLabel('LOCATION', x, y)
#     def noGPS(self):
#         super().noGPS()
#         self.setLabel('LOCATION', hd.NO_GPS)
    def temperatureIn(self, value):
        self.setLabelById(ADC, d.DS_TEMP, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_TEMP, value)
    def humidityIn(self, value):
        self.setLabelById(ADC, d.DS_HUM, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_HUM, value)
    def anglePotIn(self, value):
        self.setLabelById(ADC, d.DS_POT, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_POT, value)

    def angleImuIn(self, value):
        self.setLabelById(ADC, d.DS_IMU, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_IMU, value)

    def forceXIn(self, value):
        self.setLabelById(ADC, d.DS_LOAD_X, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_LOAD_X, value)

    def forceYIn(self, value):
        self.setLabelById(ADC, d.DS_LOAD_Y, value)
        if self.focusNum == inTest:
            self.add2Vec(d.DS_LOAD_Y, value)

#     def millisIn(self, value):
#         self.setLabel('ARD. TIME', value)
    def startSampling(self):
        realVal = self.getBtnValById(REAL)
        if type(realVal) != type(0.0):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Invalid real value.',
                                    'Add a valid real value',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            return
        self.resetVectors()
        self.focusNum = inTest
        self.app.updateScreen()
        notifThread = thr.Thread(target = self.notifyAfterDelay)
        notifThread.setName('DATA GATHER NOTIF THREAD')
        notifThread.daemon = True
        notifThread.start()
        
    def notifyAfterDelay(self):
        t.sleep(d.CALIB_AV_T)
        self.stopSampling()
        
        
    def stopSampling(self):
        self.focusNum = preTest
        self.app.updateScreen()
        self.addPoint2()
        
        
        
    def add2Vec(self, sensor, value):
        if (sensor == self.sensorType):
            try:
                floatVal = float(value)
                self.dataVector = np.append(self.dataVector, floatVal)
            except:
                pass
            
#     def fullStreamDataIn(self, anglePot, angleImu, forceValueX, forceValueY, timeValue):
#         super().fullStreamDataIn(anglePot, angleImu, forceValueX, forceValueY, timeValue) 
#         self.setLabel('X LOAD', forceValueX)
#         self.setLabel('Y LOAD', forceValueY)
#         self.setLabel('POT. ROTATION', anglePot)
#         self.setLabel('IMU. ROTATION', angleImu)

    def computeBestFit(self):
        result = np.polyfit(self.realVals, self.adcVals, deg = 1)
        a = result[0]
        b = result[1]
        self.setLabelById(A, self.sensorType, float(a))        
        self.setLabelById(B, self.sensorType, float(b))       
        
#     class SettingBtn:
#         def __init__(self, app,geoData, metaData, suffix = '', focus=False):
#             self.app = app
#             self.disp = self.app.disp
#             self.x = geoData['x']
#             self.y = geoData['y']
#             self.xdim = 16*d.px
#             self.ydim = 15*d.py
#             self.label = metaData['label']
#             self.funct = metaData['funct']
#             self.value = metaData['value']
#             self.suffix = suffix
#             self.id = metaData['id']
# 
#             self.setFocus(focus)
#             self.txtDim = int(2.4*d.px)
#             self.setBcgCol()
# 
#             self.setFontCol()
# 
#             self.setFont()
# 
#             self.setTxt()
#         def getValue(self):
#             return self.value
#         def setValue(self, value):
#             self.value = float(value)
#             self.setTxt()
#         def setFocus(self, focus):
#             self.focus = focus
#             self.setBcgCol()
# 
#         def setTxt(self):
#             self.txt = self.font.render(self.label + ': ' +(str("%.2f" % self.value) if type(self.value) == type(0.0) else str(self.value)) + self.suffix, True, self.fontCol)
#         def setFont(self):
#             self.font = pg.font.SysFont('Arial', self.txtDim,bold = True)
#         def setBcgCol(self):
#             self.bcgCol = d.textView_highlight_col if self.focus else self.app.textView_col
#         def setFontCol(self):
#             self.fontCol = self.app.font_col
# 
#         def display(self):
#             # display rect
#             pg.draw.rect(self.disp, self.bcgCol, (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim))
#             #display number
#             self.disp.blit(self.txt, (self.txt.get_rect(center=(self.x, self.y))))
