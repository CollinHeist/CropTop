'''
settingsView.py created by Witold on 2/1/2017 under the pygametrial project
'''
import pygame as pg
import defs as d
from views import view as v
from utils import text as t
from items import viewBtn as vb
from items import rectLabel as rl
class ColorTestView(v.View):
    def __init__(self, app, prevView = None):
        self.btnDefs = [(
            {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
            {},#'label': 'SELECT', 'id': 'selectBtn', 'funct': self.select
            {},
            {'label': 'BACK', 'id': 'bckBtn', 'funct': self.back}
        )]
        self.title = 'COLOR TESTING'
        super().__init__(app, prevView)

        self.stnBtnDefs = (
            {'label': 'R_BCG', 'id': 'R_BCG', 'funct': None},
            {'label': 'G_BCG', 'id': 'G_BCG', 'funct': None},
            {'label': 'B_BCG', 'id': 'B_BCG', 'funct': None},
            {'label': 'R_BOX', 'id': 'R_BOX', 'funct': None},
            {'label': 'G_BOX', 'id': 'G_BOX', 'funct': None},
            {'label': 'B_BOX', 'id': 'B_BOX', 'funct': None},
            {'label': 'R_FONT', 'id': 'R_FONT', 'funct': None},
            {'label': 'G_FONT', 'id': 'G_FONT', 'funct': None},
            {'label': 'B_FONT', 'id': 'B_FONT', 'funct': None}
        )
        self.origBcgCol = self.app.bcg_col
#         self.colors = [[0]*3 for i in range(3)]
        self.colors = [list(self.app.bcg_col), list(self.app.textView_col), list(self.app.font_col)]
        
        self.rL = rl.RectLabel(app = self.app,
                               pos = (84*d.px, 35*d.py),
                               dim = (23*d.px, 20*d.py),
                               text = 'Testing',
                               font = self.app.msgTtlFont
                               )
#         self.rL = rl.RectLabel(self.app,
#                              {'x': 80*d.px, 'y': 35*d.py, 'xdim':25*d.px, 'ydim': 20*d.py},
#                              {'txt': 'Testing', 'txtDim': 6*d.px, 'color': self.app.textView_col})
        self.rL2 = rl.RectLabel(app = self.app,
                               pos = (84*d.px, 65*d.py),
                               dim = (20*d.px, 15*d.py),
                               text = 'T',
                               font = self.app.stnBtnFont
                               )
        
#         self.rL2 = rl.RectLabel(self.app,
#                              {'x': 80*d.px, 'y': 65*d.py, 'xdim':20*d.px, 'ydim': 15*d.py},
#                              {'txt': 'T', 'txtDim': 6*d.px, 'color': self.app.textView_col})
        
        self.numStnBtnRow = 3
        self.numStnBtnCom = 3
        self.setStnFocusNum(0)
        self.stnBtnsCols = (self.cax - 30*d.px, self.cax-15*d.px, self.cax)
        self.stnBtnsRows = (self.cay - 18*d.py, self.cay, self.cay + 18*d.py)
        self.addStnBtns()
#         self.font = pg.font.SysFont('Arial', int(4*d.px))
#         self.focusSet = False
    def setStnFocusNum(self, num):
        self.stnBtnFocusNum = num

    def addStnBtns(self):
        self.stnBtns = []
        for i in range(len(self.stnBtnDefs)):
            row = self.stnBtnsRows[i // 3]
            col = self.stnBtnsCols[i % 3]
            stnBtn = vb.ViewBtn(app=self.app,
                                pos= (col,row),
                                dim = (13*d.px, 10*d.px),
                                label = self.stnBtnDefs[i]['label'],
                                id = self.stnBtnDefs[i]['id'],
                                value = self.colors[i // 3][i % 3]/255.0,
                                focus = i == self.stnBtnFocusNum,
                                formating = lambda lab, val: lab[2:] + '\n' + lab[0] + ': ' + str("%0.1f" % val)
                                )

#             stnBtn = self.SettingBtn(self.app, {'x': col, 'y': row}, self.stnBtnDefs[i],i == self.stnBtnFocusNum)
#             stnBtn.setValue(self.colors[i // 3][i % 3]/255.0)
            self.stnBtns.append(stnBtn)
    def displayView(self):
#         pg.draw.rect(self.disp, (self.bcgCol), (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim))

#         t.fontS(3*d.px)
#         t.text('BCG:', (self.cax-26*d.px, self.stnBtnsRows[0]-5*d.py), self.disp)
#  
#         t.text('BOX:', (self.cax-26*d.px, self.stnBtnsRows[1]-5*d.py), self.disp)
#  
#         t.text('FONT:', (self.cax-26*d.px, self.stnBtnsRows[2]-5*d.py), self.disp)

        
#         self.disp.blit(self.font.render('Hello World!', True, (255, 0, 0), (255, 255, 255)), (5*d.px, 10*d.py))
#         self.disp.blit('R:', (5*d.px, 10*d.py))
#         self.disp.blit('G:', (5*d.px, 10*d.py))
#         self.disp.blit('B:', (5*d.px, 10*d.py))
        
        for stnBtn in self.stnBtns:
            stnBtn.display()
            
        self.rL.display()  
        self.rL2.display()  

    def select(self):
        pass
#         self.focusSet = not self.focusSet
#         self.stnBtns[self.stnBtnFocusNum].funct()
    def toHeightSetting(self):
        from views import heightSettingView as hv
        print('go to height setting')
        self.app.setView(hv.HeightView(self.app, self))

    def toPlotSetting(self):
        from views import plotSettingView as psv
        print('go to plot setting')
        self.app.setView(psv.PlotSettingView(self.app, self))

    def toNoteSetting(self):
        from views import notesSettingView as nsv
        print('go to note setting')
        self.app.setView(nsv.NotesSettingView(self.app, self))
    def toPendingSetting(self):
        pass
    def back(self):
        self.app.bcg_col = self.origBcgCol
        self.goBack()
    def save(self):
        
        
        colorData = self.app.getSetting(d.COLORS)
                
        colorData['bcg_col'] = self.colors[0]
        colorData['textView_col'] = self.colors[1]
        colorData['font_col'] = self.colors[2]
        
        self.app.saveSetting(d.COLORS, colorData)
                
        
        
        self.app.readSettings()
        
        self.app.createViews()
        self.app.setView(self.app.settingsView)        
#         self.goBack()
        
    def updateCols(self):
        x = self.stnBtnFocusNum // self.numStnBtnRow
        y = self.stnBtnFocusNum % self.numStnBtnCom
        self.colors[x][y] = int(self.stnBtns[self.stnBtnFocusNum].value *255)
        if x == 0:
#             print(self.colors[0])
            self.app.bcg_col = self.colors[0]
#             d.bcg_col = self.colors[0]
        elif x == 1:
            self.rL.setBcgCol(self.colors[x])
            self.rL2.setBcgCol(self.colors[x])
        elif x == 2:
            self.rL.setFontCol(self.colors[x])
            self.rL2.setFontCol(self.colors[x])


    def upArrowPress(self):
#         if self.focusSet:
        stnBtn = self.stnBtns[self.stnBtnFocusNum]
        stnBtn.setValue((round(stnBtn.value+0.1,1))%1.1)
        self.updateCols()
#         elif (self.stnBtnFocusNum>=self.numStnBtnCom):
#             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
#             self.stnBtnFocusNum-=self.numStnBtnCom
#             self.stnBtns[self.stnBtnFocusNum].setFocus(True)
            
    def downArrowPress(self):
#         if self.focusSet:
        stnBtn = self.stnBtns[self.stnBtnFocusNum]
        stnBtn.setValue((round(stnBtn.value-0.1,1))%1.1)
        self.updateCols()
           
#         elif (self.stnBtnFocusNum<len(self.stnBtnDefs)-self.numStnBtnCom):
#             self.stnBtns[self.stnBtnFocusNum].setFocus(False)
#             self.stnBtnFocusNum+=self.numStnBtnCom
#             self.stnBtns[self.stnBtnFocusNum].setFocus(True)

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
    
    def setLabel(self, id, value):
         next((x for x in self.stnBtns if x.id == id), None).setValue(value)

#     class SettingBtn:
#         def __init__(self, app,geoData, metaData, focus):
#             self.app = app
#             self.disp = self.app.disp
#             self.x = geoData['x']
#             self.y = geoData['y']
#             self.xdim = 5*d.px
#             self.ydim = 5*d.py
#             self.label = metaData['label']
#             self.id = metaData['id']
#             self.funct = metaData['funct']
#             self.value = 50
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
#             self.value = value
#             self.setTxt()
#         def setDValue(self, value1, value2):
#             self.value = str(value) + str(value2)
#             self.setTxt()
# 
#         def setFocus(self, focus):
#             self.focus = focus
# #             self.setBcgCol()
# 
#         def setTxt(self):
#             self.txt = self.font.render(str("%0.1f" % self.value), True, self.fontCol)
#             
# #             self.txt = self.font.render(self.label + ': ' +str(self.value), True, self.fontCol)
#         def setFont(self):
#             self.font = pg.font.SysFont('Arial', self.txtDim, bold = True)
#         def setBcgCol(self):
#             if self.label == 'R':
#                 self.bcgCol = d.red
#             elif self.label == 'G':
#                  self.bcgCol = d.green
#             elif self.label == 'B':
#                  self.bcgCol = d.blue
#             else:
#                 self.bcgCol = d.textView_highlight_col if self.focus else d.textView_col
#         def setFontCol(self):
#             self.fontCol = self.app.font_col
# 
#         def display(self):
#             # display rect
#             pg.draw.rect(self.disp, self.bcgCol, (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim))
#             if self.focus:
#                 pg.draw.rect(self.disp, (0,255,255), (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim), int(0.5*d.px))
#                 
#             #display number
#             self.disp.blit(self.txt, (self.txt.get_rect(center=(self.x, self.y))))
