from items import noteList as nl
import os
from views import view as v
from main import defs as d
from items import message as msg
from utils import misc as m
import threading as thr

class PastTestsView(v.View):
    def __init__(self, app, graph, prevView = None):
        self.mode = 'Device'
        self.setViewTitle()
        self.btnDefs = [
                (
                    {'label': 'EXPORT\nTO USB', 'id': 'bckBtn', 'funct': self.bringExportMsg},#'label': 'SELECT', 'id': 'startBtn', 'funct': self.selectFolder
                    {'label': 'REMOVE\nALL', 'id': 'bckBtn', 'funct': self.bringRemoveMsg},
                    {'label': 'DEVICE\n/USB', 'id': 'startBtn', 'funct': self.switchMode},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                ),
                (
                    {'label': 'EXPORT\nTO USB', 'id': 'bckBtn', 'funct': self.bringExportMsg},
                    {'label': 'VIEW', 'id': 'startBtn', 'funct': self.selectFile},
                    {'label': 'DEVICE\n/USB', 'id': 'startBtn', 'funct': self.switchMode},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                )
            ]

        super().__init__(app, prevView)
        self.numBtnX = self.cax
        self.numBtnY = self.cay

        self.makeLists()
        
        self.graph = graph
#         self.focus = 0
#         self.folderList[self.focus].setFocus(True)
    def setViewTitle(self):
        self.title = self.mode + ' Test Files'

    def switchMode(self):
        if self.mode == 'Device':
            self.mode = 'USB'
        else:
            self.mode = 'Device'
        self.setViewTitle()
        self.makeLists()
        self.initButArea()
              
    def makeLists(self):
        with self.app.threadLock:
            self.focusNum = 0
            self.folderList = []
            
            if self.mode == 'Device':
                self.testsPath = os.path.join(d.RASPI_DATA_PATH, d.TESTS_DIR)
                l = self.getAllFolders()      
    
            elif self.mode == 'USB':
                self.testsPath = os.path.join(d.USB_DATA_PATH,d.TESTS_DIR)            
                if os.path.ismount(d.USB_DATA_PATH):
                    l = self.getAllFolders()
                else:
                    l = []
                    
            self.folderList.append(nl.NoteList(self.app, self.disp,{'x':self.cax-23*d.px,'y':self.cay+8*d.py, 'xdim':28*d.px, 'ydim': 66*d.py}, l,'Test folders', True))
            
            if len(l):
                l = [fullName[0:-4] for fullName in self.getAllFiles(self.folderList[0].getItem())]
                folderName = self.folderList[0].getItem()
            else:
                folderName = ''    
            self.folderList.append(nl.NoteList(self.app, self.disp,{'x':self.cax+14*d.px,'y':self.cay+8*d.py, 'xdim':44*d.px, 'ydim': 66*d.py}, l, folderName + ' Test files', False))
    def bringRemoveMsg(self):
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'REMOVING ALL ' + self.mode +' FILES',
                                    'You are about to permanently remove all files on ' + self.mode + \
                                    '. Ensure that all files are safely stored as copies. Data removed cannot be retrieved.',
                                    btnDefs = (
                                        {'label': 'PROCEED', 'id': 'yesBtn', 'funct': (self.popMsg, self.bringRemoveMsg2)},
                                        {'label': 'CANCEL', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {}
                                    )
                                    )
                         )
    def bringRemoveMsg2(self):
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'ARE YOU SURE?',
                                    'All files on ' + self.mode + \
                                    ' will be permanently deleted.',
                                    btnDefs = (
                                        {'label': 'CANCEL', 'id': 'yesBtn', 'funct': self.popAllMsg},
                                        {},
                                        {'label': 'REMOVE\nALL', 'id': 'yesBtn', 'funct': (self.popAllMsg, self.startRemoveAll)},                                                                                
                                        {}
                                    )
                                    )
                         )
        
    def startRemoveAll(self):
        delPath = self.testsPath
