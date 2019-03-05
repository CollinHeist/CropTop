'''
butInterface.py created by Witold under the cropDevice project
'''
import defs as d
import threading as thr
import RPi.GPIO as GPIO
import time as t
LOW = 0
HIGH = 1

BTN_INT = 0.02
#Button pins
BTN_1 = 12#6
BTN_2 = 16#13
BTN_3 = 20#19
BTN_4 = 21#26
BTN_UP = 6#12
BTN_LEFT = 19#16
BTN_RIGHT = 26#20
BTN_DOWN = 13#21

btnPins = [BTN_1, BTN_2, BTN_3, BTN_4, BTN_UP, BTN_LEFT, BTN_RIGHT, BTN_DOWN]

gpioBtnMap = {
    BTN_1: 'btn1Press',
    BTN_2: 'btn2Press',
    BTN_3: 'btn3Press',
    BTN_4: 'btn4Press',
    BTN_UP: 'upArrowPress',
    BTN_LEFT: 'leftArrowPress',
    BTN_RIGHT: 'rightArrowPress',
    BTN_DOWN: 'downArrowPress'
}


class BtnInput():
    def __init__(self, btnFunctMap):
        #self.app = app
        self.btnFunctMap = btnFunctMap
        
        self.button1 = 12#6
        self.button2 = 16#13
        self.button3 = 20#19
        self.button4 = 21#26
        self.buttonUp = 6#12
        self.buttonLeft = 19#16
        self.buttonRight = 26#20
        self.buttonDown = 13#21

        self.lastIn = 0 
        GPIO.setmode(GPIO.BCM)
        
        self.gpioBtnMap = {
            self.button1: 0,
            self.button2: 1,
            self.button3: 2,
            self.button4: 3,
            self.buttonUp: 4,
            self.buttonLeft: 5,
            self.buttonRight: 6,
            self.buttonDown: 7
        }        

        
        self.buttons = []
        self.resetBtnPresses()
        for pin in btnPins:
            self.buttons.append(self.Button(pin))
        #self.startBtnReadThread()
        
    def resetBtnPresses(self):
        self.btnPresses = [False] * 8
        
    def startBtnReadThread(self):
        btnThread = thr.Thread(target = self.checkInput)
        btnThread.setName('BUTTON INPUT THREAD')
        btnThread.daemon = True
        btnThread.start()
        print('started button input read thread')

    def checkInput(self):
        #while True:
            #pass
#             print('BUTTON THREAD: ' + str(t.time() - self.lastIn))
#             self.lastIn = t.time()
            #t.sleep(0.005)
#         print('checkInput')
        for button in self.buttons:
#             print('checking btn: ' + str(self.gpioBtnMap[button.pin]))
            if button.wasPressed():
#                 print('btn was pressed: '+  str(self.gpioBtnMap[button.pin]))

                if not self.btnPresses[self.gpioBtnMap[button.pin]]:
#                     print('csetting press to true for btn: ' + str(self.gpioBtnMap[button.pin]))

                    self.setBtnByPin(button.pin)       

#                     if self.app.view is not None:
#                         self.btnFunctMap[gpioBtnMap[button.pin]]()
    def setBtnByPin(self, pin):
        assert pin in btnPins
        self.btnPresses[self.gpioBtnMap[pin]] = True       

    def setBtnByNum(self, num):
        assert num < 8
        self.btnPresses[num] = True       

    class Button:
        def __init__(self, pin):
            self.pin = pin
            self.lastStatus = HIGH
            self.status = HIGH
            self.lastChangeT = 0

            GPIO.setup(self.pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

        def wasPressed(self):
            self.status = GPIO.input(self.pin)
            if self.status != self.lastStatus:
                self.lastStatus = self.status
                if self.status == HIGH:#button depressed
                    if t.time() - self.lastChangeT > BTN_INT:
                        self.lastChangeT = t.time()
                        return True
            return False