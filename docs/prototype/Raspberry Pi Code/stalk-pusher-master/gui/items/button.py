import pygame as pg
import defs as d
from utils import text as txt
class Button:
    def __init__(self, app, bluePrint, geoData):
        # x, y, width, height, label, name, function
        self.app = app
        self.disp = self.app.disp
        self.x = geoData['x']
        self.y = geoData['y']
        self.xdim = geoData['xdim']
        self.ydim = geoData['ydim']
        self.id = bluePrint['id']
        self.funct = bluePrint['funct']
        self.label = bluePrint['label']
        
        self.setBcgCol()
                
        #TEXT RENDERING%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#         self.labelRows = self.label.splitlines()
#         self.txtRows = []
#         numRows = len(self.labelRows)
#         for i in range(len(self.labelRows)):
#             self.txtRows.append([self.font.render(self.labelRows[i], True, self.fontCol), self.y - self.ydim/2 + (i+1)*self.ydim/(numRows+1)])
        #TEXT RENDERING%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    def setBcgCol(self):
            self.bcgCol = self.app.textView_col

    def display(self):
        pg.draw.rect(self.disp, self.bcgCol, (self.x-self.xdim/2, self.y-self.ydim/2, self.xdim, self.ydim))
        
        txt.mpue(disp = self.disp,
                 text = self.label,
                 pos = (self.x, self.y),
                 height = self.ydim,
                 font = self.app.btnFont,
                 fontCol = self.app.font_col
                 )
        #TEXT RENDERING%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%               
#         for txtRow in self.txtRows:
#             self.disp.blit(txtRow[0], (txtRow[0].get_rect(center=(self.x, txtRow[1]))))
        #TEXT RENDERING%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            
#         self.disp.blit(self.txt, (self.txt.get_rect(center=(self.x, self.y))))

    def action(self):
        if callable(self.funct):
            self.funct()
        elif type(self.funct == type(tuple)):
            for fun in self.funct:
                if callable(fun):
                    fun()
