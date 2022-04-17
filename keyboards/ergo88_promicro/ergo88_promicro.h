#pragma once

#include "quantum.h"

#include "i2c_master.h"

/* I2C expander config */
#define I2CA_ADDRESS 0b0100111 << 1

#define I2C_TIMEOUT 1000

enum EXPANDER_REG_BANK0 {
  EXPANDER_REG_IODIRA = 0,
  EXPANDER_REG_IODIRB,
  EXPANDER_REG_IPOLA,
  EXPANDER_REG_IPOLB,
  EXPANDER_REG_GPINTENA,
  EXPANDER_REG_GPINTENB,
  EXPANDER_REG_DEFVALA,
  EXPANDER_REG_DEFVALB,
  EXPANDER_REG_INTCONA,
  EXPANDER_REG_INTCONB,
  EXPANDER_REG_IOCONA,
  EXPANDER_REG_IOCONB,
  EXPANDER_REG_GPPUA,
  EXPANDER_REG_GPPUB,
  EXPANDER_REG_INTFA,
  EXPANDER_REG_INTFB,
  EXPANDER_REG_INTCAPA,
  EXPANDER_REG_INTCAPB,
  EXPANDER_REG_GPIOA,
  EXPANDER_REG_GPIOB,
  EXPANDER_REG_OLATA,
  EXPANDER_REG_OLATB
};

void i2c_initialize(void);
bool isI2C_initialized(void);

void i2c_write8(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t i2c_read8(uint8_t addr, uint8_t reg);

i2c_status_t i2c_last_error(void);

uint8_t i2c_read_regA_on(uint8_t addr);
void i2c_select_regB_on(uint8_t addr, uint8_t index);
void i2c_unselect_regB_on(uint8_t addr);


#define KEYMAP(\
    L00, L01, L02, L03, L04, L05, L06, L07,      R07, R06, R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15, L16, L17,      R17, R16, R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25, L26, L27,      R27, R26, R25, R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35, L36, L37,      R37, R36, R35, R34, R33, R32, R31, R30, \
    L40, L41, L42, L43, L44, L45, L46, L47,      R47, R46, R45, R44, R43, R42, R41, R40, \
                        L54, L55, L56, L57,      R57, R56, R55, R54                      \
    )\
    {\
        { L00, L01, L02, L03, L04, L05, L06, L07 },    \
        { L10, L11, L12, L13, L14, L15, L16, L17 },    \
        { L20, L21, L22, L23, L24, L25, L26, L27 },    \
        { L30, L31, L32, L33, L34, L35, L36, L37 },    \
        { L40, L41, L42, L43, L44, L45, L46, L47 },    \
{ KC_NO, KC_NO, KC_NO, KC_NO, L54, L55, L56, L57 },    \
\
        { R00, R01, R02, R03, R04, R05, R06, R07 },    \
        { R10, R11, R12, R13, R14, R15, R16, R17 },    \
        { R20, R21, R22, R23, R24, R25, R26, R27 },    \
        { R30, R31, R32, R33, R34, R35, R36, R37 },    \
        { R40, R41, R42, R43, R44, R45, R46, R47 },    \
{ KC_NO, KC_NO, KC_NO, KC_NO, R54, R55, R56, R57 }     \
}
