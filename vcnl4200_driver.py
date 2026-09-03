#Based on: //From: https://github.com/ktsai69/Vishay_VCNL4200
from machine import I2C, Pin, SoftI2C
import time
from micropython import const

DEVICE_ID = 0x1058

VCNL4200_REG_ALS_CONF = b'\x00'
VCNL4200_REG_ALS_THDH = b'\x01'
VCNL4200_REG_ALS_THDL = b'\x02'
VCNL4200_REG_PRX_CONF = b'\x03'
VCNL4200_REG_PRX_CONF3 = b'\x04'
VCNL4200_REG_PRX_CANC = b'\x05'
VCNL4200_REG_PRX_THDL = b'\x06'
VCNL4200_REG_PRX_THDH = b'\x07'
VCNL4200_REG_PRX_DATA = b'\x08'
VCNL4200_REG_ALS_DATA = b'\x09'
VCNL4200_REG_WHITE_DATA = b'\x0A'
VCNL4200_REG_INT_FLAG =b'\x0D'
VCNL4200_REG_ID = b'\x0E'

PRX_IF_AWAY = (1 << 8)
PRX_IF_CLOSE = (1 << 9)
ALS_IF_H = (1 << 12)
ALS_IF_L = (1 << 13)
PRX_SPFLAG = (1 << 14)
PRX_UPFLAG = (1 << 15)
PRX_INT_DISABLE = 0
PRX_INT_CLOSING = 1
PRX_INT_AWAY = 2
PRX_INT_BOTH = 3

