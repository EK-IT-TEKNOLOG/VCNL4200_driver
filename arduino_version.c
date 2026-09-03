//From: https://github.com/ktsai69/Vishay_VCNL4200
#define VCNL4200_ADDRESS            0x51
#define VCNL4200_WHO_AM_I           0x58

#define VCNL4200_REG_ALS_CONF       0x00
#define VCNL4200_REG_ALS_THDH       0x01
#define VCNL4200_REG_ALS_THDL       0x02
#define VCNL4200_REG_PRX_CONF       0x03
#define VCNL4200_REG_PRX_CONF3      0x04
#define VCNL4200_REG_PRX_CANC       0x05
#define VCNL4200_REG_PRX_THDL       0x06
#define VCNL4200_REG_PRX_THDH       0x07
#define VCNL4200_REG_PRX_DATA       0x08
#define VCNL4200_REG_ALS_DATA       0x09
#define VCNL4200_REG_WHITE_DATA     0x0A
#define VCNL4200_REG_INT_FLAG       0x0D
#define VCNL4200_REG_ID             0x0E

// ALS_CONF
#define VCNL4200_ALS_SD             (1 << 0)
#define VCNL4200_ALS_INT_EN         (1 << 1)
#define VCNL4200_ALS_IT_SHIFT       6
#define VCNL4200_ALS_IT_MASK        (0x3 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_50MS        (0x0 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_100MS       (0x1 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_200MS       (0x2 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_400MS       (0x3 << VCNL4200_ALS_IT_SHIFT)
// PRX_CONF
#define VCNL4200_PRX_SD             (1 << 0)
#define VCNL4200_PRX_IT_SHIFT       1
#define VCNL4200_PRX_IT_MASK        (0x7 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_1T          (0x0 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_1_5T        (0x1 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_2T          (0x2 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_4T          (0x3 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_8T          (0x4 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_9T          (0x5 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_PERS_SHIFT     4
#define VCNL4200_PRX_PERS_MASK      (0x3 << VCNL4200_PRX_PERS_SHIFT)
#define VCNL4200_PRX_PERS_1         (0x0 << VCNL4200_PRX_PERS_SHIFT)
#define VCNL4200_PRX_PERS_2         (0x1 << VCNL4200_PRX_PERS_SHIFT)
#define VCNL4200_PRX_PERS_4         (0x2 << VCNL4200_PRX_PERS_SHIFT)
#define VCNL4200_PRX_PERS_8         (0x3 << VCNL4200_PRX_PERS_SHIFT)
#define VCNL4200_PRX_INT_SHIFT      8
#define VCNL4200_PRX_INT_MASK       (0x3 << VCNL4200_PRX_INT_SHIFT)
#define VCNL4200_PRX_INT_DISABLE    (PRX_INT_DISABLE << VCNL4200_PRX_INT_SHIFT)
#define VCNL4200_PRX_INT_CLOSING    (PRX_INT_CLOSING << VCNL4200_PRX_INT_SHIFT)
#define VCNL4200_PRX_INT_AWAY       (PRX_INT_AWAY << VCNL4200_PRX_INT_SHIFT)
#define VCNL4200_PRX_INT_BOTH       (PRX_INT_BOTH << VCNL4200_PRX_INT_SHIFT)
#define VCNL4200_PRX_HD             (1 << 11)
// PRX_CONF3
#define VCNL4200_PRX_SC_EN          (1 << 0)
#define VCNL4200_PRX_SC_ADV         (1 << 1)
#define VCNL4200_PRX_SMART_PERS     (1 << 4)
#define VCNL4200_PRX_MPS_SHIFT      5
#define VCNL4200_PRX_MPS_MASK       (0x03 << VCNL4200_PRX_MPS_SHIFT)
#define VCNL4200_PRX_MPS_1P         (0x0 << VCNL4200_PRX_MPS_SHIFT)
#define VCNL4200_PRX_MPS_2P         (0x1 << VCNL4200_PRX_MPS_SHIFT)
#define VCNL4200_PRX_MPS_4P         (0x2 << VCNL4200_PRX_MPS_SHIFT)
#define VCNL4200_PRX_MPS_8P         (0x3 << VCNL4200_PRX_MPS_SHIFT)
#define VCNL4200_PRX_LED_I_SHIFT    8
#define VCNL4200_PRX_LED_I_MASK     (0x07 << VCNL4200_PRX_LED_I_SHIFT)

#define VCNL4200_PRX_SPO            (1 << 11)
#define VCNL4200_PRX_SP             (1 << 12)

