import os
import pygame as pg
import numpy as np
# import pandas as pd
import time as t
import csv
from random import randint as ri
import defs as d
from hardware import hdInterface2 as hd
from views import view as v
from items import graph as g
from items import noteList as nl
from items import rectLabel as rl
from utils import text as txt
from utils import postProcess as pp
from items import viewBtn as vb

def cmp(a, b):
    return not (a > b) - (a < b) 

class TestFileView(v.View):
    def __init__(self, app, path, graph, prevView = None):
        splitPath = path.split('/')
        self.title = splitPath[-2] + '/' + splitPath[-1][:-4]#dont want to have .csv in title
        self.btnDefs = [
                (
                    {'label':'SELECT', 'id':'selectBtn', 'funct':self.selectBtn},
                    {},
                    {},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                )
            ]
        self.filePath = path
#         print('VIEWED FILE PATH', self.filePath)

        super().__init__(app, prevView)
#         self.mode = preTest
        self.numBtnX = self.cax
        self.numBtnY = self.cay
        self.readVectors()
        self.drawPots = False
        self.drawXY = False
        
        self.graph = graph
#         self.startGraph()
        self.redrawGraph()
        self.initLayout()
    def setPostItemFocusNum(self, num):
        self.postItemFocusNum = num
        
    def setPostItemFocus(self, num):
        self.postItems[self.postItemFocusNum].setFocus(False)
        self.postItemFocusNum = num
        self.postItems[self.postItemFocusNum].setFocus(True)            

    def initLayout(self):
        self.setPostItemFocusNum(0)
#         self.postStnBtnDefs = (
#             {'label': 'Load', 'value': 'F','funct': self.switchLoadMode},
#             {'label': 'Rotation', 'value': 'IMU','funct': self.switchRotMode}
#         )
        self.postItems = []
        
        #self.postItems.append(nl.NoteList(self.app, self.disp,{'x':self.cax-28*d.px,'y':self.cay, 'xdim':20*d.px, 'ydim': 25*d.py}, listName = 'postTestNotes', hasFocus = True))
        
        self.postItems.append(vb.ViewBtn(app = self.app,
                                    pos = (self.cax-4*d.px, self.cay + 42 * d.py),
                                    dim = (22 * d.px, 12*d.py),
                                    label = 'Load',
                                    value = 'F',
                                    funct = self.switchLoadMode,
                                    focus = True,
                                    formating = lambda lab, val: lab+ ': ' + str(val)
                                    )
                          )

        self.postItems.append(vb.ViewBtn(app = self.app,
                                    pos = (self.cax+22*d.px, self.cay + 42 * d.py),
                                    dim = (22 * d.px, 12*d.py),
                                    label = 'Rot.',
                                    value = 'IMU',
                                    funct = self.switchRotMode,
                                    focus = False,
                                    formating = lambda lab, val: lab+ ': ' + str(val)
                                    )
                          )
#         self.postItems.append(self.SettingBtn(self.app, {'x': self.cax-10*d.px, 'y': self.cay + 40 * d.py},
#                                           self.postStnBtnDefs[0], True,  (15 * d.px, 10*d.py)))
#         self.postItems.append(self.SettingBtn(self.app, {'x': self.cax+10*d.px, 'y': self.cay + 40 * d.py},
#                                   self.postStnBtnDefs[1], False, (15 * d.px, 10*d.py)))

    def goBack(self):
#         self.graph.close()
        super().goBack()
    def readVectors(self):
        
        csv_file = open(self.filePath, 'r')
        
        self.testData = np.array([])
        self.times = np.array([])
        self.loadsX = np.array([])
        self.loadsY = np.array([])
        self.loads = np.array([])
        self.anglePots = np.array([])
        self.angleImus = np.array([])
        
        temp = csv_file.read().splitlines()
        readIn = False
        for line in temp:
            if not readIn:
                headers = line.split(',')
                if len(headers)>0 and cmp(headers, d.testHeaders):
                    readIn = True
                    continue
            else:
                [time, angle_pot, angle_imu, load_x, load_y] = line.split(',')
                self.times = np.append(self.times, float(time))
                self.loadsX = np.append(self.loadsX, float(load_x))
                self.loadsY = np.append(self.loadsY, float(load_y))
                self.anglePots = np.append(self.anglePots, float(angle_pot))
                self.angleImus = np.append(self.angleImus, float(angle_imu))

        self.loads = np.sqrt(self.loadsX**2 + self.loadsY**2)
           
    def selectBtn(self):
        self.postItems[self.postItemFocusNum].funct()
       
    def redrawGraph(self, highlights = np.array([]), annotations = []):
                        
        with self.app.hd.threadLock:
            if not len(self.times):
                self.graph.clear()
                return
            if self.drawPots:
                angleUnit = ' (POT.)'# + '[' + ((self.getABUnit(d.DS_POT))[-1])+']'
                angles = self.anglePots                            
            else:
                angleUnit = ' (IMU)'# + '[' + ((self.getABUnit(d.DS_IMU))[-1])+']'
                angles = self.angleImus                            
            if self.drawXY:
                loadUnit = ' XY'# 'X: ' + ((self.getABUnit(d.DS_LOAD_X))[-1]) + ', Y: ' + ((self.getABUnit(d.DS_LOAD_Y))[-1])
                loads1 = self.loadsX
                loads2 = self.loadsY
                highlights = np.array([])
                
            else:
                loadUnit = ' F'#'F: ' + ((self.getABUnit(d.DS_LOAD_X))[-1])
                loads1 = self.loads                                  
                loads2 = np.array([])
                                                             
            annotations = []
            if angles[0] > self.app.getSetting(d.MAX_START_ANGLE):
                annotations.append({'text':'SA '+ str("%0.1f" % angles[0])+ '>' + str(self.app.getSetting(d.MAX_START_ANGLE)),
                                    'index': 0,
                                    'ptx': angles[0],
                                    'pty': loads1[0],
                                    'xpos':1,
                                    'ypos': 0,
                                    'ha': 'right',
                                    'va': 'bottom',
                                    'bcg_col': 'red'})
            