# ALS_CONF
VCNL4200_ALS_SD = (1 << 0)
VCNL4200_ALS_INT_EN = (1 << 1)
VCNL4200_ALS_IT_SHIFT = 6
VCNL4200_ALS_IT_MASK = (0x3 << VCNL4200_ALS_IT_SHIFT)
VCNL4200_ALS_IT_50MS = (0x0 << VCNL4200_ALS_IT_SHIFT)
VCNL4200_ALS_IT_100MS = (0x1 << VCNL4200_ALS_IT_SHIFT)
VCNL4200_ALS_IT_200MS = (0x2 << VCNL4200_ALS_IT_SHIFT)
VCNL4200_ALS_IT_400MS = (0x3 << VCNL4200_ALS_IT_SHIFT)
# PRX_CONF
VCNL4200_PRX_SD = (1 << 0)
VCNL4200_PRX_IT_SHIFT = 1
VCNL4200_PRX_IT_MASK = (0x7 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_1T = (0x0 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_1_5T = (0x1 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_2T = (0x2 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_4T = (0x3 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_8T = (0x4 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_IT_9T = (0x5 << VCNL4200_PRX_IT_SHIFT)
VCNL4200_PRX_PERS_SHIFT = 4
VCNL4200_PRX_PERS_MASK = (0x3 << VCNL4200_PRX_PERS_SHIFT)
VCNL4200_PRX_PERS_1 = (0x0 << VCNL4200_PRX_PERS_SHIFT)
VCNL4200_PRX_PERS_2 = (0x1 << VCNL4200_PRX_PERS_SHIFT)
VCNL4200_PRX_PERS_4 = (0x2 << VCNL4200_PRX_PERS_SHIFT)
VCNL4200_PRX_PERS_8 = (0x3 << VCNL4200_PRX_PERS_SHIFT)
VCNL4200_PRX_INT_SHIFT = 8
VCNL4200_PRX_INT_MASK = (0x3 << VCNL4200_PRX_INT_SHIFT)
VCNL4200_PRX_INT_DISABLE = (PRX_INT_DISABLE << VCNL4200_PRX_INT_SHIFT)
VCNL4200_PRX_INT_CLOSING = (PRX_INT_CLOSING << VCNL4200_PRX_INT_SHIFT)
VCNL4200_PRX_INT_AWAY = (PRX_INT_AWAY << VCNL4200_PRX_INT_SHIFT)
VCNL4200_PRX_INT_BOTH = (PRX_INT_BOTH << VCNL4200_PRX_INT_SHIFT)
VCNL4200_PRX_HD = (1 << 11)
# PRX_CONF3
VCNL4200_PRX_SC_EN = (1 << 0)
VCNL4200_PRX_SC_ADV = (1 << 1)
VCNL4200_PRX_SMART_PERS = (1 << 4)
VCNL4200_PRX_MPS_SHIFT = 5
VCNL4200_PRX_MPS_MASK = (0x03 << VCNL4200_PRX_MPS_SHIFT)
VCNL4200_PRX_MPS_1P = (0x0 << VCNL4200_PRX_MPS_SHIFT)
VCNL4200_PRX_MPS_2P = (0x1 << VCNL4200_PRX_MPS_SHIFT)
VCNL4200_PRX_MPS_4P = (0x2 << VCNL4200_PRX_MPS_SHIFT)
VCNL4200_PRX_MPS_8P = (0x3 << VCNL4200_PRX_MPS_SHIFT)
VCNL4200_PRX_LED_I_SHIFT = 8
VCNL4200_PRX_LED_I_MASK = (0x07 << VCNL4200_PRX_LED_I_SHIFT)

VCNL4200_PRX_SPO = (1 << 11)
VCNL4200_PRX_SP = (1 << 12)

# Defaults
VCNL4200_DEFAULT_ALS_CONF = (VCNL4200_ALS_IT_100MS)
VCNL4200_DEFAULT_ALS_THDH = 0xFFFF
VCNL4200_DEFAULT_ALS_THDL = 0x0000
VCNL4200_DEFAULT_PRX_CONF = (VCNL4200_PRX_IT_4T | VCNL4200_PRX_PERS_4 | VCNL4200_PRX_HD)
VCNL4200_DEFAULT_PRX_CONF3 = (VCNL4200_PRX_SC_EN | VCNL4200_PRX_SC_ADV | VCNL4200_PRX_SMART_PERS | VCNL4200_PRX_SPO | VCNL4200_PRX_MPS_2P)
VCNL4200_DEFAULT_PRX_CANC = 0x0000
VCNL4200_DEFAULT_PRX_THDL = 0x0000
VCNL4200_DEFAULT_PRX_THDH = 0xFFFF

# LED Current settings
LED_I = {
    "50MA": const(0x00),  # LED current 50mA
    "75MA": const(0x01),  # LED current 75mA
    "100MA": const(0x02),  # LED current 100mA
    "120MA": const(0x03),  # LED current 120mA
    "140MA": const(0x04),  # LED current 140mA
    "160MA": const(0x05),  # LED current 160mA
    "180MA": const(0x06),  # LED current 180mA
    "200MA": const(0x07),  # LED current 200mA
}

class VCNL4200:

    def begin(self, sda=19, scl=18, address=0x51):
        self.i2c = I2C(0)
        self.i2c_addr = address
        self.writeword(VCNL4200_REG_ALS_THDL, 0x0)
        self.writeword(VCNL4200_REG_ALS_THDL, 0x0)

        chip_id = self.readword(VCNL4200_REG_ID)
        if not chip_id == DEVICE_ID:
            raise "No chip found. Please correct and try again"
        
        print('[+] Device found with id',hex(chip_id))

        if self.writeword(VCNL4200_REG_ALS_CONF, VCNL4200_DEFAULT_ALS_CONF) and self.writeword(VCNL4200_REG_ALS_THDH, VCNL4200_DEFAULT_ALS_THDH) and \
                self.writeword(VCNL4200_REG_ALS_THDL, VCNL4200_DEFAULT_ALS_THDL) and \
                self.writeword(VCNL4200_REG_PRX_CONF, VCNL4200_DEFAULT_PRX_CONF) and \
                self.writeword(VCNL4200_REG_PRX_CONF3, VCNL4200_DEFAULT_PRX_CONF3) and \
                self.writeword(VCNL4200_REG_PRX_CANC, VCNL4200_DEFAULT_PRX_CANC) and \
                self.writeword(VCNL4200_REG_PRX_THDL, VCNL4200_DEFAULT_PRX_THDL) and \
                self.writeword(VCNL4200_REG_PRX_THDH, VCNL4200_DEFAULT_PRX_THDH):
            self.lens_factor = 1.0

    def writeword(self, register, value):
        ba = bytearray()
        ba.append(value&0xff)
        ba.append((value>>8)&0xff)
        self.i2c.writeto_mem(self.i2c_addr, int(register[0]), ba)
        return True

    def readword(self, register):
        val = self.i2c.readfrom_mem(self.i2c_addr, int(register[0]), 2)
        val = (val[1]<<8)|(val[0]&0xff)
        return val

    def bitsUpdate(self, register, mask, update):
        value = self.readword(register)
        print('VALUE',value,'MASK',mask,'UPDATE',update)
        value &= mask
        value |= update
        return self.writeword(register, value)

    def s16(self, value):
        #return -(value & 0x8000) | (value & 0x7fff)
        return 0xffff-value

    def set_PRX_LED_I(self, led_i):
        return self.bitsUpdate(VCNL4200_REG_PRX_CONF3, self.s16(VCNL4200_PRX_LED_I_MASK), led_i << VCNL4200_PRX_LED_I_SHIFT)

    def read_PRX(self):
        return self.readword(VCNL4200_REG_PRX_DATA)

    def read_ALS(self):
        return self.readword(VCNL4200_REG_ALS_DATA)

    def get_lux(self):
        resulution = [0.024, 0.012, 0.006, 0.003]

        als_conf = self.readword(VCNL4200_REG_ALS_CONF)
        als = self.read_ALS()
        if not als_conf or not als:
            return -1.0
        
        als_it = (als_conf & VCNL4200_ALS_IT_MASK) >> VCNL4200_ALS_IT_SHIFT
        lux = als
        lux *= resulution[als_it]
        lux *= self.lens_factor

        return lux

if __name__ == '__main__':
    print('[+] Starting system....')
    sensor = VCNL4200()
    sensor.begin()
    sensor.set_PRX_LED_I(LED_I['50MA'])

    print('[+] Sensor ready!')
    while True:
        print('[+] Getting reading', time.time())
        print('PRX',sensor.read_PRX(), 'LUX',sensor.get_lux())
        time.sleep(.3)
