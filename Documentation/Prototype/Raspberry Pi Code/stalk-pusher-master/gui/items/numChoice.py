'''
numChoice.py created by Witold on 2/1/2017 under the cropDevice project
assume it knows the geography. It needs:
@dict:
    @string value: which value are we changing?
    @string units: what unit doe this value have?
@int numDigits: how many digits does this value have?


'''
import pygame as pg
import defs as d
from main import img
from items import rectLabel as rl

#static variables
arrowUpimg = pg.image.load(d.APP_PATH +'/assets/img/arrowUpImg.png')
arrowUpimg = pg.transform.scale(arrowUpimg, (int(5*d.px), int(5*d.px)))
# zero out RGB values
arrowUpimg.fill((0, 0, 0, 255), None, pg.BLEND_RGBA_MULT)
# add in new RGB values
arrowUpimg.fill(d.arrow_col + (0,), None, pg.BLEND_RGBA_ADD)

arrowDownImg = pg.image.load(d.APP_PATH +'/assets/img/arrowDownImg.png')
arrowDownImg = pg.transform.scale(arrowDownImg, (int(5*d.px), int(5*d.px)))

# zero out RGB values
arrowDownImg.fill((0, 0, 0, 255), None, pg.BLEND_RGBA_MULT)
# add in new RGB values
arrowDownImg.fill(d.arrow_col + (0,), None, pg.BLEND_RGBA_ADD)

class NumChoice:
    def __init__(self, app, disp, valueData, geoData):
        self.app = app
        self.disp = disp
        self.x = geoData['x']
        self.y = geoData['y']
        self.valueName = valueData['value']
        self.valueUnit = valueData['unit']
        self.numDigits = valueData['numDigits']
        self.unitPos = valueData['unitPos']

        self.addBtns()

    def addBtns(self):
        self.focusNum = 0
        self.btns = []
        self.value = self.app.getSetting(self.valueName)
        val = self.value
        for i in range(self.numDigits):
            exp = self.numDigits-i -1
            divider = 10**exp
            quot = val // divider
            val -= quot * divider
            xPos = self.x - 14*d.px + i*10*d.px
            self.btns.append(self.NumBtn(self.app, quot, {'x':xPos,'y': self.y, 'xdim': 8*d.px, 'ydim': 8*d.px}, i==self.focusNum))
        if self.unitPos == 'suffix':
            xPos = self.x - 14*d.px + len(self.btns)*10*d.px
        elif self.unitPos == 'prefix':
            xPos = self.x - 14*d.px - 10*d.px

        self.unitLabel = rl.RectLabel(app = self.app,
                                      pos = (xPos, self.y),
                                      dim = ( 8 * d.px, 8 * d.px),
                                      text = self.valueUnit,
                                      font = self.app.numKeyFont
                                      )

#         self.unitLabel = rl.RectLabel(
#             self.app,
#             {'x': xPos, 'y': self.y, 'xdim': 8 * d.px, 'ydim': 8 * d.px},
#             {'txt':self.valueUnit,'txtDim':4*d.px, 'color': self.app.textView_col})

    def display(self):
        for btn in self.btns:
            btn.display()
        self.unitLabel.display()
    def getValue(self):
        value = 0
        for i in range(len(self.btns)):
            value += self.btns[i].value * 10**(self.numDigits-1-i)
        return value
    def saveValue(self):
        d.saveSetting(self.valueName, self.value)
    def upArrowPress(self):
        self.btns[self.focusNum].changeValue(1)
        self.value = self.getValue()

    def downArrowPress(self):
        self.btns[self.focusNum].changeValue(-1)
        self.value = self.getValue()
    def leftArrowPress(self):
        if self.focusNum == 0:
            return
        self.btns[self.focusNum].setFocus(False)
        self.focusNum -=1
        self.btns[self.focusNum].setFocus(True)
    def rightArrowPress(self):
        if self.focusNum == self.numDigits-1:
            return
        self.btns[self.focusNum].setFocus(False)
        self.focusNum +=1
        self.btns[self.focusNum].setFocus(True)
    def saveValue(self):
        self.app.saveSetting(self.valueName, self.value)
    class NumBtn:
        def __init__(self, app, value, butGeo, focus):
            self.app = app
            self.disp = self.app.disp
            self.value = value
            self.focus = focus
            color = d.textView_highlight_col if self.focus else self.app.textView_col
            
            self.rectLabel = rl.RectLabel(app = self.app,
                                          pos = (butGeo['x'], butGeo['y']),
                                          dim = (butGeo['xdim'], butGeo['ydim']),
                                          text = value,
                                          font = self.app.numKeyFont,
                                          bcgCol = color
                                          )

        def setFocus(self, focus):
            self.focus  = focus
            # self.setBcgCol()
            if self.focus:
                self.rectLabel.setBcgCol(d.textView_highlight_col)
            else:
                self.rectLabel.setBcgCol((self.app.textView_col))
        def display(self):
            self.rectLabel.display()
            if (self.focus):
                self.disp.blit(arrowUpimg, img.getLeftUp(arrowUpimg, self.rectLabel.x, self.rectLabel.y-self.rectLabel.ydim))
                self.disp.blit(arrowDownImg, img.getLeftUp(arrowDownImg, self.rectLabel.x, self.rectLabel.y+self.rectLabel.ydim))


        def changeValue(self, change):
            self.value += change
            if self.value == 10:
                self.value = 0
            elif self.value == -1:
                self.value = 9
            self.rectLabel.setText(self.value)
            
