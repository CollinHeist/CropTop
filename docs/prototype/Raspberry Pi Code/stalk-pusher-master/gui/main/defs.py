print('defs.py')
import math
import os
import pygame as pg

#read from and write to setting file
#read settings and assign to variables
def readSettings():
    import json
    with open(setting_file_path, 'r') as data_file:
        data = json.load(data_file)
        return data
def readSettingFromFile(file_path):
    import json
    with open(file_path, 'r') as data_file:
        data = json.load(data_file)
        return data
    
#return a given setting
def getSetting(setting):
    import json
    global testHeight, testPlot, testNote
    with open(setting_file_path, 'r') as data_file:
        data = json.load(data_file)
        return data[setting]
def saveSetting(setting, value):
    import json
    with open(setting_file_path, 'r+') as data_file:
        data = json.load(data_file)
        data[setting] = value
        data_file.seek(0)
        json.dump(data, data_file,indent=4)
        data_file.truncate()
def saveSettingsObject(settingsObject):
    import json
    with open(setting_file_path, 'r+') as data_file:
        data_file.seek(0)
        json.dump(settingsObject, data_file,indent=4)
        data_file.truncate()
    
#for parsing date
TIME_DEL = '_'
HOUR_DEL = ':'
MILLIS_DEL = '.'
#invalid arduino input
NUL_ARD_IN = 'NAN'
#constant units (for saving to file, mainly)
HEIGHT_UNIT = 'cm'
TIME_UNIT = 'UTC'
PLOT_UNIT = '#'
GPS_UNIT = 'angular degrees'
#formats
TEST_FILE_FORMAT = '.csv'
SCREENSHOT_FORMAT = '.jpg'
LOG_FORMAT = '.txt'
#default test name
TEST_FILE_NAME = 'test'
#save wait time timeout in seconds
SAVE_TIMEOUT = 2
SAVE_BTN_DELAY = 1
#critical dir names
STALK_PUSHER_DIR = 'StalkPusher'
TESTS_DIR = 'tests'
UPDATE_DIR = 'update'
#critical paths
DESKTOP_PATH = '/home/pi/Desktop'
APP_PATH = '/home/pi/Desktop/StalkPusher/gui'#os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), os.pardir))#../gui/
MAINAPP_PATH = '/home/pi/Desktop/StalkPusher/gui/main'#os.path.join(os.path.dirname(os.path.realpath(__file__)))#../gui/main/
USB_DATA_PATH = '/home/pi/Documents/cropDevUsb'#'/media/cropDevUsb'#'../tests'
RASPI_DATA_PATH = '/home/pi/Documents/cropDevSd'#'../tests'
SCREENSHOT_PATH = '/home/pi/Pictures/CropDevScreens'
#updates
UPDATE_DATA_FILE = 'updateData.json'
UPDATE_SCRIPT_FILE = 'updateScript.py'
#setting file
setting_file_path = '/home/pi/Desktop/StalkPusher/gui/main/appData.json'
#error log files
ERROR_LOG_FILE = '/home/pi/Desktop/cropDevErrorLogFile.txt'
TEST_ERROR_LOG_FILE = '/home/pi/Desktop/cropDevTestErrorLogFile.txt'
SERIAL_LOG_FILE = '/home/pi/Desktop/cropDevSerialLogFile'#.txt'

#permissions
RW_PERM_A = '766'#read write all users
# Screen Geometry
#in pixels
pg.init()
FULLSCREEN = 1
infoObject = pg.display.Info()
width = infoObject.current_w
height = infoObject.current_h
if not FULLSCREEN:
    width = width/2
    height = height/2
# width = 640
# height = 480
px = width/100.0
py = height/100.0
#in inches
diagonalIn = 7
witdthIn = width * diagonalIn/(math.sqrt(width**2+height**2))#
heightIn = height * diagonalIn/(math.sqrt(width**2+height**2))#
pxIn = witdthIn/100.0
pyIn = heightIn/100.0
dpi = width/witdthIn
# Colors
transparent = (0,0,0,100)
black = (0,0,0)
white = (255,255,255)
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
gray = (50,50,50)
light_blue = (50,50,255)
light_green = (50,255,50)
light_gray = (125,125,125)
light_red = (255,50,50)


#gen geo
xMargin = 2*px
yMargin = 2*py

#context area geo
caXDim = 75*px
caYDim = 100*py
caGeo = {'x': 62.5*px,'y':50*py,'xdim':caXDim-2*xMargin,'ydim':caYDim-2*yMargin}

#btnArea geo
btnXdim = 26*px
btnYdim = 25*py
btnAreaGeo = [{'x':12.5*px,'y':12.5*py,'xdim':btnXdim-2*xMargin,'ydim':btnYdim-2*yMargin},
       {'x':12.5*px,'y':37.5*py,'xdim':btnXdim-2*xMargin,'ydim':btnYdim-2*yMargin},
       {'x':12.5*px,'y':62.5*py,'xdim':btnXdim-2*xMargin,'ydim':btnYdim-2*yMargin},
       {'x':12.5*px,'y':87.5*py,'xdim':btnXdim-2*xMargin,'ydim':btnYdim-2*yMargin}]

#Default font sizes, some change dynamically.
BTN_FS = int(3.8*px)
VIEW_TTL_FS = int(6*px)
NL_FS = int(3.6*px)
LV_VB_FS = int(3.2*px)
STN_BTN_FS = int(3.6*px)
MSG_TTL_FS = int(4.6*px)
MSG_BD_FS = int(3.8*px)
CONF_MSG_BD_FS = int(4.4*px)
KB_KEY_FS = int(3.8*px)
NK_FS = int(4*px)

