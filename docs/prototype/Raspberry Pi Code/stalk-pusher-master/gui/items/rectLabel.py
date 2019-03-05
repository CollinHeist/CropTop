'''
rectLabel.py created by Witold on 2/2/2017 under the cropDevice project
disp:display object
geoData {x,y,xdim,ydim}
txtData {label, txtDim, color}
'''
import pygame as pg
import defs as d
from utils import text as txt

class RectLabel:
    def __init__(self, app, pos, dim, text, font, fontCol = 0, bcgCol = 0, txtMode = 'mpte', scaleFactor = 1.0):
        self.app = app
        self.disp = self.app.disp
        self.x = pos[0]
        self.y = pos[1]
        self.xdim = dim[0]
        self.ydim = dim[1]

        self.text = str(text)
        
        self.font = font
        
        self.txtMode = txtMode
                
        if not fontCol:
            self.setFontCol(self.app.font_col)
        else:
            self.setFontCol(fontCol)  
            
        if not bcgCol:
            self.setBcgCol(self.app.textView_col)
        else:
            self.setBcgCol(bcgCol)  
                      
        self.bcgSurface = pg.Surface((self.xdim, self.ydim), pg.SRCALPHA)  # per-pixel alpha
                
        self.setHasBorder(False)
        
        self.scaleFactor = scaleFactor
    def setFontCol(self, fontCol):
        self.fontCol = fontCol
        self.app.updateScreen()
    def setBcgCol(self, bcgCol):
        self.bcgCol = bcgCol
        self.app.updateScreen()
                
    def setText(self, text):
        self.text = str(text)
        self.app.updateScreen()
    def setHasBorder(self, hasBorder):
        self.hasBorder = hasBorder
        self.app.updateScreen()
    def display(self):
        self.show(self.x, self.y)
        
    def displayWithY(self, y):
        self.show(self.x, y)
    
    def show(self, x, y):
        self.bcgSurface.fill(self.bcgCol)
        self.disp.blit(self.bcgSurface, (x - self.xdim / 2, y - self.ydim / 2, self.xdim, self.ydim))
                
        if self.hasBorder:
            pg.draw.rect(self.disp, [0, 0, 255], (x - self.xdim/2,y - self.ydim / 2,self.xdim,self.ydim), 5)
            
        if self.txtMode == 'spu':
            txt.spu(self.disp,
                    self.text,
                    (x, y),
                    self.font,
                    self.fontCol)
        elif self.txtMode == 'spt':
            txt.spt(self.disp,
                    self.text,
                    (x, y),
                    self.xdim * self.scaleFactor,
                    self.font,
                    self.fontCol)
        
        elif self.txtMode == 'mpue':
            txt.mpue(self.disp,
                    self.text,
                    (x, y),
                    self.ydim * self.scaleFactor,
                    self.font,
                    self.fontCol)

        elif self.txtMode == 'mpta':
            txt.mpta(self.disp,
                    self.text,
                    (x, y),
                    (self.xdim * self.scaleFactor, self.ydim * self.scaleFactor),
                    self.font,
                    self.fontCol)

        elif self.txtMode == 'mpte':
            txt.mpte(disp = self.disp,
                    text = self.text,
                    pos = (x, y),
                    dim = (self.xdim * self.scaleFactor, self.ydim * self.scaleFactor),
                    font = self.font,
                    fontCol = self.fontCol)
            
        