'''
graph.py created by Witold on 2/5/2017 under the cropDevice project
'''
import pygame as pg
import defs as d
import numpy as np
import matplotlib as mpl
mpl.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.backends.backend_agg as agg
import matplotlib.ticker as ticker

import pylab as pl
import time as t
class Graph:
    def __init__(self, disp, geoData, xlabel = '', ylabel = '', graphNum =1):
        self.disp = disp
        self.x = geoData['x']
        self.y = geoData['y']
        self.xdim = geoData['xdim']
        self.ydim = geoData['ydim']
        self.initMPL(graphNum)
        self.updImgInt = 0.1 #in seconds 
        self.resetUpdateTime()
    def resetPlot(self):
        #self.initMPL()
        self.clear()
#         pass
    def initMPL(self, graphNum):
        self.fig = plt.figure(
            figsize=(self.xdim* d.pxIn, self.ydim* d.pyIn),
            dpi = d.dpi,
            tight_layout = {'pad': 0.2},
            facecolor = 'w'#'d.convertColor(d.graphBcg_col)
        )
 
        self.ax = self.fig.add_subplot(111)
#         self.ax.set_facecolor(d.convertColor(d.graphBcg_col))
        self.canvas = agg.FigureCanvasAgg(self.fig)
        self.clear()
    def setXLabel(self, label):
        plt.xlabel(label)       
#         pass 
    def resetUpdateTime(self):
        self.lastUpdT = t.time()
#         pass
    def clear(self):
#         plt.close('all')
        self.ax.clear()
        self.canvas.draw()
        renderer = self.canvas.get_renderer()
        raw_data = renderer.tostring_rgb()
        size = self.canvas.get_width_height()
        self.plotImgSurf =  pg.image.fromstring(raw_data, size, "RGB")

    def updatePlot(
            self,
            x = np.array([]),
            y1 = np.array([]),
            y2 = np.array([]),
            xlabel = 'xlabel',
            ylabel ='ylabel',
            highlights = np.array([]),
            annotations = [],
            a = None,
            b = None
        ):

#         plt.close('all')
#         self.clear()
        
        self.ax.clear()
        self.canvas.draw()

        self.ax.xaxis.set_major_formatter(ticker.FormatStrFormatter('%.1f'))
        self.ax.yaxis.set_major_formatter(ticker.FormatStrFormatter('%.1f'))
        
        self.ax.xaxis.set_major_locator(ticker.MaxNLocator(4))
        self.ax.yaxis.set_major_locator(ticker.MaxNLocator(5))
        
        
#         print('x', len(x))
#         print('y1', len(y1))
#         print('y2', len(y2))

        self.ax.plot(x, y1,
            'o',
            markersize=int(0.8*d.px),
            markerfacecolor = 'black',
            markeredgecolor = 'black'
        )
        if y2.size != 0:
            self.ax.plot(x, y2,
                'o',
                markersize=int(0.8*d.px),
                markerfacecolor = 'blue',
                markeredgecolor = 'blue'
            )        
        else:
            if highlights.size > 0:
                self.ax.plot(x[highlights], y1[highlights],
                    's',
                    markersize=int(1.5*d.px),
                    markerfacecolor = 'None',
                    markeredgecolor = 'red',
                    markeredgewidth='2.5'
                )      
            
        for annotation in annotations:
            plt.annotate(
                annotation['text'],
                xy=(annotation['ptx'], annotation['pty']), xycoords = 'data',
                xytext=(annotation['xpos'],annotation['ypos']), textcoords = 'axes fraction',
                ha=annotation['ha'], va=annotation['va'],
                bbox=dict(boxstyle='round, pad=0.2', fc=annotation['bcg_col'], alpha=0.6),
                arrowprops=dict(arrowstyle = '->', connectionstyle='arc3,rad=0.5')
                )
        
        if a is not None and b is not None:
            line = a*x+b
            self.ax.plot(
                x,
                line,
                linewidth = 3
            )

        
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        
#         plt.tight_layout()       
            
        self.canvas.draw()
        renderer = self.canvas.get_renderer()
        raw_data = renderer.tostring_rgb()
        size = self.canvas.get_width_height()
        self.plotImgSurf =  pg.image.fromstring(raw_data, size, "RGB")

    def close(self):
        plt.clf()
    def display(self, x, y):
        if (t.time() - self.lastUpdT >= self.updImgInt):
            try:
                self.updatePlotImg(x, y)
            except Exception as e:
                print(str(e))
            self.resetUpdateTime()
        self.disp.blit(self.plotImgSurf, (self.x-(self.xdim*d.px)/2, self.y-(self.ydim*d.py)/2))
#         pass
    def display(self):
        self.disp.blit(self.plotImgSurf, (self.x-(self.xdim*d.px)/2, self.y-(self.ydim*d.py)/2))
#         pass
    def upArrowPress(self):
        pass
    def downArrowPress(self):
        pass
    def leftArrowPress(self):
        pass
    def rightArrowPress(self):
        pass