#             (trueMaxInd, highlights) = pp.checkValidity(self.loads)
#             if trueMaxInd != -1:
#                 annotations.append({'text':'ML (' + str("%0.1f" % loads1[trueMaxInd]) + ')',
#                     'index': trueMaxInd,
#                     'ptx': angles[trueMaxInd],
#                     'pty': loads1[trueMaxInd],                  
#                     'xpos': 0,
#                     'ypos': 1,
#                     'ha': 'left',
#                     'va': 'top',
#                     'bcg_col': 'green'})
# 
#             if self.drawXY:
#                 
#                 (trueMaxInd, hls) = pp.checkValidity(loads2)
#                                 
#                 if trueMaxInd != -1:
#                     annotations.append({'text':'MLY (' + str("%0.1f" % loads2[trueMaxInd]) + ')',
#                         'index': trueMaxInd,
#                         'ptx': angles[trueMaxInd],
#                         'pty': loads2[trueMaxInd],                     
#                         'xpos': 1,
#                         'ypos': 1,
#                         'ha': 'right',
#                         'va': 'top',
#                         'bcg_col': 'gray'})
                    
            self.graph.updatePlot(
                x = angles,
                y1 = loads1,
                y2 = loads2,
                xlabel = 'ROT.' + angleUnit,
                ylabel = 'LOAD' + loadUnit,
                highlights = highlights,
                annotations = annotations                                              
            )
    def switchLoadMode(self):
        self.drawXY = not self.drawXY
        self.postItems[-2].setValue('XY'if self.drawXY else 'F')
        self.redrawGraph()
    def switchRotMode(self):
        self.drawPots = not self.drawPots
        self.postItems[-1].setValue('Pot.'if self.drawPots else 'IMU')
        self.redrawGraph()

    def startGraph(self):
        self.graph = g.Graph(self.disp, {'x':self.cax, 'y':self.cay-3*d.py, 'xdim': 60, 'ydim':72})

    def displayView(self):
        self.graph.display()
        for item in self.postItems:
            item.display()
    def upArrowPress(self):
        self.postItems[self.postItemFocusNum].upArrowPress()
    def downArrowPress(self):
            self.postItems[self.postItemFocusNum].downArrowPress()
    def leftArrowPress(self):
        self.setPostItemFocus((self.postItemFocusNum-1)%len(self.postItems))

    def rightArrowPress(self):
            self.setPostItemFocus((self.postItemFocusNum+1)%len(self.postItems))
        
#     class SettingBtn:
#         def __init__(self, app,geoData, metaData, focus, dim = (25*d.px, 18*d.py)):
#             self.app = app
#             self.disp = self.app.disp
#             self.x = geoData['x']
#             self.y = geoData['y']
#             self.xdim = dim[0]
#             self.ydim = dim[1]
#             self.label = metaData['label']
#             self.value = metaData['value']
#             self.funct = metaData['funct']
#             self.setFocus(focus)
#             self.txtDim = txt.findFontSize(self.label+ ': ' + str(self.value), 'Arial', self.xdim, self.ydim)
# 
#             self.setFontCol()
# 
#             self.setFont()
# 
#             self.setTxt()
#         def setValue(self, value):
#             self.value = value
#         def setFocus(self, focus):
#             self.focus = focus
#             self.setBcgCol()
# 
#         def setTxt(self):
#             self.txt = self.font.render(self.label+ ': ' + str(self.value) + ('mm' if self.label == 'Height' else ''), True, self.fontCol)
#         def setFont(self):
#             self.font = pg.font.SysFont('Arial', self.txtDim, bold = True)
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
#         def upArrowPress(self):
#             pass
#         def downArrowPress(self):
#             pass

