'''
Created on Jan 30, 2017

Main menu view (welcome screen)

@author: Witold
'''

import pygame as pg
import views.view as v
import defs as d
import time as t
from hardware import hdInterface2 as hd
from items import viewBtn as vb
UPDATE_INTERVAL = 0.1#seconds

class LiveFeedView(v.View):
    def __init__(self, app, prevView = None):
        self.btnDefs = [(
                {'label': 'STOP/\nSTART', 'id': 'bckbtn', 'funct': self.uPause},
                {'label': 'ADC', 'id': 'bckbtn', 'funct': self.toADC},
                {},#'label': 'Except', 'id': 'bckbtn', 'funct': self.throwExc},#'label': 'Except', 'id': 'bckbtn', 'funct': self.throwExc
                {'label': 'BACK', 'id': 'bckbtn', 'funct': self.back},
            ),
            (
                {'label': 'STOP/\nSTART', 'id': 'bckbtn', 'funct': self.uPause},
                {'label': 'UNITS', 'id': 'bckbtn', 'funct': self.toReal},
                {},
                {'label': 'BACK', 'id': 'bckbtn', 'funct': self.back}
            )
            ]
        
        self.stnBtnDefs = (
            {'label': 'TEMP.', 'funct': None},
            {'label': 'HUMIDITY', 'funct': None},
            {'label': 'LOCATION', 'funct': None},
            {'label': 'TIME', 'funct': None},
            {'label': 'X LOAD', 'funct': None},
            {'label': 'Y LOAD', 'funct': None},
            {'label': 'POT. ANGLE', 'funct': None},
            {'label': 'IMU ANGLE', 'funct': None},
            {'label': 'CPU TIME', 'funct': None}

        )
        self.title = 'LIVE FEED'
        super().__init__(app, prevView)

        self.numStnBtnRow = 3
        self.numStnBtnCom = 3
        self.setStnFocusNum(0)
        self.stnBtnsCols = (self.cax - 25*d.px, self.cax, self.cax + 25*d.px)
        self.stnBtnsRows = (self.cay - 24*d.py, self.cay+2*d.py, self.cay + 28*d.py)
        self.addStnBtns()
        
        self.querying = False
        self.lastQueryT = 0
        
    def throwExc(self):
        raise Exception('sample')
    def toADC(self):
        self.focusNum = 1
        self.initButArea()
    def toReal(self):
        self.focusNum = 0
        self.initButArea()
    def uPause(self):
        if self.querying:
             self.stopQuerying()
        else:
            self.startQuerying()
    def startQuerying(self):
        self.querying = True
        self.app.streaming = True
        self.app.hd.startLive()
    def stopQuerying(self):
        self.querying = False
        self.app.streaming = False
        self.app.hd.stopStream()
       
    def setStnFocusNum(self, num):
        self.stnBtnFocusNum = num
    
    def addStnBtns(self):
        self.stnBtns = []
        for i in range(len(self.stnBtnDefs)):
            row = self.stnBtnsRows[i // self.numStnBtnCom]
            col = self.stnBtnsCols[i % self.numStnBtnRow]
            
            self.stnBtns.append(vb.ViewBtn(app = self.app,
                                           pos = (col, row),
                                           dim = (24*d.px, 24*d.py),
                                           label = self.stnBtnDefs[i]['label'],
                                           value = 'N/A',
                                           font = self.app.lvVbFONT,
                                           formating = lambda lab, val: lab+ ':\n' + str(val),
                                           txtMode = 'mpte'
                                           )
                                )
            
#             self.stnBtns.append(self.SettingBtn(self.app, {'x': col, 'y': row}, self.stnBtnDefs[i],i == self.stnBtnFocusNum))
            
            
#         for stnBtn in self.stnBtns:
#             stnBtn.display()
    def back(self):
        self.stopQuerying()
        from views import mainView as mv
        self.app.setView(self.prevView)
    
    def displayView(self):
        #display title for context area
#         if self.querying and t.time() - self.lastQueryT > UPDATE_INTERVAL:
#              self.lastQueryT = t.time()
             #self.app.hd.getAll()
            
        for stnBtn in self.stnBtns:
            stnBtn.display()
        


    def upArrowPress(self):
        if (self.stnBtnFocusNum>=self.numStnBtnCom):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum-=self.numStnBtnCom
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def downArrowPress(self):
        if (self.stnBtnFocusNum<len(self.stnBtnDefs)-self.numStnBtnCom):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum+=self.numStnBtnCom
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def leftArrowPress(self):
        if (self.stnBtnFocusNum>0):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum-=1
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def rightArrowPress(self):
        if (self.stnBtnFocusNum<len(self.stnBtnDefs)-1):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum+=1
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)
    
    def convertedEnvData(self, dataType, dataTypeName):
        (a, b) = self.getAB(dataType)
        val = self.app.getEnvData(dataTypeName)
        try:
            val = float(val)
        except:
            val = 0.0
        return (val-b)/a
    
    #overriden    
    def convertedVector(self, vector, dataType):
        #vector is actually always a string
        if vector == d.NUL_ARD_IN:
            return vector
        (a, b, unit) = self.getABUnit(dataType)
        try:
            retVal = (float(vector)-b)/a
            retVal = str("%0.2f" % retVal) + unit            
            return retVal
        except Exception as e:
            print('invalid temp data in', vector, str(e))
            return str(vector)
        
    def setLabel(self, label, value):
        if type(value) == type(0.0):
            value = str("%0.2f" % value)
        next((x for x in self.stnBtns if x.label == label), None).setValue(value)
         