#data strings
TEST_HEIGHT = 'testHeight'
TEST_PLOT = 'testPlot'
PRE_TEST_NOTES = 'preTestNotes'
POST_TEST_NOTES = 'postTestNotes'
NOTE_BANK = 'noteBank'
TEST_FOLDER = 'testFolder'
SENSORS = 'sensors'
SENSOR_BANK = 'sensorBank'
COLORS = 'colors'
DATA_CONFIRM_FREQ = 'dataConfirmFreq'
MAX_START_ANGLE = 'maxStartAngle'
VERSION = 'version'
OPERATOR = 'operator'
#sensor types data strings
DS_LOAD_X = 'LOAD_X'
DS_LOAD_Y = 'LOAD_Y'
DS_IMU = 'IMU'
DS_POT = 'POT'
DS_TEMP = 'TEMP'
DS_HUM = 'HUM'

#data fields for sensor objects
SENSOR_UNIT = 'unit'
SENSOR_A = 'a'
SENSOR_B = 'b'
SENSOR_LAST = 'last'

SENSOR_FIELDS = [SENSOR_UNIT, SENSOR_A, SENSOR_B, SENSOR_LAST]
#    "operator": "witold",

dataStrings = [TEST_HEIGHT, TEST_PLOT, PRE_TEST_NOTES, POST_TEST_NOTES,
                NOTE_BANK, TEST_FOLDER, SENSORS, SENSOR_BANK,
                 COLORS, DATA_CONFIRM_FREQ, MAX_START_ANGLE, VERSION, OPERATOR]
#Sensors
sensorDataStrings = [DS_LOAD_X, DS_LOAD_Y, DS_IMU, DS_POT, DS_TEMP, DS_HUM]

#environemental data strings
TEMPERATURE = 'temp'
LOCATION = 'loc'
HUMIDITY = 'hum'
TIME = 'time'

#testing variables
testHeight = 0
testPlot = 0
testNote = ''
testNotes = []
noteBank = []
#test saving
testHeaders = ['TIME', 'ANGLE_POT', 'ANGLE_IMU', 'LOAD_X', 'LOAD_Y']
#keyboard: num or word?
NUM = 'NUM'
WORD = 'WORD'
ALPHA = 'ALPHA'

MAX_NOTES = 5 #max notes per test

CALIB_AV_T = 2# sampling period for calibration in seconds
#default colors
bcg_col_d = black
font_col_d = black
#colors
textView_highlight_col = green#white#red
textView_neg_col = white#red
textView_pos_col = white#green
font_col_inv = white#light_green
graphBcg_col = white#light_green
graphPoint_col = black
arrow_col = white#red # org light_blue
nlWrapper_col = white
msgHeader_col = white
msgBody_col = light_gray
#default settings
DEF_STN_NUM = 0
DEF_STN_STR = 'N/A'
DEF_SENSORS = {
        "POT": "pot1",
        "LOAD_X": "loadx1",
        "HUM": "hum1",
        "TEMP": "temp1",
        "IMU": "imu1",
        "LOAD_Y": "loady1"
    }
DEF_SENSORBANK = {
        "POT": {
            "pot1": {
                "unit": "Deg",
                "b": 0.0,
                "a": 5400.0,
                "last": "2017-05-20,10:43"
            }
        },
        "LOAD_X": {
            "loadx1": {
                "unit": "N",
                "b": 0.0,
                "a": -120.0,
                "last": "2017_7_9_11:39:30"
            },
        },
        "HUM": {
            "hum1": {
                "unit": "%",
                "b": 0.0,
                "a": 1.0,
                "last": "2017-05-20,10:43"
            }
        },
        "TEMP": {
            "temp1": {
                "unit": "C",
                "b": 0.0,
                "a": 1.0,
                "last": "2017-05-20,10:43"
            }
        },
        "IMU": {
            "imu1": {
                "unit": "Deg",
                "b": 0.0,
                "a": 1.0,
                "last": "2017-05-20,10:43"
            }
        },
        "LOAD_Y": {
            "loady1": {
                "unit": "N",
                "b": 0.0,
                "a": -120.0,
                "last": "2017_7_9_10:39:40"
            }
        }
    }
DEF_COLORS ={
        "font_col": [0,0,0],
        "textView_col": [255,255,255],
        "bcg_col": [0,0,0]
    }

DEF_STN_MAP = {
    TEST_HEIGHT: 150,
    TEST_PLOT: 1,
    PRE_TEST_NOTES: [],
    POST_TEST_NOTES: [],
    NOTE_BANK: [],
    TEST_FOLDER: 'TESTDIR',
    SENSORS: DEF_SENSORS,
    SENSOR_BANK: DEF_SENSORBANK,
    COLORS: DEF_COLORS,
    DATA_CONFIRM_FREQ: 200,
    MAX_START_ANGLE: 5,
    VERSION: '1.0.0',
    OPERATOR: DEF_STN_STR
    }
#conversion from 0-255 RGB to 0-1 RGB
def convertColor(color):
    return (x/255.0 for x in color)
def darkenColor(color):
    return [int(0.5*x) for x in color]
def brightenColor(color):
    return [255 if (int(2*x) % 255) < x else (int(2*x) % 255) for x in color]
def invertColor(color):
    return [255 - x for x in color]    

