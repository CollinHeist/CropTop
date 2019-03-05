'''
heightCView.py created by Witold on 2/1/2017 under the cropDevice project
'''
from items import numChoice as nc
from views import view as v
from main import defs as d
class HeightView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'HEIGHT SETTING'
        self.btnDefs = [
                (
                    {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
                    {},
                    {},
                    {'label': 'CANCEL', 'id': 'cancelBtn', 'funct': self.cancel}
                )
            ]
        super().__init__(app, prevView)

        self.numBtnX = self.cax
        self.numBtnY = self.cay
        self.startNumChoice()

    def save(self):
        # from views import settingsView as sv
        self.numChoice.saveValue()
        self.goBack()
        # self.app.setView(sv.SettingsView(self.app))
    def cancel(self):
        self.goBack()
        # self.app.setView(sv.SettingsView(self.app))
    def startNumChoice(self):
        self.numChoice = nc.NumChoice(self.app, self.disp,{'value':d.TEST_HEIGHT,'unit':'cm', 'numDigits':3, 'unitPos': 'suffix'}, {'x':self.cax, 'y':self.cay})
    def display(self):
        super().display()
        self.numChoice.display()
    def upArrowPress(self):
        self.numChoice.upArrowPress()
    def downArrowPress(self):
        self.numChoice.downArrowPress()
    def leftArrowPress(self):
        self.numChoice.leftArrowPress()
    def rightArrowPress(self):
        self.numChoice.rightArrowPress()
