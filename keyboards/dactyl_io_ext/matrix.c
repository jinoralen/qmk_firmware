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
	return 	~((PIND&(1<<4) ? (1<<0) : 0) |
			(PINC&(1<<6) ? (1<<1) : 0) |
			(PIND&(1<<7) ? (1<<2) : 0) |
			(PINE&(1<<6) ? (1<<3) : 0) |
			(PINB&(1<<4) ? (1<<4) : 0) |
			(PINB&(1<<5) ? (1<<5) : 0));
}

void select_mc(uint8_t index) {
    // Output low(DDR:1, PORT:0) to select
    switch (index) {
        case 7:
            setPinOutput(F5);
            writePinLow(F5);
            break;
        case 8:
            setPinOutput(F6);
            writePinLow(F6);
            break;
        case 9:
            setPinOutput(F7);
            writePinLow(F7);
            break;
        case 10:
            setPinOutput(B1);
            writePinLow(B1);
            break;
        case 11:
            setPinOutput(B3);
            writePinLow(B3);
            break;
        case 12:
            setPinOutput(B2);
            writePinLow(B2);
            break;
        case 13:
            setPinOutput(B6);
            writePinLow(B6);
            break;
    }
}

void unselect_mc(void) {
	setPinInput(F5);
    setPinInput(F6);
    setPinInput(F7);
    setPinInput(B1);
    setPinInput(B3);
    setPinInput(B2);
    setPinInput(B6);
}


void mc_init(void) {
	unselect_mc();
	
	setPinInputHigh(D4);
    setPinInputHigh(C6);
    setPinInputHigh(D7);
    setPinInputHigh(E6);
    setPinInputHigh(B4);
    setPinInputHigh(B5);
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
		if(i < 7) {
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
