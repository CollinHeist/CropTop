from items import noteList as nl
import os
from views import view as v
from main import defs as d
from views import keyboardView as kbv
from items import message as msg
from utils import dateParse as dp
class SensorSettingView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'SENSORS MANAGER'
        self.btnDefs = [
                (
                    {'label': 'ADD\nSENSOR', 'id': 'addSensorBtn', 'funct': self.addSensor},
                    {},
                    {},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                ),
                (
                    {},
                    {'label': 'MORE', 'id': 'startBtn', 'funct': self.moreBtn},
                    {'label': 'SELECT', 'id': 'startBtn', 'funct': self.selectSensor},
                    {'label': 'BACK', 'id': 'bckBtn', 'funct': self.goBack}
                )
            ]
#self.sensorData = self.app.getSetting(d.SENSORS)[self.sensor]
        super().__init__(app, prevView)
        self.numBtnX = self.cax
        self.numBtnY = self.cay
        
        self.getData()
        self.initLists()
        
#         self.focus = 0
#         self.folderList[self.focus].setFocus(True)
    def getData(self):
        self.sensorBankData = self.app.getSetting(d.SENSOR_BANK)
        self.sensorsData = self.app.getSetting(d.SENSORS)
        
    def initLists(self):
        self.nls = []
        
        self.nls.append(nl.NoteList(self.app, self.disp,{'x':self.cax-20*d.px,'y':self.cay, 'xdim':28*d.px, 'ydim': 50*d.py}, d.sensorDataStrings, 'Device channels', True))
        l = self.getAllSensors(self.nls[0].getItem())
        
        self.nls.append(nl.NoteList(self.app, self.disp,{'x':self.cax+20*d.px,'y':self.cay, 'xdim':28*d.px, 'ydim': 50*d.py}, l,self.nls[0].getItem()+' sensors', False))
        self.nls[1].selectByItem(self.sensorsData[self.nls[0].getItem()])
            
    def addSensor(self):
        self.popMsg()
        self.app.hd.getAll()
        self.newSensor = {}
        self.newSensor['sensorType'] = self.nls[0].getItem()
        self.app.setView(kbv.KeyboardView(self.app, self,
                                             d.WORD,
                                             'Sensor Name',
                                             'sensorName'
                                             ))
    
    def keyboardReturn(self, key, value, status = 1):
        self.newSensor[key] = value
        print('key', key)
        if key == 'sensorName':
            if value in self.getAllSensors(self.newSensor['sensorType']):
                    self.pushMsg(msg.Message(self.app, self, self.disp,
                                'INVALID SENSOR NAME',
                                'Sensor ' + value +' already exists.',
                                btnDefs = (
                                    {'label': 'RETRY', 'id': 'exitBtn', 'funct': self.addSensor},
                                    {},
                                    {},
                                    {'label': 'OK', 'id': 'cancelBtn', 'funct': self.popMsg}
                                )
                                )
                    )
            else:
                self.app.setView(kbv.KeyboardView(self.app, self,
                                                     d.WORD,
                                                     'Sensor Unit',
                                                     'sensorUnit'
                                                     ))
        elif key == 'sensorUnit':
            self.saveAddedSensor()
            from views import editSensorView as esv
            self.app.setView(esv.EditSensorView(self.app, self.newSensor['sensorType'], self.newSensor['sensorName'], self))



    def saveAddedSensor(self):
        newSensorData = {d.SENSOR_UNIT: self.newSensor['sensorUnit'],
                      d.SENSOR_A: 'NaN',
                      d.SENSOR_B: 'NaN',
                      d.SENSOR_LAST: dp.DateParse(self.app.getEnvData(d.TIME)).getDateTime()}
        sensorBank = self.app.getSetting(d.SENSOR_BANK)
        sensorBank[self.newSensor['sensorType']][self.newSensor['sensorName']] = newSensorData
        self.app.saveSetting(d.SENSOR_BANK, sensorBank)
        self.initLists()
                    
    def moreBtn(self):
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                'Select action.',
                                'Choose your desired action for sensor ' + self.nls[1].getItem(),
                                btnDefs = (
                                    {'label': 'REMOVE', 'id': 'exitBtn', 'funct': self.removeSensorPrompt},
                                    {'label': 'EDIT', 'id': 'restartBtn', 'funct': self.toEditView},
                                    {'label': 'CALIBRATE', 'id': 'shutdownBtn', 'funct': self.toCalibrationView},
                                    {'label': 'CANCEL', 'id': 'cancelBtn', 'funct': self.popMsg}
                                )
                                )
                    )
                     
    def removeSensorPrompt(self):
        self.pushMsg(msg.Message(self.app, self, self.disp,
                                'Removing sensor ' + self.nls[1].getItem(),
                                'Are you sure?',
                                btnDefs = (
                                    {'label': 'YES', 'id': 'exitBtn', 'funct': self.removeSensor},
                                    {},
                                    {},
                                    {'label': 'NO', 'id': 'cancelBtn', 'funct': self.popMsg}
                                )
                                )
                    )
    def removeSensor(self):
        self.popMsg()
        self.popMsg()

        if len(list(self.sensorBankData[self.nls[0].getItem()])) <=1:
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Cannot remove ' + self.nls[1].getItem(),
                                    'This is the only ' + self.nls[0].getItem() + ' sensor type. Add another one first.',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'cancelBtn', 'funct': self.popMsg},
                                        {'label': 'ADD', 'id': 'addSensorBtn', 'funct': self.addSensor},
                                        {},
                                        {}
                                    )
                                    )
                        )
            return
        if self.nls[1].isCurrentSelected():
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Cannot remove ' + self.nls[1].getItem(),
                                    'This sensor is the selected one. Select another one first..',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'cancelBtn', 'funct': self.popMsg},
                                        {},
                                        {},
                                        {}
                                    )
                                    )
                        )
            return
            
        sensorBank = self.app.getSetting(d.SENSOR_BANK)
        del sensorBank[self.nls[0].getItem()][self.nls[1].getItem()]
        self.app.saveSetting(d.SENSOR_BANK, sensorBank)
        self.setFocus(not self.focusNum)        
        self.initLists()
        self.initButArea()
             
    def toEditView(self):
        self.popMsg()
        from views import editSensorView as esv
        self.app.setView(esv.EditSensorView(self.app, self.nls[0].getItem(), self.nls[1].getItem(), self))
