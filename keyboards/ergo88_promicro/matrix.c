#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#include QMK_KEYBOARD_H

/* matrix state(1:on, 0:off) */
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values

//region using ProMicro pins
uint8_t read_mc(void) {
	return 	~((PINF&(1<<4) ? (1<<7) : 0) |
			(PINF&(1<<5) ? (1<<6) : 0) |
			(PINF&(1<<6) ? (1<<5) : 0) |
			(PINF&(1<<7) ? (1<<4) : 0) |
			(PINB&(1<<1) ? (1<<3) : 0) |
			(PINB&(1<<3) ? (1<<2) : 0) |
			(PINB&(1<<2) ? (1<<1) : 0) |
			(PINB&(1<<6) ? (1<<0) : 0));
}

void select_mc(uint8_t index) {
    // Output low(DDR:1, PORT:0) to select
    switch (index) {
        case 11:
            setPinOutput(D4);
            writePinLow(D4);
            break;
        case 10:
            setPinOutput(C6);
            writePinLow(C6);
            break;
        case 9:
            setPinOutput(D7);
            writePinLow(D7);
            break;
        case 8:
            setPinOutput(E6);
            writePinLow(E6);
            break;
        case 7:
            setPinOutput(B4);
            writePinLow(B4);
            break;
        case 6:
            setPinOutput(B5);
            writePinLow(B5);
            break;
    }
}

void unselect_mc(void) {
	setPinInput(D4);
    setPinInput(C6);
    setPinInput(D7);
    setPinInput(E6);
    setPinInput(B4);
    setPinInput(B5);
}


void mc_init(void) {
	unselect_mc();
	
	setPinInputHigh(F4);
    setPinInputHigh(F5);
    setPinInputHigh(F6);
    setPinInputHigh(F7);
    setPinInputHigh(B1);
    setPinInputHigh(B3);
    setPinInputHigh(B2);
    setPinInputHigh(B6);
}


// custom matrix
void matrix_init_custom(void) {
    // TODO: initialize hardware and global matrix state here
    mc_init();
    i2c_initialize();

    for(uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i] = 0;
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) { 
    bool changed = false;
      
	matrix_row_t current_row = 0;
	
    for(uint8_t i = 0; i < MATRIX_ROWS; i++) {
		//phex(i);
		if(i < 6) {
			// left
			
			i2c_select_regB_on(I2CA_ADDRESS, i);
			
			current_row = i2c_read_regA_on(I2CA_ADDRESS);
			
			i2c_unselect_regB_on(I2CA_ADDRESS);
		} else {
			// right
			
			select_mc(i);
			
			current_row = read_mc();
			
			unselect_mc();
		}
		
		if(current_row != raw_matrix[i]) {
            raw_matrix[i] = current_row;
            changed = true;
        } 
		
        current_row = 0;
    }  
    
    return changed;
}


// DO NOT REMOVE
// Needed for proper wake/sleep
void matrix_power_up(void) {
    mc_init();
    i2c_initialize();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

}