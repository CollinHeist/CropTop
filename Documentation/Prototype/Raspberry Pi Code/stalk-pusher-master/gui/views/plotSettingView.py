'''
plotCView.py created by Witold on 2/1/2017 under the cropDevice project
'''
from items import numChoice as nc
from views import view as v
class PlotSettingView(v.View):
    def __init__(self, app, prevView = None):
        self.title = 'Plot Setting'
        self.btnDefs = [
            (
            {'label': 'SAVE', 'id': 'saveBtn', 'funct': self.save},
            {},
            {},
            {'label': 'CANCEL', 'id': 'cancelBtn', 'funct': self.cancel})
            ]

        super().__init__(app, prevView)
        self.numBtnX = self.cax
        self.numBtnY = self.cay
        self.startNumChoice()
    def save(self):
        self.numChoice.saveValue()
        self.goBack()
    def cancel(self):
        self.goBack()
        # from views import settingsView as sv
        # self.app.setView(sv.SettingsView(self.app))

    def startNumChoice(self):
        self.numChoice = nc.NumChoice(self.app,self.disp,{'value':'testPlot','unit':'#', 'numDigits':6, 'unitPos': 'prefix'}, {'x':self.cax, 'y':self.cay})
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
