'''
settingsView.py created by Witold on 2/1/2017 under the pygametrial project
'''
import pygame as pg
import defs as d
from views import view as v
from utils import text as txt
from items import message as msg
from items import viewBtn as vb
from views import keyboardView as kbv
from utils import misc as m
import threading as thr
import time as t
import os
class SettingsView(v.View):
    def __init__(self, app, prevView = None):
        self.btnDefs = [(
            {'label': 'SELECT', 'id': 'selectBtn', 'funct': self.select},
            {},
            {},
            {'label': 'BACK', 'id': 'bckBtn', 'funct': self.back}
        )]
        self.title = 'SETTINGS'
        super().__init__(app, prevView)

        self.stnBtnDefs = (
            {'label': 'HEIGHT', 'funct': self.toHeightSetting},
            {'label': 'PLOT', 'funct': self.toPlotSetting},
            {'label': 'NOTE', 'funct': self.toNoteSetting},
            {'label': 'COLORS', 'funct': self.toColorTesting},
            {'label': 'SENSORS', 'funct': self.toSensorSettingView},
#             {'label': 'VOLUME', 'funct': self.toPendingSetting},
#             {'label': 'GPS', 'funct': self.toPendingSetting},
            {'label': 'OPERATOR', 'funct': self.setOperator},
            {'label': 'UPDATE', 'funct': self.checkUSB}
#             {'label': 'ABOUT', 'funct': self.toPendingSetting},
        )
        self.updateComplete = False
        self.numStnBtnRow = 2
        self.numStnBtnCom = 3
        self.setStnFocusNum(0)
        self.stnBtnsCols = (self.cax - 26*d.px, self.cax, self.cax + 26*d.px)
        self.stnBtnsRows = (self.cay - 24*d.py, self.cay, self.cay + 24*d.py)
        self.addStnBtns()
    def setStnFocusNum(self, num):
        self.stnBtnFocusNum = num
    
    def addStnBtns(self):
        self.stnBtns = []
        for i in range(len(self.stnBtnDefs)):
            row = self.stnBtnsRows[i // 3]
            col = self.stnBtnsCols[i % 3]
            self.stnBtns.append(vb.ViewBtn(app = self.app,
                                           pos = (col, row),
                                           dim = (22*d.px, 18*d.py),
                                           label = self.stnBtnDefs[i]['label'],
                                           funct = self.stnBtnDefs[i]['funct'],
                                           focus =  i == self.stnBtnFocusNum),
                                )            
#             self.stnBtns.append(self.SettingBtn(self.app, {'x': col, 'y': row}, self.stnBtnDefs[i],i == self.stnBtnFocusNum))
    def displayView(self):
        for stnBtn in self.stnBtns:
            stnBtn.display()
    def select(self):
        self.stnBtns[self.stnBtnFocusNum].funct()
    def toHeightSetting(self):
        from views import heightSettingView as hv
        print('go to height setting')
        self.app.setView(hv.HeightView(self.app, self))

    def toPlotSetting(self):
        from views import plotSettingView as psv
        print('go to plot setting')
        self.app.setView(psv.PlotSettingView(self.app, self))

    def toNoteSetting(self):
        from views import notesSettingView as nsv
        print('go to note setting')
        self.app.setView(nsv.NotesSettingView(self.app, self))
    def toColorTesting(self):
        from views import colorTestView as ctv
        self.app.setView(ctv.ColorTestView(self.app, self))
    def toSensorSettingView(self):
        from views import sensorSettingView as ssv
        self.app.setView(ssv.SensorSettingView(self.app, self))
        
    def toUpdateSetting(self):
        from views import updateView as uv
        self.app.setView(uv.UpdateView(self.app, self))
               
    def toPendingSetting(self):
        pass
    
    def setOperator(self):
        self.app.setView(kbv.KeyboardView(self.app, self,
                                      d.WORD,
                                      'Device operator name',
                                      'operator',
                                      self.app.getSetting(d.OPERATOR)
                                      ))
    def keyboardReturn(self, key, value, status = 1):
        if key == 'operator':
            self.app.saveSetting(d.OPERATOR, value)
        
    def back(self):
        from views import mainView as mv
        print('go back')
        self.app.setView(self.prevView)

    def upArrowPress(self):
        if (self.stnBtnFocusNum>=self.numStnBtnCom):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum-=self.numStnBtnCom
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def downArrowPress(self):
        if (self.stnBtnFocusNum<len(self.stnBtnDefs)-self.numStnBtnCom):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum+=self.numStnBtnCom
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def leftArrowPress(self):
        if (self.stnBtnFocusNum>0):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum-=1
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)

    def rightArrowPress(self):
        if (self.stnBtnFocusNum<len(self.stnBtnDefs)-1):
            self.stnBtns[self.stnBtnFocusNum].setFocus(False)
            self.stnBtnFocusNum+=1
            self.stnBtns[self.stnBtnFocusNum].setFocus(True)
            
            
    '''
    Update protocol:
    - User plugs in USB stick
    - User presses UPDATE button
    - GUI looks for valid update files
        -a root folder named 'update'
            -a StalkPusher folder
            -an updateData.json file
            -an updateScript.py script [OPTIONAL]
    - If not found: message saying not found
    - If found: message saying found and comparing versions
    - If user wants to update:
        -execute Script
        -copy and paste, StalkPusher folder to desktop, overriding all but:
            -appData.json [in accordance with updateData.json]
        -update appData.json with new version number
        -set all permissions on written files and folders
        
        -If succesful display success message and put Restart message
            -When restart, do the restart
        -If not:
            -put fail message with revert changes btn
            -if revert changes, revert changes
            
    Special attention should be given to:
        -appData.json
            -make sure there is a default value returned when given data field does not exist yet
                -if default value returned, save it immediatly under given data field
            -make sure software can handle those default values everywhere
            -make sure able to write when given data field does not exist yet
        -test files
            -make sure test file read routine is flexible enough to recognize variable start and end positions of vectors
    '''
    
    """
    Update SUB Stick structure
    /
        /update
            updateData.json
            /cropDevice
                /main
                /utils
                /views
                /...
    updateConf.json contains following info:
    - new version
    - replace appData.json?
    - etc.
    """
    def checkUSB(self):
        if self.app.test is not None:
            if self.app.test.testing:
                return
        validUpdate = False
        scriptUpdate = False
        updatePath = os.path.join(d.USB_DATA_PATH, d.UPDATE_DIR)
        print('checking if update path exists')

        if os.path.exists(updatePath):
            updateDataPath = os.path.join(updatePath, d.UPDATE_DATA_FILE)
            print('update path exists')
            if os.path.isfile(updateDataPath):
                updateData = d.readSettingFromFile(updateDataPath)
                newVersion = updateData['version']
                validUpdate = True
                print('update data exists')
                updateScriptFile = os.path.join(updatePath, d.UPDATE_SCRIPT_FILE)
                if os.path.isfile(updateScriptFile):
                    print('update script exists')
                    scriptUpdate = True
                    
        if validUpdate:
                self.pushMsg(msg.Message(self.app, self, self.disp,
                                            'Valid update found.',
                                            ('Update contains custom script. ' if scriptUpdate else '') + 'Current version: ' + self.app.getSetting(d.VERSION) + ' New version: ' + newVersion,
                                            btnDefs = (
                                                {'label': 'UPDATE', 'id': 'yesBtn', 'funct': (self.popMsg, self.startUpdate)},
                                                {},
                                                {},
                                                {'label': 'CANCEL', 'id': 'yesBtn', 'funct': self.popMsg}
                                            )
                                            )
                                 )
                
        else:
            #either no USB stick or incorrect folder structure
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                        'No valid update.',
                                        'Insert USB stick with valid update',
                                        btnDefs = (
                                            {'label': 'RETRY', 'id': 'yesBtn', 'funct': (self.popMsg, self.checkUSB)},
                                            {},
                                            {},
                                            {'label': 'CANCEL', 'id': 'yesBtn', 'funct': self.popMsg}
                                        )
                                        )
                             )

