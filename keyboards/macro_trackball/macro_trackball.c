#include "macro_trackball.h"
#include <avr/interrupt.h>
#include "pointing_device.h"
#include "print.h"

// Multiple for mouse moves
#ifndef TRKSTEP
#define TRKSTEP 20
#endif

// multiple for mouse scroll
#ifndef SCROLLSTEP
#define SCROLLSTEP 5
#endif

// Trackball interrupts accumulate over here. Processed on scan
// Stores prev state of mouse, high bits store direction
uint8_t trkState    = 0;
uint8_t trkBtnState = 0;

volatile uint8_t tbUpCnt  = 0;
volatile uint8_t tbDnCnt  = 0;
volatile uint8_t tbLtCnt  = 0;
volatile uint8_t tbRtCnt  = 0;

volatile uint8_t upState  = 0;
volatile uint8_t downState = 0;
volatile uint8_t leftState = 0;
volatile uint8_t rightState = 0;


void keyboard_pre_init_kb(void) {
    setPinInput(B6);
	setPinInput(B2);
	setPinInput(B3);
	setPinInput(B1);

    keyboard_pre_init_user();
}

void matrix_init_kb(void) {

	matrix_init_user();
};

void matrix_scan_kb(void) {
    uint8_t right = readPin(B6);
	uint8_t left = readPin(B2);
	uint8_t up = readPin(B3);
	uint8_t down = readPin(B1);
	
	if(upState != up) tbUpCnt++;
	if(downState != down) tbDnCnt++;
	if(leftState != left) tbLtCnt++;
	if(rightState != right) tbRtCnt++;
	
	 // Modify the report
    report_mouse_t pRprt = pointing_device_get_report();
	
    pRprt.x -= tbLtCnt * TRKSTEP; tbLtCnt = 0;
    pRprt.x += tbRtCnt * TRKSTEP; tbRtCnt = 0;
    pRprt.y -= tbUpCnt * TRKSTEP; tbUpCnt = 0;
	pRprt.y += tbDnCnt * TRKSTEP; tbDnCnt = 0;
    
	// Save state, push update
    if (pRprt.x != 0 || pRprt.y != 0 || pRprt.h != 0 || pRprt.v != 0)
        pointing_device_set_report(pRprt);
	
	upState = up;
	leftState = left;
	downState = down;
	rightState = right;
	
	// Ensure any user customizations are called (for some reason this wasn't happening by default)
    matrix_scan_user();
}