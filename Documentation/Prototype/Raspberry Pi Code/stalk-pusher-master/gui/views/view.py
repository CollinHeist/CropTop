'''
Created on Jan 30, 2017

This is the superclass for each view. A view can be the Welcome screen, the Settings screen,
the Testing screen etc. The view has a 4-button area on the left and a Main Area on the right.
The 4-buutton area buttons and the Context Area are dependent on the View type. The View class has
8 input methods (btn1press, btn2press, upPress, etc.), which are triggered from the Main Window.
The View manages what happens when those inputs are registered. For buttons 1-4 press, it will delegate
the press to the 4-button area. For the rest, it will delegate it to the Main Area by default. The view has an init
in which it initializes the UI. It might have a remove UI function as well.

@author: Witold
'''

import pygame as pg
import defs as d
import items.butArea as ba
from hardware import hdInterface2 as hd
from utils import text as txt
from items import viewBtn as vb

class View(object):
    def __init__(self, app, prevView = None):

        #array containing identities of all buttons for the view and their data
        self.app = app
        self.disp = self.app.disp
        self.prevView = prevView
        self.cax = d.caGeo['x']
        self.cay = d.caGeo['y']
        self.caxdim = d.caGeo['xdim']
        self.caydim = d.caGeo['ydim']
        self.focusNum = 0

        self.initUI()

#         self.loadMsgFromStack()

        
    def loadMsgFromStack(self):
        for msg in self.app.msgStack:
            if msg == 'serialConnFail':
                self.serialConnFail()
            elif msg == 'some other msg':
                pass
            
        self.app.msgStack = []
    def serialConnFail(self):
        from items import message as ms
        self.pushMsg(ms.Message(self.app, self, self.disp,
                                'Serial connection failed',
                                'Please verify wiring and restart software.',
                                btnDefs = (
                                    {'label': 'OK', 'id': 'exitBtn', 'funct': self.popMsg},
                                    {'label': 'RETRY', 'id': 'restartBtn', 'funct': self.retrySerialConn},
                                    {'label': 'RESTART\nDEVICE', 'id': 'restartBtn', 'funct': self.bringRestartMsg},
                                    {}
                                )
                                )
                     )
    def initUI(self):
        self.cover = pg.Surface((100*d.px, 100*d.py), pg.SRCALPHA)  # per-pixel alpha
        self.cover.fill((0,0,0,200))

        self.messages = []
        self.initButArea()
    def initButArea(self):
        self.butArea = ba.ButArea(self.app, self.btnDefs[self.focusNum])
        self.app.updateScreen()
        
    def initButAreaByDefs(self, btnDefs):
        self.butArea = ba.ButArea(self.app, btnDefs)
        
    def addBtn(self, index, btnDef, focus = -1):
        if focus == -1 or self.focusNum == focus:
            self.butArea.switchBtn(index, btnDef)        
    def hasMsg(self):
        return len(self.messages)    
    def pushMsg(self, msg):
        self.messages.append(msg)
        self.app.updateScreen()

    def deleteMsgByIndex(self, index):
        if index == len(self.messages)-1:
            self.popMsg()
        else:
            del self.messages[index]
                    
    def getMsgIndexByTtl(self, msgTtl):
        for i in range(len(self.messages)):
            if msgTtl == self.messages[i].ttlTxt:
                return i
        return -1
    def popMsg(self):
        if len(self.messages)<1: return
        del self.messages[-1]
        if len(self.messages):
            self.messages[-1].initButArea()
        else:
            self.initButArea()
        self.app.updateScreen()

    def popAllMsg(self):
        if len(self.messages):
            del self.messages[:]
            self.initButArea()
        
    def keyboardReturn(self, key, value, status = 1):
        return value
    def display(self):
        
        txt.spt(disp = self.disp,
                text = self.title,
                pos = (self.cax, 5*d.py),
                width = self.caxdim,
                font = self.app.viewTtlFont,
                fontCol = d.invertColor(self.app.bcg_col)
                )
        
#         self.disp.blit(self.titleTxt, (self.titleTxt.get_rect(center=(self.cax, self.cay- 3*d.py-self.caydim/2+self.titleTxt.get_height()))))
        self.displayView()
        
        #display half transparent black cover
        if len(self.messages)>0: self.disp.blit(self.cover, (0, 0, 100*d.px, 100*d.py))

        for msg in self.messages:
            msg.display()
            
        self.butArea.display()
        
    def displayView(self):
        pass
#     def display(self):
#         self.butArea.display()
#         pg.draw.rect(self.disp, d.gray, (self.cax-self.caxdim/2, self.cay-self.caydim/2, self.caxdim, self.caydim))
#         self.disp.blit(self.titleTxt, (self.titleTxt.get_rect(center=(self.cax, self.cay- 3*d.py-self.caydim/2+self.titleTxt.get_height()))))
#         for msg in self.messages:
#             msg.display()
    
    #button callbacks
    def btn1Press(self):
        # try:
        self.butArea.btnPressed(0)
        # except:
        #     pass
    def btn2Press(self):
        # try:
        self.butArea.btnPressed(1)
        # except:
        #     pass
    def btn3Press(self):
        # try:
        self.butArea.btnPressed(2)
        # except:
        #     pass
    def btn4Press(self):
        # try:
        self.butArea.btnPressed(3)
        # except:
        #     pass
    def upArrowPress(self):
        pass
    def downArrowPress(self):
        pass
    def leftArrowPress(self):
        pass
    def rightArrowPress(self):
        pass

