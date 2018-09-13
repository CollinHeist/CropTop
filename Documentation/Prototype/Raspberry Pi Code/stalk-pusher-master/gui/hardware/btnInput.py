'''
butInterface.py created by Witold under the cropDevice project
'''
import defs as d
import threading as t
import RPi.GPIO as GPIO
import time as t

class BtnInput():
    def __init__(self, btnFunctMap):
        self.btnFunctMap = btnFunctMap
        self.button1 = 6
        self.button2 = 13
        self.button3 = 19
        self.button4 = 26
        self.buttonUp = 12
        self.buttonLeft = 16
        self.buttonRight = 20
        self.buttonDown = 21
        self.bounceTime = 100

        self.leftBtns = [self.button1, self.button2, self.button3, self.button4]
        self.arrowBtns = [self.buttonUp, self.buttonLeft, self.buttonRight, self.buttonDown]

        self.lastLeftInputT = t.time()
        self.inpLeftInt = 0.25
        self.lastLeftInputBtn = 0

        self.lastArrowInputT = t.time()
        self.inpArrowInt = 0.15
        self.lastArrowInputBtn = 0

        self.gpioBtnMap = {
            self.button1: 'btn1Press',
            self.button2: 'btn2Press',
            self.button3: 'btn3Press',
            self.button4: 'btn4Press',
            self.buttonUp: 'upArrowPress',
            self.buttonLeft: 'leftArrowPress',
            self.buttonRight: 'rightArrowPress',
            self.buttonDown: 'downArrowPress'
        }

        GPIO.setmode(GPIO.BCM)

        GPIO.setup(self.button1, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.button2, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.button3, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.button4, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.buttonUp, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.buttonLeft, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.buttonRight, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.setup(self.buttonDown, GPIO.IN, pull_up_down=GPIO.PUD_UP)

        GPIO.add_event_detect(
            self.button1,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.button2,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.button3,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.button4,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )
        GPIO.add_event_detect(
            self.buttonUp,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.buttonLeft,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.buttonRight,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )

        GPIO.add_event_detect(
            self.buttonDown,
            GPIO.FALLING,
            callback=self.btnInput,
            bouncetime=self.bounceTime
        )
    #lewo: 26
    #up: 
    #right:
    #down:
    def btnInput(self, btn):
        print('button input')
        if btn in self.leftBtns:
            if not (t.time() - self.lastLeftInputT < self.inpLeftInt and self.lastLeftInputBtn == btn):
                self.lastLeftInputBtn = btn
                self.lastLeftInputT = t.time()
                self.btnFunctMap[self.gpioBtnMap[btn]]()
            else:
                print(t.time() - self.lastLeftInputT)
        elif btn in self.arrowBtns:
            if not (t.time() - self.lastArrowInputT < self.inpArrowInt and self.lastArrowInputBtn == btn):
                self.lastArrowInputBtn = btn
                self.lastArrowInputT = t.time()
                self.btnFunctMap[self.gpioBtnMap[btn]]()
            else:
                print(t.time() - self.lastArrowInputT)