#     def customUpdate(self):
#         updateScriptPath = os.path.join(os.path.join(d.USB_DATA_PATH, d.UPDATE_DIR), UPDATE_SCRIPT_FILE)
#         m.osCommand('sudo python3 ' + updateScriptPath)        
#         
#         self.pushMsg(msg.Message(self.app, self, self.disp,
#                                     'Update succesful.',
#                                     'Restart device to apply changes.',
#                                     btnDefs = (
#                                         {'label': 'RESTART', 'id': 'yesBtn', 'funct': (self.popMsg, self.app.restartPi)},
#                                         {},
#                                         {},
#                                         {'label': 'LATER', 'id': 'yesBtn', 'funct': self.popMsg}
#                                     )
#                                     )
#                          )
    def startUpdate(self):
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'UPDATING...',
                                    'Please wait while software is updating.',
                                    btnDefs = (
                                        {},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                         )
        updateThread = thr.Thread(target = self.defaultUpdate)
        updateThread.setName('UPDATE THREAD')
        updateThread.daemon = True
        updateThread.start()

    def defaultUpdate(self):
        
        updatePath = os.path.join(d.USB_DATA_PATH, d.UPDATE_DIR)
        updateDataPath = os.path.join(updatePath, d.UPDATE_DATA_FILE)
        updateData = d.readSettingFromFile(updateDataPath)
        newVersion = updateData['version']
        overrideAppData = updateData['overrideAppData']
        
        updSoftwarePath = os.path.join(updatePath, d.STALK_PUSHER_DIR)
        
        #copy
        if overrideAppData:
            m.osCommand('rm -r ' + d.APP_PATH)
            m.osCommand('cp -r ' + updSoftwarePath + ' ' + d.DESKTOP_PATH)
        else:
            oldAppData = d.readSettings()
            oldAppData[d.VERSION] = newVersion
            m.osCommand('rm -r ' + d.APP_PATH)
            m.osCommand('cp -r ' + updSoftwarePath + ' ' + d.DESKTOP_PATH)
            d.saveSettingsObject(oldAppData)
        #set permissions to all
        for path, subdirs, files in os.walk(d.APP_PATH):
            m.osCommand('chmod 777 ' + path)
            for name in files:
                filePath = os.path.join(path, name)
                m.osCommand('chmod 777 ' + filePath)
        
        updateScriptFile = os.path.join(updatePath, d.UPDATE_SCRIPT_FILE)
        if os.path.isfile(updateScriptFile):
            m.osCommand('python3 ' + updateScriptFile)
        
        try:
            restartRequired = updateData['restartRequired']
        except:
            restartRequired = True

        self.popMsg()        
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Update succesful.',
                                    'Restart is required.' if restartRequired else 'Restart is recommended. Changes will not apply until restart.',
                                    btnDefs = (
                                        {'label': 'RESTART', 'id': 'yesBtn', 'funct': (self.popMsg, self.app.restartPi)},
                                        {},
                                        {},
                                        {} if restartRequired else {'label': 'LATER', 'id': 'yesBtn', 'funct': self.popMsg}
                                    )
                                    )
                         )

