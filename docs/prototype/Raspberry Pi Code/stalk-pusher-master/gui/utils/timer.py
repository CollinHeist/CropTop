"""
this will no0tify the gui thread that a given amount of time has elapsed
it accepts a time in seconds and a function to be executed
when that time has elapsed.

available both as a class to instantiate and keep a record of or just a
no return function
"""
import threading as thr
import time as t
def setTimer(waitT, func):
    waitThread = thr.Thread(target=wait, args=(waitT, func,))
    waitThread.daemon = True
    waitThread.name = 'TIMER'
    waitThread.start()
 
def wait(waitT, func):
    t.sleep(waitT)
    func()
    

class Timer(thr.Thread):
    def __init__(self, waitT, func):
        self.waitT = waitT
        self.func = func
        super().__init__(self)
    def run(self):
        t.sleep(self.waitT)
        self.func()
    