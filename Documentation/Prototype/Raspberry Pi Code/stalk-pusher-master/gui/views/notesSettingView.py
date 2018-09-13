'''
notesSettingView.py created by Witold on 2/2/2017 under the cropDevice project
'''
import random, string
import pygame as pg
import defs as d

import pygame as pg
import defs as d
from items import numChoice as nc
from views import view as v
from views import settingsView as sv
from items import noteList as nl
from items import message as msg
class NotesSettingView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'NOTE SETTING'
        self.btnDefs = [
            (
                {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
                {'label': 'REMOVE', 'id': 'removeNoteBtn', 'funct': self.removeNote},
                {},
                {'label': 'NOTE\nMANAGER', 'id': 'noteMngBtn', 'funct': self.toNoteManager}
            ),
            (
                {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
                {'label': 'REMOVE', 'id': 'removeNoteBtn', 'funct': self.removeNote},
                {},
                {'label': 'NOTE\nMANAGER', 'id': 'noteMngBtn', 'funct': self.toNoteManager}
            ),
            (
                {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
                {'label': 'ADD TO\nPRE-TEST', 'id': 'addToCurr', 'funct': self.addToPreTest},                
                {'label': 'ADD TO\nPOST-TEST', 'id': 'addToCurr', 'funct': self.addToPostTest},
                {'label': 'NOTE\nMANAGER', 'id': 'noteMngBtn', 'funct': self.toNoteManager}
            )
        ]
        super().__init__(app, prevView)
        self.currNotesX = self.cax
        self.currNotesY = self.cay

    def setfocusNum(self, focus):
#         if self.focusNum != focus:
        self.noteLists[self.focusNum].setFocus(False)
        self.focusNum = focus
        self.noteLists[self.focusNum].setFocus(True)
        self.initButArea()

    def startLists(self):
        self.noteLists = []
        self.noteLists.append(nl.NoteList(self.app, self.disp,{'x':self.cax-25*d.px,'y':self.cay, 'xdim':20*d.px, 'ydim': 50*d.py}, listName='preTestNotes', hasFocus=False, maxNotes = d.MAX_NOTES))# self.focusNum == len(self.noteLists)))        
        self.noteLists.append(nl.NoteList(self.app, self.disp,{'x':self.cax,'y':self.cay, 'xdim':20*d.px, 'ydim': 50*d.py}, listName='postTestNotes', hasFocus=False, maxNotes = d.MAX_NOTES))#self.focusNum == len(self.noteLists)))
        self.noteLists.append(nl.NoteList(self.app, self.disp,{'x':self.cax+25*d.px,'y':self.cay, 'xdim':20*d.px, 'ydim': 50*d.py}, listName='noteBank', hasFocus=False))# self.focusNum == len(self.noteLists)))
        self.automaticFocus('right')
    def toNoteManager(self):
        for nl in self.noteLists:
            nl.saveList()
        from views import noteManagerView as nmw
        self.app.setView(nmw.NoteManagerView(self.app, self))
    def save(self):
        for nl in self.noteLists:
            nl.saveList()
        self.goBack()
        # self.app.setView(sv.SettingsView(self.app))
    def cancel(self):
        self.goBack()
        # self.app.setView(sv.SettingsView(self.app))
   
    def moveNote(self, source, dest):
        if self.noteLists[source].isEmpty():
            self.pushMsg(msg.Message(self.app, self, self.disp,
                            'Cannot add note.',
                            'There is nothing to add.',
                            btnDefs = (
                                {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                {},
                                {},
                                {}
                            )
                            )
                 )
            return
        if self.noteLists[dest].isFull():    
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Cannot add note.',
                                    'You have reached the limit of ' + self.noteLists[source].listName + ' (5).',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
            return
        
        self.noteLists[dest].prependNote(self.noteLists[source].removeNote())
        if self.noteLists[self.focusNum].isEmpty():
            self.automaticFocus()

        
    def addToPreTest(self):
        print('add note to pre test')
        self.moveNote(2, 0)
#         if not self.noteLists[0].isFull():
#             self.noteLists[0].prependNote(self.noteLists[self.focusNum].removeNote())
#             if self.noteLists[self.focusNum].isEmpty():
#                 print('is empty')
#                 self.automaticFocus('left', self.focusNum-1)
#         else:
#             self.pushMsg(msg.Message(self.app, self, self.disp,
#                                     'Cannot add note.',
#                                     'You have reached the limit of pre-test nodes (5).',
#                                     btnDefs = (
#                                         {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
#                                         {},
#                                         {},
#                                         {}
#                                     )
#                                     )
#                          )

    def addToPostTest(self):
        print('add note to post test')
        self.moveNote(2, 1)

#         if not self.noteLists[1].isFull():
#             self.noteLists[1].prependNote(self.noteLists[self.focusNum].removeNote())
#             if self.noteLists[self.focusNum].isEmpty():
#                 print('is empty')
#                 self.automaticFocus('left', self.focusNum-1)
#         else:
#             self.pushMsg(msg.Message(self.app, self, self.disp,
#                                     'Cannot add note.',
#                                     'You have reached the limit of post-test nodes (5).',
#                                     btnDefs = (
#                                         {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
#                                         {},
#                                         {},
#                                         {}
#                                     )
#                                     )
#                          )
            

    def removeNote(self):
        print('remove note')
        self.moveNote(self.focusNum, 2)

#         if self.noteLists[self.focusNum].isEmpty():
#             print('is empty')
#             self.automaticFocus()
#         else:
#             self.noteLists[2].prependNote(self.noteLists[self.focusNum].removeNote())
#             if self.noteLists[self.focusNum].isEmpty():
#                 print('is empty')
#                 self.automaticFocus()

    def automaticFocus(self, direction = 'right', start = 0):
#         print('fovusnum', self.focusNum, 'direction', direction, 'start', start)

        if direction == 'right':
#             print('start with', start, 'ending with', len(self.noteLists)-1)

            for i in range(start, len(self.noteLists), 1):
#                 print(i, 'not empty')

                if not self.noteLists[i].isEmpty():
#                     print(i, 'setting this focus num')

                    self.setfocusNum(i)
                    break
                    
        elif direction == 'left':
#             print('start with', start, 'ending with', len(self.noteLists)+1)

            for i in range(start,-1,-1):
                if not self.noteLists[i].isEmpty():
                    self.setfocusNum(i)
                    break

    def displayView(self):
        for nl in self.noteLists:
            nl.display()
    def upArrowPress(self):
        self.noteLists[self.focusNum].upArrowPress()
    def downArrowPress(self):
        self.noteLists[self.focusNum].downArrowPress()
    def leftArrowPress(self):
        if self.focusNum == 0:
            return
        else:
            self.automaticFocus('left', self.focusNum-1)
    def rightArrowPress(self):
        if self.focusNum == len(self.noteLists)-1:
            return
        else:
            self.automaticFocus('right', self.focusNum+1)
    def focusOn(self):
        self.startLists()
