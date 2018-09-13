'''
Created on Jan 30, 2017

Button Area class. This is a container for the four buttons on the left. It receives input from the view
and triggers actions bound to each button. It may rearrange buttons, too.
@author: Witold
'''
from items import button as b
from main import defs as d


class ButArea:

    def __init__(self, app, btnDefs):
        self.app = app
        self.disp = self.app.disp
        self.btnDefs = btnDefs
        self.addBtns()
        
    def addBtns(self):
        self.btns = []
        for i in range(4):
            # try:
            if bool(self.btnDefs[i]):#not an empty dict
                self.btns.append(b.Button(self.app, self.btnDefs[i], d.btnAreaGeo[i]))
            else:
                self.btns.append(None)
            # except Exception as e:
            #     self.btns.append(None)
                # print ('Button appending error', str(e))
                
    def switchBtn(self, i, btnDef):
        if i > 3: return
        self.btns[i] = b.Button(self.app, btnDef, d.btnAreaGeo[i])
        self.app.updateScreen()
        
    def display(self):
        for btn in self.btns:
            try:
                btn.display()
            except:
                pass
    def removeUI(self):
        for btn in self.btns:
            btn.removeUI()
    def btnPressed(self,i):
        # try:
        if self.btns[i] != None:
            self.btns[i].action()
        # except:
           # print('Error executing action for button ', i+1)