// Defaults
#define VCNL4200_DEFAULT_ALS_CONF   (VCNL4200_ALS_IT_100MS)
#define VCNL4200_DEFAULT_ALS_THDH   0xFFFF
#define VCNL4200_DEFAULT_ALS_THDL   0x0000
#define VCNL4200_DEFAULT_PRX_CONF   (VCNL4200_PRX_IT_4T | \
                                     VCNL4200_PRX_PERS_4 | \
                                     VCNL4200_PRX_HD)
#define VCNL4200_DEFAULT_PRX_CONF3  (VCNL4200_PRX_SC_EN | \
                                     VCNL4200_PRX_SC_ADV | \
                                     VCNL4200_PRX_SMART_PERS | \
                                     VCNL4200_PRX_SPO | \
                                     VCNL4200_PRX_MPS_2P)
#define VCNL4200_DEFAULT_PRX_CANC   0x0000
#define VCNL4200_DEFAULT_PRX_THDL   0x0000
#define VCNL4200_DEFAULT_PRX_THDH   0xFFFF

float lens_factor;
uint8_t slaveAddress;

enum PRX_LED_I_t {
      PRX_LED_I_50mA = 0,
      PRX_LED_I_75mA = 1,
      PRX_LED_I_100mA = 2,
      PRX_LED_I_120mA = 3,
      PRX_LED_I_140mA = 4,
      PRX_LED_I_160mA = 5,
      PRX_LED_I_180mA = 6,
      PRX_LED_I_200mA = 7};

const uint16_t
      PRX_IF_AWAY = (1 << 8),
      PRX_IF_CLOSE = (1 << 9),
      ALS_IF_H = (1 << 12),
      ALS_IF_L = (1 << 13),
      PRX_SPFLAG = (1 << 14),
      PRX_UPFLAG = (1 << 15);
    const uint16_t
      PRX_INT_DISABLE = 0,
      PRX_INT_CLOSING = 1,
      PRX_INT_AWAY = 2,
      PRX_INT_BOTH = 3;

//#include <Arduino.h>
#include <Wire.h>

TwoWire* _wire;

int begin(void)
{
  _wire->begin(19, 18);
  slaveAddress = VCNL4200_ADDRESS;

  // Prevent I2C bus lockup
  writeWord(VCNL4200_REG_ALS_THDL, 0x0);
  writeWord(VCNL4200_REG_ALS_THDL, 0x0);
  
  uint16_t id;
  if (!readWord(VCNL4200_REG_ID, &id) || (id & 0xFF) != VCNL4200_WHO_AM_I)
	  return 0;

  // Initialization
  if (writeWord(VCNL4200_REG_ALS_CONF, VCNL4200_DEFAULT_ALS_CONF) &&
      writeWord(VCNL4200_REG_ALS_THDH, VCNL4200_DEFAULT_ALS_THDH) &&
      writeWord(VCNL4200_REG_ALS_THDL, VCNL4200_DEFAULT_ALS_THDL) &&
      writeWord(VCNL4200_REG_PRX_CONF, VCNL4200_DEFAULT_PRX_CONF) &&
      writeWord(VCNL4200_REG_PRX_CONF3, VCNL4200_DEFAULT_PRX_CONF3) &&
      writeWord(VCNL4200_REG_PRX_CANC, VCNL4200_DEFAULT_PRX_CANC) &&
      writeWord(VCNL4200_REG_PRX_THDL, VCNL4200_DEFAULT_PRX_THDL) &&
      writeWord(VCNL4200_REG_PRX_THDH, VCNL4200_DEFAULT_PRX_THDH))
  {
    lens_factor = 1.0;
    return 1;
  }
  
  return 0;
}

void end(void)
{
  ALS_INT_EN(false);
  ALS_SD(true);
  PRX_INT(false);
  PRX_SD(true);
}

boolean bitsUpdate(uint8_t reg, uint16_t mask, uint16_t update)
{
  uint16_t value;
  
  if (!readWord(reg, &value))
    return false;
  value &= mask;
  value |= update;
  return writeWord(reg, value);
}

boolean read_PRX(uint16_t *prx)
{
  return readWord(VCNL4200_REG_PRX_DATA, prx);
}

boolean read_ALS(uint16_t *als)
{
  return readWord(VCNL4200_REG_ALS_DATA, als);
}

float get_lux(void)
{
  uint16_t als;
  uint16_t als_conf;
  uint16_t als_it;
  float lux;
  float resolution[] = {0.024f, 0.012f, 0.006f, 0.003f};

  if (!readWord(VCNL4200_REG_ALS_CONF, &als_conf) || !read_ALS(&als))
    return -1.0f;
    
  als_it = (als_conf & VCNL4200_ALS_IT_MASK) >> VCNL4200_ALS_IT_SHIFT;
    
  lux = (float)als;
  lux *= resolution[als_it];
  lux *= lens_factor;
  return lux;
}

