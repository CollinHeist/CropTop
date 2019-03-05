import threading as thr
import time as t
from random import randint
from main import defs as d
import sys
RUN_TIME = 20#s
FREQ = 0.01#s
class Test:
    def __init__(self, app, runTime = RUN_TIME, freq = FREQ):
        self.app = app
        self.runTime = runTime
        self.freq = freq
        self.testing = False
#         self.initRandInputThread()
    def startTest(self):
        print('BTN INPUT TEST INITIATED')
        self.cropDevTestErrorLogFile = open(d.TEST_ERROR_LOG_FILE, 'a+')
        sys.stderr = self.cropDevTestErrorLogFile

        self.testing = True
        rIThread = thr.Thread(target = self.randInput)
        rIThread.daemon = True
        rIThread.name = 'TEST THREAD'
        rIThread.start()
    def randInput(self):
        startT = t.time()
        lastInputT = t.time()
        while self.testing:# and t.time() - startT < RUN_TIME
            t.sleep(self.freq)
#             if t.time() - lastInputT >= self.freq: 
            lastInputT = t.time()
            key = randint(0,7)
            self.app.btnInput.setBtnByNum(key)           
        self.testing = False
    def stopTest(self):
        print('BTN INPUT TEST STOPPED')
        self.testing = False     
        self.cropDevTestErrorLogFile.close()       
        sys.stderr = sys.__stderr__

        