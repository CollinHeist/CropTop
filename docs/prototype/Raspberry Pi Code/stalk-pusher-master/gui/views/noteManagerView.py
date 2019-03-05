'''
noteManagerView.py created by Witold under the cropDevice project
'''
import pygame as pg
import defs as d
from views import view as v
from views import settingsView as sv
from items import noteList as nl
from views import keyboardView as kbv
class NoteManagerView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'NOTE MANAGER'
        self.btnDefs = [
            (
                {'label': 'NEW', 'id': 'toNewNoteBtn', 'funct': self.toNewNoteView},
                {'label': 'DELETE', 'id': 'removeNoteBtn', 'funct': self.deleteNote},
                {},
                {'label': 'BACK', 'id': 'bckBtn', 'funct': self.back}
            )
        ]
        super().__init__(app, prevView)
        self.currNotesX = self.cax
        self.currNotesY = self.cay
        self.startList()
    def setfocusNum(self, focus):
        if self.focusNum != focus:
            self.noteLists[self.focusNum].setFocus(False)
            self.focusNum = focus
            self.noteLists[self.focusNum].setFocus(True)
            self.initButArea()

    def startList(self):
        self.noteLists = []
        self.noteLists.append(nl.NoteList(self.app,self.disp,{'x':self.cax,'y':self.cay, 'xdim':30*d.px, 'ydim': 50*d.py}, listName='noteBank', hasFocus = (self.focusNum == len(self.noteLists))))
#         if self.noteLists[self.focusNum].isEmpty():
#             print('is empty')
#             self.setfocusNum(not self.focusNum)

    def toNewNoteView(self):
        self.app.setView(kbv.KeyboardView(self.app, self,
                                          d.WORD,
                                          'NEW NOTE',
                                          'newNote'
                                          ))
#         from views import newNoteView as nnv
#         self.app.setView(nnv.NewNoteView(self.app, self))
    def keyboardReturn(self, key, value, status = 1):
        if key == 'newNote':
#             noteBank = self.app.getSetting(d.NOTE_BANK)
#             noteBank.append(value)
#             self.app.saveSetting(d.NOTE_BANK, noteBank)
            self.noteLists[0].prependNote(value)
#             self.startList()
            
    def save(self):
        for nl in self.noteLists:
            nl.saveList()
    def back(self):
        self.save()
        self.goBack()
        # from views import notesSettingView as nsv
        # self.app.setView(nsv.NotesSettingView(self.app))
#     def addToCurr(self):
#         print('add note')
#         self.noteLists[not self.focusNum].addNote(self.noteLists[self.focusNum].removeNote())
#         if self.noteLists[self.focusNum].isEmpty():
#             print('is empty')
#             self.setfocusNum(not self.focusNum)

    def deleteNote(self):
        print('remove note')
        if self.noteLists[self.focusNum].isEmpty():
            print('is empty')
#             self.setfocusNum(not self.focusNum)
        else:
            self.noteLists[self.focusNum].removeNote()
            self.save()
            print('remove note')
            #save that fact
#             if self.noteLists[self.focusNum].isEmpty():
#                 print('is empty')
#                 self.setfocusNum(not self.focusNum)
    def display(self):
        super().display()
        for nl in self.noteLists:
            nl.display()
    def upArrowPress(self):
        self.noteLists[self.focusNum].upArrowPress()
    def downArrowPress(self):
        self.noteLists[self.focusNum].downArrowPress()
    def leftArrowPress(self):
        if self.focusNum == 0 or self.noteLists[not self.focusNum].isEmpty():
            return
        else:
            self.setfocusNum(not self.focusNum)
    def rightArrowPress(self):
        if self.focusNum == len(self.noteLists)-1 or self.noteLists[not self.focusNum].isEmpty():
            return
        else:
            self.setfocusNum(not self.focusNum)
#     def focusOn(self):
#         self.startList()
