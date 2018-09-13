from items import keyBoard as kb
class KeyboardAlpha(kb.Keyboard):
    def __init__(self, disp, geoData):
        super().__init__(disp, geoData)
    def initKBData(self):
        self.chars = (
        '1','2','3','4','5','6','7','8','9','0',
        'Q','W','E','R','T','Y','U','I','O','P',
        'A','S','D','F','G','H','J','K','L','Z',
        'X','C','V','B','N','M','_','-', '(', ')')
        self.rows = 4
        self.columns = 10        

