#include "dactyl_mini_ext.h"

static i2c_status_t last_err = 0;
bool i2c_initialized = false;

void config_on(uint8_t addr) {
    // config all A as inputs, B by default as outputs
	i2c_write8(addr, EXPANDER_REG_IODIRA, 0b11111111);
	i2c_write8(addr, EXPANDER_REG_IODIRB, 0b00000000);
	
	// enable pullups for inputs
	i2c_write8(addr, EXPANDER_REG_GPPUA, 0b11111111);
    i2c_write8(addr, EXPANDER_REG_GPPUB, 0b00000000);
}

void i2c_initialize(void){
    print("I2C init start\n");
     
    if(!i2c_initialized) {
        i2c_init();
        i2c_initialized = true;
    }
	
	config_on(I2CA_ADDRESS);

    if(i2c_last_error()) {
        print("Unable to setup left side!\n");
    }else {
        print("Left side OK!\n");
    }
}  

bool isI2C_initialized() {
    return i2c_initialized;
}

uint8_t i2c_read8(uint8_t addr, uint8_t reg) {
    uint8_t data = 0;
    
    last_err = i2c_read_register(addr, reg, &data, sizeof(data), I2C_TIMEOUT); 

    return ~data;

}

void i2c_write8(uint8_t addr, uint8_t reg, uint8_t data) {
    last_err = i2c_write_register(addr, reg, &data, sizeof(data), I2C_TIMEOUT);
}

i2c_status_t i2c_last_error(void) {
    return last_err;
}

// important stuff
uint8_t i2c_read_regA_on(uint8_t addr) {
	return i2c_read8(addr, EXPANDER_REG_GPIOA);
}

void i2c_select_regB_on(uint8_t addr, uint8_t index) {
    i2c_write8(addr, EXPANDER_REG_GPIOB, 0xFF & ~(1 << index));
} 

void i2c_unselect_regB_on(uint8_t addr) {
    i2c_write8(addr, EXPANDER_REG_GPIOB, 0xFF & ~(0<<7));
}
