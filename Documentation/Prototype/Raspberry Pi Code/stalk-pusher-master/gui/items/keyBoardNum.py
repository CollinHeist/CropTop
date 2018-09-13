from items import keyBoard as kb

class KeyboardNum(kb.Keyboard):
    def __init__(self, disp, geoData):
        super().__init__(disp, geoData)
    def initKBData(self):
        self.chars = (
        '1','2','3',
        '4','5','6',
        '7','8','9',
        '0','.','-')
        self.rows = 4
        self.columns = 3        
        