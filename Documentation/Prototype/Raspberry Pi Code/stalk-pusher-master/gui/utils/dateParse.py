'''
2017_6_22_8_31_53
'''
from main import defs as d
class DateParse:
    def __init__(self, dateStr):
        try:
            print(dateStr.split(d.TIME_DEL))
            [self.year, self.month, self.day, self.hour, self.minute, self.second]  = dateStr.split(d.TIME_DEL)
        except Exception as e:
            self.year = 'N/A'
            self.month = 'N/A'
            self.day = 'N/A'
            self.hour = 'N/A'
            self.minute = 'N/A'
            self.second = 'N/A'
            print ('date parse error:', str(e))
    def getTime(self):
        return self.hour + d.HOUR_DEL + self.minute + d.HOUR_DEL + self.second
    def getDateTime(self):
        return self.year + d.TIME_DEL + self.month + d.TIME_DEL + self.day + d.TIME_DEL + self.getTime()
        