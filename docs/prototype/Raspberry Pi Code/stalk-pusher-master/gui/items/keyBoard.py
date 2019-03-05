'''
KeyBoards.py created by Witold under the cropDevice project
'''
import pygame as pg
import defs as d
from items import rectLabel as rl

class Keyboard:
    def __init__(self, app, geoData):
        self.app = app
        self.disp = self.app.disp
        self.x = geoData['x']
        self.y = geoData['y']
        self.xdim = geoData['xdim']
        self.ydim = geoData['ydim']
        self.focusNum = 0
        self.initKBData()
        self.initKeys()
    def initKBData(self):
        self.chars = (
        '1','2','3','4','5','6','7','8','9','0',
        'Q','W','E','R','T','Y','U','I','O','P',
         'A','S','D','F','G','H','J','K','L',';',
         'Z','X','C','V','B','N','M',',','.','?')
        self.rows = 4
        self.columns = 10        
        
    def initKeys(self):

        xInterval = self.xdim/self.columns
        yInterval = self.ydim/self.rows
        self.keys = []
        for i in range(len(self.chars)):
            x = self.x-self.xdim/2+xInterval*((i % self.columns) + 0.5)
            y = self.y-self.ydim/2+yInterval*(i // self.columns+0.5)
            self.keys.append(self.Key(
                self.chars[i],
                self.app,
                {'x':x,
                 'y':y,
                 'xdim':0.95*xInterval,
                 'ydim':0.95*yInterval}
            ))
        self.keys[self.focusNum].setFocus(True)

    def display(self):
        for key in self.keys:
            key.display()
    def upArrowPress(self):
        self.keys[self.focusNum].setFocus(False)
        self.focusNum = (self.focusNum - self.columns) % (self.columns * self.rows)
        self.keys[self.focusNum].setFocus(True)

    def downArrowPress(self):
        self.keys[self.focusNum].setFocus(False)
        self.focusNum = (self.focusNum + self.columns) % (self.columns * self.rows)
        self.keys[self.focusNum].setFocus(True)

    def leftArrowPress(self):
        self.keys[self.focusNum].setFocus(False)
#         self.focusNum = ((self.focusNum - 1) % (len(self.chars) - (self.columns * (self.focusNum // self.columns)))) % (self.columns) + (self.focusNum // self.columns) * self.columns
        self.focusNum = (self.focusNum - 1) % self.columns + (self.focusNum // self.columns) * self.columns
#         self.focusNum = ((self.focusNum - 1) % self.columns + (self.focusNum // self.columns) * self.columns) % len
        self.keys[self.focusNum].setFocus(True)

    def rightArrowPress(self):
        self.keys[self.focusNum].setFocus(False)
        self.focusNum = ((self.focusNum + 1) % len(self.chars)) % self.columns + (self.focusNum // self.columns) * self.columns
        self.keys[self.focusNum].setFocus(True)

#     def upArrowPress(self):
#         if (self.focusNum>=self.columns):
#             self.keys[self.focusNum].setFocus(False)
#             self.focusNum-=self.columns
#             self.keys[self.focusNum].setFocus(True)
# 
#     def downArrowPress(self):
#         if (self.focusNum<len(self.keys)-self.columns):
#             self.keys[self.focusNum].setFocus(False)
#             self.focusNum+=self.columns
#             self.keys[self.focusNum].setFocus(True)
# 
#     def leftArrowPress(self):
#         if (self.focusNum>0):
#             self.keys[self.focusNum].setFocus(False)
#             self.focusNum-=1
#             self.keys[self.focusNum].setFocus(True)
# 
#     def rightArrowPress(self):
#         if (self.focusNum<len(self.keys)-1):
#             self.keys[self.focusNum].setFocus(False)
#             self.focusNum+=1
#             self.keys[self.focusNum].setFocus(True)

    def getChar(self):
        return self.keys[self.focusNum].char
    class Key:
        def __init__(self, char, app, geoData):
            self.app = app
            self.disp = self.app.disp
            self.char = char
            self.x = geoData['x']
            self.y = geoData['y']
            self.xdim = geoData['xdim']
            self.ydim = geoData['ydim']
            self.rectLabel = rl.RectLabel(
                                app = self.app,
                                pos = (self.x, self.y),
                                dim = (self.xdim, self.ydim),
                                text = char,
                                font = self.app.kbKeyFont
                            )
            
#             self.rectLabel = rl.RectLabel(
#                 self.app,
#                 geoData,
#                 {'txt':char,
#                 'txtDim':3*d.px,
#                 'color': self.app.textView_col
#                  }
#             )
        def display(self):
            self.rectLabel.display()

        def setFocus(self, focus):
            self.focus = focus
            self.rectLabel.setBcgCol(d.textView_highlight_col if self.focus else self.app.textView_col)
            self.app.updateScreen()

