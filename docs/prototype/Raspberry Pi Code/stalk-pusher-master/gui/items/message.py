import pygame as pg
import defs as d
from items import rectLabel as rl
from utils import text as txt
ttlProp = 0.2 #proportion of y space taken by title rect
class Message:
    def __init__(self, app, view, disp, ttlTxt, msgTxt,
                  geoData = {'x':62.5*d.px, 'y': 50*d.py, 'xdim': 70*d.px, 'ydim': 50*d.py},
                  btnDefs = None,
                  ttlData = None,
                  bdData = None
                  ):
        
        self.app = app
        self.disp = disp
        self.view = view
        
        self.ttlTxt = ttlTxt
        self.msgTxt = msgTxt
        
        self.btnDefs = btnDefs
        
        self.x = geoData['x']
        self.y = geoData['y']
        self.xdim = geoData['xdim']
        self.ydim = geoData['ydim']
        
        
        self.bcg = pg.Surface((self.xdim, self.ydim), pg.SRCALPHA)  # per-pixel alpha

        self.bcg.fill(self.app.textView_col)
        
        ttlYdim = ttlProp * self.ydim
        ttlY = self.y - (self.ydim - ttlYdim)/2
        
        bdDim= self.ydim - ttlYdim
        bdY = self.y + (self.ydim-bdDim)/2
        
        
        
        if bdData is not None:
            bdFont = bdData['font']
        else:
            bdFont = self.app.msgBdFont
        
        
        self.ttlRect = rl.RectLabel(app=self.app,
                                    pos = (self.x, ttlY),
                                    dim = (70*d.px, ttlYdim),
                                    text = self.ttlTxt,
                                    font = self.app.msgTtlFont,
#                                     fontCol = d.font_col_inv,
                                    bcgCol = d.brightenColor(self.app.textView_col)
                                    )
        
#         self.ttl = rl.RectLabel(self.app,
#                                 {'x':self.x, 'y': self.y - self.ydim/2 + 5*d.py, 'xdim': 70*d.px, 'ydim': 10*d.py},
#                                 {'txt':self.ttlTxt,'txtDim':4*d.px,'color':d.brightenColor(self.app.textView_col)})
        
        self.msgRect = rl.RectLabel(app=self.app,
                                    pos = (self.x, bdY),
                                    dim = (70*d.px, bdDim),
                                    text = self.msgTxt,
                                    font = bdFont,
#                                     fontCol = d.font_col_inv,
#                                     bcgCol = d.brightenColor(self.app.textView_col)
                                    txtMode = 'mpta',
                                    scaleFactor = 0.85
                                    )

#         self.msg = rl.RectLabel(self.app,
#                                 {'x':self.x, 'y': self.y, 'xdim': 70*d.px, 'ydim': 10*d.py},
#                                 {'txt':self.msgTxt,'txtDim':2.5*d.px,'color':self.app.textView_col})
        
        
#         self.font = pg.font.SysFont('Arial', int(4*d.px))
        self.initButArea()
    def initButArea(self):
        self.view.initButAreaByDefs(self.btnDefs)
          
    def display(self):
#         #display message background rect
#         self.disp.blit(self.bcg, (self.x - self.xdim / 2, self.y - self.ydim / 2, self.xdim, self.ydim))
#         #display title
#         self.ttl.display()
#         #display message
#         w = 0.9*self.xdim
#         left = self.x-w/2
#         
#         boxH = (self.ydim - self.ttl.ydim)
#         h = 0.9*(boxH)
#         top = self.y-self.ydim/2 + self.ttl.ydim + (boxH-h)/2
# #         txt.multilineText(self.disp, self.msgTxt, (left, top),(w, h), self.font, self.app.font_col)
#         txt.multilineText2(self.disp, self.msgTxt, (left, top),(w, h), self.font, self.app.font_col)
# #         self.msg.display()
        self.ttlRect.display()
        self.msgRect.display()
        