#         if not os.path.isdir(delPath):
#             delPath = os.path.dirname(delpath)
        if not os.path.isdir(delPath):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Cannot proceed',
                                        'Either there are no test files to delete or the directory structure is invalid.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                        )
                             )
            return
        if self.mode == 'USB' and not os.path.ismount(d.USB_DATA_PATH):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Cannot proceed',
                                        'USB is not mounted. Check USB connection first.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                        )
                             )
            return
            
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'REMOVING...',
                                    'Please wait while files are being removed.',
                                    btnDefs = (
                                        {},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
        delThread = thr.Thread(target = self.removeAll)
        delThread.setName('REMOVE THREAD')
        delThread.daemon = True
        delThread.start()
    def removeAll(self):
        delPath = self.testsPath
        if not os.path.isdir(delPath):
            delPath = os.path.dirname(delpath)
        m.osCommand('rm -rf ' + delPath)
        self.popAllMsg()
        self.makeLists()
        self.initButArea()
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                   'REMOVE COMPLETE',
                                   'Please verify validity of remove operation.',
                                   btnDefs = (
                                       {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                       {},
                                       {},
                                       {}
                                   )
                                   )
                        )
    def bringExportMsg(self):
        if not (os.path.isdir(d.RASPI_DATA_PATH) and os.path.isdir(os.path.join(d.RASPI_DATA_PATH, d.TESTS_DIR))):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'No test folders.',
                                        'Nothing to export. Perform tests or check that test files are correctly saved to device under'\
                                        ' ' + os.path.join(d.RASPI_DATA_PATH,d.TESTS_DIR) + '.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                    )
                        )                    
            return
        
        if not os.path.ismount(d.USB_DATA_PATH):
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'NO USB',
                                        'Cannot detect USB. Check that USB stick is correctly plugged in and retry.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {'label': 'RETRY', 'id': 'yesBtn', 'funct': (self.popMsg, self.bringExportMsg)},
                                            {},
                                            {}
                                        )
                                    )
                        )                    
            return
            
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Exporting to USB.',
                                    'You are about to export all test files stored on device to USB stick. All duplicate data will be overwritten.',                                    btnDefs = (
                                        {'label': 'PROCEED', 'id': 'yesBtn', 'funct': (self.popMsg, self.startExport)},
                                        {'label': 'CANCEL', 'id': 'yesBtn', 'funct': self.popMsg},
                                        {},
                                        {}
                                    )
                                )
                    )
    def startExport(self):
        if not (os.path.isdir(d.RASPI_DATA_PATH) and os.path.isdir(os.path.join(d.RASPI_DATA_PATH, d.TESTS_DIR)) and
                os.path.isdir(d.USB_DATA_PATH) and os.path.ismount(d.USB_DATA_PATH)): #final check
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Export failed.',
                                        'Export failed. Check the existence of SD and USB folders and USB connection.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                    )
                        )
            return                 

        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'EXPORTING...',
                                    'Please wait while files are being exported.',
                                    btnDefs = (
                                        {},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
        exportThread = thr.Thread(target = self.exportFiles)
        exportThread.setName('EXPORT THREAD')
        exportThread.daemon = True
        exportThread.start()
                      
    def exportFiles(self):
#         m.osCommand('sudo chmod ' + d.RW_PERM_A + ' '  + d.USB_DATA_PATH)
        m.osCommand('rsync -a -u ' + os.path.join(d.RASPI_DATA_PATH, d.TESTS_DIR) + ' ' + d.USB_DATA_PATH)
        self.popMsg()

        self.makeLists()
        self.initButArea()
        
        
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                   'EXPORT COMPLETE',
                                   'You can remove USB stick and verify the export outcome.',
                                   btnDefs = (
                                       {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                       {},
                                       {},
                                       {}
                                   )
                                   )
                        )
            
    def replaceList(self, l, folder):
        if folder is not None:
            self.folderList[1] = (nl.NoteList(self.app, self.disp,{'x':self.cax+14*d.px,'y':self.cay+8*d.py, 'xdim':44*d.px, 'ydim': 66*d.py}, l, folder + ' Test files', False))

    '''
    following is from:
    https://stackoverflow.com/a/4500607/3000014
    '''
    def sorted_ls(self, path):
        mtime = lambda f: os.stat(os.path.join(path, f)).st_mtime
        return list(sorted(os.listdir(path), key=mtime, reverse = True))
        
    def getDirectSubDirs(self,dirPath):
        try:
            return [name for name in os.listdir(dirPath) if os.path.isdir(os.path.join(dirPath, name))]
        except:
            return []
    def getMostRecent(self):
        pass
    def getAllFolders(self):
        try:
            return self.sorted_ls(self.testsPath)
#             return self.getDirectSubDirs(self.testsPath)    
        except:
            return []
    def getAllFiles(self, testFolderName):
        if (testFolderName is None):
            return []
        path = os.path.join(self.testsPath, testFolderName)
        testFiles = self.sorted_ls(path)
#         testFiles = [tf for tf in os.listdir(path) if os.path.isfile(os.path.join(path, tf))]
        return testFiles

    def selectFolder(self):
        testFolderName = self.folderList[self.focusNum].getItem()        
        path = self.testsPath +'/'+testFolderName
        testFiles = [tf for tf in os.listdir(path) if os.path.isfile(os.path.join(path, tf))]
    def selectFile(self):
        if self.folderList[1].isEmpty():
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'Test folder empty.',
                                        'No test files in selected test folder.',
                                        btnDefs = (
                                            {'label': 'OK', 'id': 'yesBtn', 'funct': self.popMsg},
                                            {},
                                            {},
                                            {}
                                        )
                                    )
                        )                    
            return
            
        testFolderName = self.folderList[0].getItem()

        testFile = self.folderList[1].getItem()  + d.TEST_FILE_FORMAT
               
        path = self.testsPath +'/'+testFolderName+'/'+testFile
        from views import testFileView as tfv
        self.app.setView(tfv.TestFileView(self.app, path, self.graph, self))
        

    def upArrowPress(self):
        self.folderList[self.focusNum].upArrowPress()
        if self.focusNum == 0:
            self.replaceList([fullName[0:-4] for fullName in self.getAllFiles(self.folderList[0].getItem())], self.folderList[0].getItem())
    def downArrowPress(self):
        self.folderList[self.focusNum].downArrowPress()
        if self.focusNum ==0:
            self.replaceList([fullName[0:-4] for fullName in self.getAllFiles(self.folderList[0].getItem())], self.folderList[0].getItem())
    def leftArrowPress(self):
        self.folderList[self.focusNum].setFocus(False)
        self.focusNum = not self.focusNum
        self.folderList[self.focusNum].setFocus(True)
        self.initButArea()

    def rightArrowPress(self):
        self.folderList[self.focusNum].setFocus(False)
        self.focusNum = not self.focusNum
        self.folderList[self.focusNum].setFocus(True)
        self.initButArea()

    def displayView(self):
        for fl in self.folderList:
            fl.display()