#     def keyboardReturn(self, key, value, status = 1):
#         i
    def toCalibrationView  (self):
        self.popMsg()

        from views import calibrationView as cv
        self.app.setView(cv.CalibrationView(self.app, self.nls[0].getItem(), self.nls[1].getItem(), self))

    def selectSensor(self):
        currSensData = self.sensorBankData[self.nls[0].getItem()][self.nls[1].getItem()]
        if type(currSensData[d.SENSOR_A]) != type(0.0) or type(currSensData[d.SENSOR_B]) != type(0.0):#invalid a or b parameters
            self.pushMsg(msg.Message(self.app, self, self.disp,
                                    'Invalid sensor parameters',
                                    'Set calibration parameters of ' + self.nls[1].getItem() + ' and retry.',
                                    btnDefs = (
                                        {'label': 'OK', 'id': 'cancelBtn', 'funct': self.popMsg},
                                        {'label': 'EDIT', 'id': 'restartBtn', 'funct': self.toEditView},
                                        {'label': 'CALIBRATE', 'id': 'shutdownBtn', 'funct': self.toCalibrationView},
                                        {}
                                    )
                                    )
                        )
            return
        self.nls[1].selectCurrentExclusive()
        self.sensorsData[self.nls[0].getItem()] = self.nls[1].getSelectedExclusive()
        self.app.saveSetting(d.SENSORS, self.sensorsData)
    def replaceList(self, sensorName):
        l = self.getAllSensors(sensorName)
        self.nls[1] = (nl.NoteList(self.app, self.disp,{'x':self.cax+20*d.px,'y':self.cay, 'xdim':28*d.px, 'ydim': 50*d.py}, l, sensorName + ' sensors', False))
        self.nls[1].selectByItem(self.sensorsData[self.nls[0].getItem()])
                
    def getAllSensors(self, sensorType):
        return list(self.sensorBankData[sensorType])

    def setFocus(self, focusNum):
        self.nls[self.focusNum].setFocus(False)
        self.focusNum = focusNum
        self.nls[self.focusNum].setFocus(True)
                
    def upArrowPress(self):
        self.nls[self.focusNum].upArrowPress()
        if self.focusNum ==0:
            self.replaceList(self.nls[0].getItem())
    def downArrowPress(self):
        self.nls[self.focusNum].downArrowPress()
        if self.focusNum ==0:
            self.replaceList(self.nls[0].getItem())
    def leftArrowPress(self):
        self.setFocus(not self.focusNum)
        self.initButArea()

    def rightArrowPress(self):

        self.setFocus(not self.focusNum)
        self.initButArea()

    def displayView(self):
        for fl in self.nls:
            fl.display()