import unittest
import serial
import time

class TestStringMethods(unittest.TestCase):

    def setUp(self):
        self.ser = serial.Serial('/dev/tty.usbserial-A504WQVE',19200)

    # def test_Ready(self):
    #     message = (self.__class__.ser).readline()
    #     print message
    #     self.assertTrue("%RDDYRECE$" in message)

    def test_PCLL0000(self):
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%PCLL0000$\r\n')
            message = self.ser.readline()
            if ('%PCLLRECE$' in message):
                message = self.ser.readline()
                self.assertTrue("TI" in message and "LO" in message and "TE" in message and "HU" in message)
            else:
                self.fail()
        else:
            self.fail()

    def test_PCLL0001(self):
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%PCLL0001$\r\n')
            message = self.ser.readline()
            if ('%PCLLRECE$' in message):
                message = self.ser.readline()
                # print message
                self.assertTrue("TI" not in message and "LO" not in message and "TE" in message and "HU" not in message and "NAN" not in message)
            else:
                self.fail()
        else:
            self.fail()

    def test_PCLL0010(self):
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%PCLL0010$\r\n')
            message = self.ser.readline()
            if ('%PCLLRECE$' in message):
                message = self.ser.readline()
                # print message
                self.assertTrue("TI" not in message and "LO" not in message and "TE" not in message and "HU" in message and "NAN" not in message)
            else:
                self.fail()
        else:
            self.fail()

    def test_PCLL0100(self):
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%PCLL0100$\r\n')
            message = self.ser.readline()
            if ('%PCLLRECE$' in message):
                message = self.ser.readline()
                # print message
                self.assertTrue("TI" not in message and "LO" in message and "TE" not in message and "HU" not in message and "NAN" not in message)
            else:
                self.fail()
        else:
            self.fail()

    def test_PCLL1000(self):
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%PCLL1000$\r\n')
            message = self.ser.readline()
            if ('%PCLLRECE$' in message):
                message = self.ser.readline()
                # print message
                self.assertTrue("TI" in message and "LO" not in message and "TE" not in message and "HU" not in message and "NAN" not in message)
            else:
                self.fail()
        else:
            self.fail()


    def test_LIVE(self):
        liveMessage = [];
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%LIVE0000$\r\n')
            message = self.ser.readline()
            if ('%LIVERECE$' in message):
                time.sleep(1)
                self.ser.write('%STOP$\r\n')
                time.sleep(1)
                while (self.ser.in_waiting > 0 ):
                    liveMessage.append(self.ser.readline())

                self.assertTrue('%STOPRECE$' in liveMessage[-1])
                self.assertTrue("MI" in liveMessage[-2] and "AI" in liveMessage[-2] and "AP" in liveMessage[-2] and "FX" in liveMessage[-2] and "FY" in liveMessage[-2] and "TI" in liveMessage[-2] and "LO" in liveMessage[-2])
            else:
                self.fail()
        else:
            self.fail()

    def test_STRM(self):
        liveMessage = [];
        message = self.ser.readline()
        if ("%RDDYRECE$" in message):
            self.ser.write('%STRM0000$\r\n')
            message = self.ser.readline()
            if ('%STRMRECE$' in message):
                time.sleep(1)
                self.ser.write('%STOP$\r\n')
                time.sleep(1)
                while (self.ser.in_waiting > 0 ):
                    liveMessage.append(self.ser.readline())
                print liveMessage[-2]
                self.assertTrue('%STOPRECE$' in liveMessage[-1])
                self.assertTrue("MI" in liveMessage[-2] and "AI" in liveMessage[-2] and "AP" in liveMessage[-2] and "FX" in liveMessage[-2] and "FY" in liveMessage[-2])
            else:
                self.fail()
        else:
            self.fail()

    def tearDown(self):
        self.ser.close()

if __name__ == '__main__':
    unittest.main()