#     def convertedEnvData(self, dataType, dataTypeName):
#         (a, b) = self.getAB(dataType)
#         val = self.app.getEnvData(dataTypeName)
#         try:
#             val = float(val)
#         except:
#             val = 0.0
#         return (val-b)/a
    def convertedVector(self, vector, dataType):
        if vector == d.NUL_ARD_IN:
            return vector        
        (a, b) = self.getAB(dataType)
        try:
            retVal = (float(vector)-b)/a
            return retVal
        except Exception as e:
            print('invalid data in', vector, str(e))
            return vector
    def getAB(self, sensorType):
        sensorName = self.app.getSetting(d.SENSORS)[sensorType]
        sensorBank = self.app.getSetting(d.SENSOR_BANK)
        sensor = sensorBank[sensorType][sensorName]
        return(sensor[d.SENSOR_A], sensor[d.SENSOR_B])
    
    def getUnit(self, sensorType):
        sensorName = self.app.getSetting(d.SENSORS)[sensorType]
        sensorBank = self.app.getSetting(d.SENSOR_BANK)
        sensor = sensorBank[sensorType][sensorName]
        return sensor[d.SENSOR_UNIT]
    
    def getABUnit(self, sensorType):
        sensorName = self.app.getSetting(d.SENSORS)[sensorType]
        sensorBank = self.app.getSetting(d.SENSOR_BANK)
        sensor = sensorBank[sensorType][sensorName]
        return(sensor[d.SENSOR_A], sensor[d.SENSOR_B], sensor[d.SENSOR_UNIT])
    
    #sensorCallbacks
    def timeIn(self, year, month, day, hour, minute, second, millis):
        self.app.saveEnvData(d.TIME, year + d.TIME_DEL + month + d.TIME_DEL + day + d.TIME_DEL + hour + d.TIME_DEL + minute + d.TIME_DEL + second)
    def locationIn(self, x, y):
        self.app.saveEnvData(d.LOCATION, str(x) + '|' + str(y))
    def noGPS(self):
        self.app.saveEnvData(d.LOCATION, hd.NO_GPS)
    def temperatureIn(self, value):
        try:
            value = self.convertedVector(float(value), d.DS_TEMP)
            self.app.saveEnvData(d.TEMPERATURE, value)
        except Exception as e:
            print('invalid temp data in', value, str(e))
    def humidityIn(self, value):
        try:
            value = self.convertedVector(float(value), d.DS_HUM)
            self.app.saveEnvData(d.HUMIDITY, value)
        except Exception as e:
            print('invalid hum data in', value, str(e))
    def anglePotIn(self, value):
        pass
    def angleImuIn(self, value):
        pass
    def forceXIn(self, value):
        pass
    def forceYIn(self, value):
        pass
    def millisIn(self, value):
        pass
    def fullStreamDataIn(self, anglePot, angleImu, forceValueX, forceValueY, timeValue):
        #print(angleValue, forceValueX, forceValueY, timeValue)
        if not self.app.streaming:
            print('not streaming')
            self.app.hd.stopStream()

    #commands to get data
    def getHumidity(self):
        self.app.hd.getHumidity()
    def getTemperature(self):
        self.app.hd.getTemperature()
    def getLocation(self):
        self.app.hd.getLocation()
    def getTime(self):
        self.app.hd.getTime()
    def getAll(self):
        self.app.hd.getAll()
    def connectionEstablished(self):
        pass
    def focusOn(self):
        print('focus on')
#         self.popAllMsg()
        self.app.updateScreen()
    def focusOut(self):
#         self.popAllMsg()
        print('focus out')
        
    def focusOnWithArg(self):
        print('focus on with arg')
    def goBack(self):
        self.app.setView(self.prevView)
#     def goBackWithArg(self, arg):
#         self.app.setViewWithArg(self.prevView, arg)
    def okBtnAction(self):
        pass
    def bringRestartMsg(self):
        from items import message as ms
        self.pushMsg(ms.Message(self.app, self, self.disp,
                                'RESTARTING DEVICE...',
                                'ARE YOU SURE?',
                                btnDefs = (
                                    {'label': 'YES', 'id': 'yesBtn', 'funct': self.app.restartPi},
                                    {'label': 'NO', 'id': 'noBtn', 'funct': self.popMsg},
                                    {},
                                    {}
                                )
                                )
                     )
        
    def bringShutdownMsg(self):
        from items import message as ms
        self.pushMsg(ms.Message(self.app, self, self.disp,
                                'SHUTTING DOWN DEVICE...',
                                'ARE YOU SURE?',
                                btnDefs = (
                                    {'label': 'NO', 'id': 'noBtn', 'funct': self.popMsg},
                                    {},
                                    {},
                                    {'label': 'YES', 'id': 'yesBtn', 'funct': self.app.shutdownPi}
                                )
                                )
                     )
    def bringExitMsg(self):
        from items import message as ms
        self.pushMsg(ms.Message(self.app, self, self.disp,
                                'EXITING SOFTWARE',
                                'ARE YOU SURE?',
                                btnDefs = (
                                    {'label': 'YES', 'id': 'yesBtn', 'funct': self.app.exit},
                                    {'label': 'NO', 'id': 'noBtn', 'funct': self.popMsg},
                                    {},
                                    {}
                                )
                                )
                     )
        
    def retrySerialConn(self):
        self.popMsg()
        self.app.hd.initConnThread()
