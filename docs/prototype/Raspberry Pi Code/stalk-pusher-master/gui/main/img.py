'''
img.py created by Witold under the cropDevice project
'''
import pygame as pg
import defs as d

def getLeftUp(img, centerx, centery):
    (xdim, ydim) = img.get_rect().size
    return(centerx - xdim/2, centery - ydim/2)

class IMG:
    def __init__(self, disp, name, geoData, color):
        self.disp = disp
        self.x = geoData['x']
        self.y = geoData['y']
        self.xdim = geoData['xdim']
        self.ydim = geoData['ydim']

    def setLoc(self, x, y):
        self.x = x
        self.y = y
    def setSize(self, xdim, ydim):
        self.xdim = xdim
        self.ydim = ydim
    def setColor(self, color):
        self.color = color
    def display(self):
        pass

    def getLeftUp(img, centerx, centery):
        (xdim, ydim) = img.get_rect().size
        return (centerx - xdim / 2, centery - ydim / 2)


