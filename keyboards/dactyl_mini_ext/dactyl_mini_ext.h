#pragma once

#include <stdint.h>
#include <stdbool.h>
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