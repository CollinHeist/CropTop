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

class UpdateView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'UPDATE'
        self.btnDefs = [
                (
                    {},
                    {},
                    {},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                )
            ]
        super().__init__(app, prevView)
    
    def checkUSB(self):
        if os.path.exists(d.USB_DATA_PATH+d.UPDATE_DIR):
            self.updatePath = d.USB_DATA_PATH+d.UPDATE_DIR
        else:
            #either no USB stick or incorrect folder structure
            self.pushMsg()
        l = self.getAllFolders()      
        self.folderList.append(nl.NoteList(self.app, self.disp,{'x':self.cax-23*d.px,'y':self.cay, 'xdim':28*d.px, 'ydim': 50*d.py}, l,'Test folders', True))
        