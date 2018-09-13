"""
This is a general purpose keyboard view to input values
I need:
1. which view to go back to
2. a key with which to identify the return string
3. Type -> word or number?
4. Title
"""
from views import view as v
import pygame as pg
import defs as d
from items import rectLabel as rl
from items import message as msg

class KeyboardView(v.View):
    def __init__(self, app, prevView = None, type = d.NUM, dataName = 'Data', retKey = '', input ='', maxlen = 20, suffix = ''):
        self.title = 'INPUT: ' + dataName
        self.btnDefs = [
            (
                {'label': 'OK', 'id': 'saveBtn', 'funct': self.save},
                {'label': 'SELECT', 'id': 'selectBtn', 'funct': self.addChar},
                {'label': 'BACK\nSPACE', 'id': 'bckSpaceBtn', 'funct': self.backSpace},
                {'label': 'CANCEL', 'id': 'bckBtn', 'funct': self.back}
            )
        ]
        super().__init__(app, prevView)
        self.type = type
        self.retKey = retKey
        
        self.maxlen = maxlen

        self.currNotesX = self.cax
        self.currNotesY = self.cay
        self.input = str(input)
        self.suffix = suffix
        self.inputRect = rl.RectLabel(app = self.app,
                                  pos = (self.cax, self.cay - 24*d.py),
                                  dim = (58*d.px, 8*d.py),
                                  text = self.input + ' ' + self.suffix,
                                  font = self.app.nlFont,
                                  )
        self.initKeyBoard(type)
    def initKeyBoard(self, type):
        if type == d.NUM:
            from items import keyBoardNum as kbn
            self.keyBoard = kbn.KeyboardNum(
                self.app,
                {'x':self.cax,
                 'y':self.cay+20*d.py,
                 'xdim':72*d.px,
                 'ydim':56*d.py
                 }
            )
        elif type == d.WORD:
            from items import keyBoard as kb
            self.keyBoard = kb.Keyboard(
                self.app,
                {'x':self.cax,
                 'y':self.cay+20*d.py,
                 'xdim':72*d.px,
                 'ydim':56*d.py
                 }
            )
        elif type == d.ALPHA:
            from items import keyboardAlpha as kba
            self.keyBoard = kba.KeyboardAlpha(
                self.app,
                {'x':self.cax,
                 'y':self.cay+20*d.py,
                 'xdim':72*d.px,
                 'ydim':56*d.py
                 }
            )

            
    def displayView(self):
        self.keyBoard.display()
        self.inputRect.display()
    def save(self):
        if len(self.input)>0:
            self.goBack()           
            self.prevView.keyboardReturn(self.retKey, self.input)
        else:
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Cannot accept empty input',
                                    'Please enter input or cancel',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            
    def addChar(self):
        if len(self.input)<self.maxlen:
            self.input += self.keyBoard.getChar()
            self.inputRect.setText(self.input + ' ' + self.suffix)
        else:
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Input too long',
                                    'Reached maximum length for this input: ' + str(self.maxlen),
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            
    def backSpace(self):
        if len(self.input)>0:
            self.input = self.input[:-1]
            self.inputRect.setText(self.input)


    def back(self):
        self.goBack()
    def upArrowPress(self):
        self.keyBoard.upArrowPress()
        self.app.updateScreen()
    def downArrowPress(self):
        self.keyBoard.downArrowPress()
    def leftArrowPress(self):
        self.keyBoard.leftArrowPress()
    def rightArrowPress(self):
        self.keyBoard.rightArrowPress()