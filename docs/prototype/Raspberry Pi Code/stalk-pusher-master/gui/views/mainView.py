'''
Created on Jan 30, 2017

Main menu view (welcome screen)

@author: Witold
'''

import pygame as pg
from views import view as v
from items import viewBtn as vb
import defs as d
import time as t
from utils import text as txt

class MainView(v.View):
    def __init__(self, app):

        self.btnDefs = [(
            {'label': 'SETTINGS', 'id': 'stgsBtn', 'funct': self.goToSettings},
            {'label': 'TESTING', 'id': 'tstBtn', 'funct': self.goToTesting},
            {'label': 'LIVE FEED', 'id': 'snfBtn', 'funct': self.goToLiveFeed},
            {'label': 'EXIT', 'id': 'bckBtn', 'funct': self.exitBtn})
            ]

        self.viewBtnDefs = (
            {'label': 'TEMPERATURE', 'funct': self.getTemperature},
            {'label': 'HUMIDITY', 'funct': self.getHumidity},
            {'label': 'LOCATION', 'funct': self.getLocation},
            {'label': 'TIME', 'funct': self.getTime}
        )

        self.title = 'MAIN MENU'

        super().__init__(app)

        self.caTtlfont = pg.font.SysFont('Arial', int(6*d.px), bold = True)
        self.caTtltxt = 'STALK STRENGTH\nDEVICE ' + self.app.getSetting(d.VERSION)#self.caTtlfont.render('STALK STRENGTH DEVICE ' + self.app.getSetting(d.VERSION), True, d.font_col_inv)

        self.numViewBtnRow = 2
        self.numViewBtnCom = 2
        self.setViewBtnsFocusNum(0)
        self.viewBtnsCols = (self.cax - 18*d.px, self.cax + 18*d.px)
        self.viewBtnsRows = (self.cay + 20*d.py, self.cay + 40*d.py)

        self.addViewBtns()
                
    def setViewBtnsFocusNum(self, num):
        self.viewBtnFocusNum = num
        
    def addViewBtns(self):
        self.viewBtns = []
        for i in range(len(self.viewBtnDefs)):
            row = self.viewBtnsRows[i // self.numViewBtnCom]
            col = self.viewBtnsCols[i % self.numViewBtnRow]
            
            self.viewBtns.append(vb.ViewBtn(app = self.app,
                                     pos = (col,row),
                                     dim = (32*d.px,18*d.py),
                                     label = self.viewBtnDefs[i]['label'],
                                     value = 'N/A',
                                     funct = self.viewBtnDefs[i]['funct'],
                                     focus = False,
                                     formating = lambda lab, val: lab+ ':\n' + str(val)#,
#                                      txtMode = 'mpte'
                                     )
                                 )
                                     
                                     
            
    def select(self):
        self.app.hd.getAll()

    def focusOn(self):
        super().focusOn()
        self.app.hd.getAll()
    def displayView(self):
        #display title for context area
        txt.mpue(disp = self.disp,
                 text = self.caTtltxt,
                 pos = (self.cax, self.cay - 5*d.py),
                 height = 25*d.py,
                 font = self.caTtlfont,
                 fontCol = d.invertColor(self.app.bcg_col)
                 )
#         self.disp.blit(self.caTtltxt, (self.caTtltxt.get_rect(center=(self.cax, self.cay))))
        for viewBtn in self.viewBtns:
            viewBtn.display()
        
    def goToLiveFeed(self):
        import views.testingView as tv
        print('view: go to live feed')
        self.app.setView(self.app.liveFeedView)
        self.app.liveFeedView.startQuerying()

    def goToTesting(self):
        import views.testingView as tv
        print('view: go to testing')
        self.app.setView(self.app.testingView)

    def goToSettings(self):
        import views.settingsView as sv
        print('going to settings')
        self.app.setView(self.app.settingsView)

#     def upArrowPress(self):
#         pass
# #         if (self.stnBtnFocusNum>=self.numStnBtnCom):
# #             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
# #             self.stnBtnFocusNum-=self.numStnBtnCom
# #             self.stnBtns[self.stnBtnFocusNum].setFocus(True)
# 
#     def downArrowPress(self):
#         pass
# #         if (self.stnBtnFocusNum<len(self.stnBtnDefs)-self.numStnBtnCom):
# #             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
# #             self.stnBtnFocusNum+=self.numStnBtnCom
# #             self.stnBtns[self.stnBtnFocusNum].setFocus(True)
# 
#     def leftArrowPress(self):
#         if (self.stnBtnFocusNum>0):
#             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
#             self.stnBtnFocusNum-=1
#             self.stnBtns[self.stnBtnFocusNum].setFocus(True)
# 
#     def rightArrowPress(self):
#         if (self.stnBtnFocusNum<len(self.stnBtnDefs)-1):
#             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
#             self.stnBtnFocusNum+=1
#             self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def timeIn(self, year, month, day, hour, minute, second, millis):
        super().timeIn(year, month, day, hour, minute, second, millis)
        value = hour+':'+str(minute)+', '+ str(day)+'/'+str(month)+'/'+str(year) #':'+str(second)+'.'+str(millis)+
        next((x for x in self.viewBtns if x.label == 'TIME'), None).setValue(value)
    def locationIn(self, x, y):
        super().locationIn(x, y)
        next((x for x in self.viewBtns if x.label == 'LOCATION'), None).setValue((x, y))
    def noGPS(self):
        super().noGPS()
        next((x for x in self.viewBtns if x.label == 'LOCATION'), None).setValue('No GPS')        
    def temperatureIn(self, value):
        super().temperatureIn(value)
        next((x for x in self.viewBtns if x.label == 'TEMPERATURE'), None).setValue(str(value))
    def humidityIn(self, value):
        super().humidityIn(value)
        next((x for x in self.viewBtns if x.label == 'HUMIDITY'), None).setValue(value)
#     def connectionEstablished(self):
#         print('main: established conn')
#         self.getAll()

#     class SettingBtn:
#         def __init__(self, app, geoData, metaData, focus):
#             self.app = app
#             self.disp = self.app.disp
#             self.x = geoData['x']
#             self.y = geoData['y']
#             self.xdim = 25*d.px
#             self.ydim = 18*d.py
#             self.label = metaData['label']
#             self.funct = metaData['funct']
#             self.value = 'N/A'
#             self.setFocus(focus)
#             self.txtDim = int(2.5*d.px)
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
#             self.setFont()
#             self.setTxt()
#         def setDValue(self, value1, value2):
#             self.value = str(value1)  +', ' + str(value2)
#             self.setFont()
#             self.setTxt()
#         def setFocus(self, focus):
#             self.focus = focus
#             self.setBcgCol()
#             self.app.updateScreen()
# 
#         def setTxt(self):
#             #self.setFont()
#             self.txt = self.font.render(self.label + ': ' +self.value, True, self.fontCol)
#             self.app.updateScreen()
#         def setFont(self):
#             self.font = pg.font.SysFont('Arial', self.txtDim)#self.txtDim
#         def setBcgCol(self):
# 
#             self.bcgCol = d.textView_highlight_col if self.focus else self.app.textView_col
#         def setFontCol(self):
# 
#             self.fontCol = self.app.font_col
# 
#         def display(self):
#             # display rect
#             pg.draw.rect(self.disp, self.bcgCol, (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim))
#             #display number
#             self.disp.blit(self.txt, (self.txt.get_rect(center=(self.x, self.y))))
    def exitBtn(self):
        
        if self.app.test is not None:
            if self.app.test.testing:
                return
        from items import message as ms
        self.pushMsg(ms.Message(self.app, self, self.disp,
                                'EXITING',
                                'Choose exit mode.',# You are about to exit. Just saying. So you will be exiting after you click yes so think about it very hard cause that might bring some unwanted consequences I think. One final word... this is very long.',
                                btnDefs = (
                                    {'label': 'CANCEL', 'id': 'cancelBtn', 'funct': self.popMsg},
                                    {'label': 'EXIT', 'id': 'exitBtn', 'funct': self.bringExitMsg},
                                    {'label': 'RESTART', 'id': 'restartBtn', 'funct': self.bringRestartMsg},
                                    {'label': 'SHUT\nDOWN', 'id': 'shutdownBtn', 'funct': self.bringShutdownMsg},
                                )
                                )
                     )
        