boolean ALS_SD(boolean shutdown)
{
  return bitsUpdate(
    VCNL4200_REG_ALS_CONF,
    ~VCNL4200_ALS_SD,
    shutdown ? VCNL4200_ALS_SD : 0);
}

boolean ALS_INT_EN(boolean enable)
{
  return bitsUpdate(
    VCNL4200_REG_ALS_CONF,
    ~VCNL4200_ALS_INT_EN,
    enable ? VCNL4200_ALS_INT_EN : 0);
}

boolean ALS_INT_with_threshold(float percent)
{
  uint16_t als;
  
  if (!read_ALS(&als) || percent <= 0)
    return false;
 
  float thdh = (float)als * (100.0 + percent) / 100.0;
  float thdl = (float)als * (100.0 - percent) / 100.0;
  if (thdh - thdl < 1.0)
    thdh += 1.0;
  uint16_t wh = (thdh > 65535.0f) ? 65535 : (uint16_t)thdh;   
  uint16_t wl = (thdl < 0.0f) ? 0 : (uint16_t)thdl;

  if (ALS_INT_EN(false) &&
      writeWord(VCNL4200_REG_ALS_THDH, wh) &&
      writeWord(VCNL4200_REG_ALS_THDL, wl) &&
      ALS_INT_EN(true))
    return true;
    
  return false;
}

boolean PRX_SD(boolean shutdown)
{
  return bitsUpdate(
    VCNL4200_REG_PRX_CONF,
    ~VCNL4200_PRX_SD,
    shutdown ? VCNL4200_PRX_SD : 0);
}

boolean PRX_INT(uint16_t prx_int)
{
  return bitsUpdate(
    VCNL4200_REG_PRX_CONF,
    ~VCNL4200_PRX_INT_MASK,
    prx_int << VCNL4200_PRX_INT_SHIFT);
}

boolean PRX_INT_with_threshold(uint16_t thdl, uint16_t thdh)
{
  if (PRX_INT(PRX_INT_DISABLE) &&
      writeWord(VCNL4200_REG_PRX_THDL, thdl) &&
      writeWord(VCNL4200_REG_PRX_THDH, thdh) &&
      PRX_INT(PRX_INT_BOTH))
    return true;
    
  return false;
}

boolean read_INT_FLAG(uint16_t *int_flag)
{
  return readWord(VCNL4200_REG_INT_FLAG, int_flag);
}

boolean set_PRX_LED_I(PRX_LED_I_t led_i)
{
  return bitsUpdate(
    VCNL4200_REG_PRX_CONF3,
    ~VCNL4200_PRX_LED_I_MASK,
    led_i << VCNL4200_PRX_LED_I_SHIFT);
}

PRX_LED_I_t get_PRX_LED_I(void)
{
  uint16_t conf3; 
  readWord(VCNL4200_REG_PRX_CONF3, &conf3);
  return (PRX_LED_I_t)(
    (conf3 & VCNL4200_PRX_LED_I_MASK) >> VCNL4200_PRX_LED_I_SHIFT);
}


boolean readWord(uint8_t reg, uint16_t *data)
{
  uint8_t   wd;

  _wire->beginTransmission(slaveAddress);
  if (_wire->write (reg) != 1)
    goto read_error;
  _wire->endTransmission(false);
  if (_wire->requestFrom(slaveAddress, (uint8_t)2) != 2)
    goto read_error;
  
  wd = 10;
  while (_wire->available()<2 && wd)
    wd--;
  if (!wd)
    goto read_error;
  
  *data = _wire->read();
  *data |= _wire->read() << 8;
  return true;

read_error:
  _wire->endTransmission(true);
  return false;
}

boolean writeWord(uint8_t reg, uint16_t data)
{
  boolean status = false;
  
  _wire->beginTransmission(slaveAddress);
  if (_wire->write(reg) &&
      _wire->write((uint8_t)(data & 0xFF)) &&
      _wire->write((uint8_t)((data >> 8) & 0xFF)))
    status = true;
  _wire->endTransmission(true);

  return status;
}

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println();

	_wire = &Wire;

  if (!begin())
  {
    Serial.println("Failed to initialize vcnl4200");
    while(1);
  }
  
  // Set IR LED current to 100mA
  set_PRX_LED_I(PRX_LED_I_50mA);

  Serial.println("PRX\tLux");
}


void loop()
{
  uint16_t prx;

  if (read_PRX(&prx))
  {
    Serial.print(prx);
    Serial.print('\t');
    Serial.println(get_lux());
  }

  delay(500);
}