#     def setDLabel(self, label, value1, value2):
#          next((x for x in self.stnBtns if x.label == label), None).setDValue(value1, value2)
   
    def timeIn(self, year, month, day, hour, minute, second, millis):
        super().timeIn(year, month, day, hour, minute, second, millis)
        value = hour.zfill(2)+':'+minute.zfill(2) +' ' + day.zfill(2)+'/'+month.zfill(2)
        self.setLabel('TIME', value)
    
    def locationIn(self, x, y):
        super().locationIn(x, y)
        self.setLabel('LOCATION', (x, y))
    def noGPS(self):
        super().noGPS()
        self.setLabel('LOCATION', hd.NO_GPS)
        
        
    def temperatureIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_TEMP)
        self.setLabel('TEMP.', value)
    def humidityIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_HUM)
        self.setLabel('HUMIDITY', value)
    
    
    def anglePotIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_POT)
        self.setLabel('POT. ANGLE', value)
    def angleImuIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_IMU)
        self.setLabel('IMU ANGLE', value)
    def forceXIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_LOAD_X)
        self.setLabel('X LOAD', value)
    def forceYIn(self, value):
        if not self.focusNum:
            value = self.convertedVector(value, d.DS_LOAD_Y)
        self.setLabel('Y LOAD', value)
    def millisIn(self, value):
        self.setLabel('CPU TIME', value)


#     class SettingBtn:
#         def __init__(self, app,geoData, metaData, focus):
#             self.app = app
#             self.disp = self.app.disp
#             self.x = geoData['x']
#             self.y = geoData['y']
#             self.xdim = 23*d.px
#             self.ydim = 18*d.py
#             self.label = metaData['label']
#             self.funct = metaData['funct']
#             self.value = 'N/A'
#             self.setFocus(focus)
#             self.txtDim = int(2.4*d.px)
#             self.setBcgCol()
# 
#             self.setFontCol()
# 
#             self.setFont()
# 
#             self.setTxt()
# 
#         def setValue(self, value):
#             self.value = str(value)
#             self.setTxt()
#         def setDValue(self, value1, value2):
#             self.value = str(value1) +', ' + str(value2)
#             self.setTxt()
# 
#         def setFocus(self, focus):
#             self.focus = focus
#             self.setBcgCol()
# 
#         def setTxt(self):
#             self.txt = self.font.render(self.label + ': ' +self.value, True, self.fontCol)
#             self.app.updateScreen()
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
        
