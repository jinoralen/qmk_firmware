#pragma once

#include "config_common.h"
#define PRODUCT Ergo88

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 8

// wiring of each half
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5, F4 }
#define MATRIX_ROW_PINS { B5, B4, E6, D7, C6, D4 }

#define DIODE_DIRECTION COL2ROW

/* Select hand configuration */
//#define MASTER_LEFT
#define MASTER_RIGHT
//#define EE_HANDS

/* serial.c configuration for split keyboard */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D0

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
//#define MANUFACTURER    tshort
// defined in subfolder
#define DESCRIPTION     A split keyboard

/* mouse config */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 38    // Number of LEDs
#define RGBLED_SPLIT {19, 19}

#define TAPPING_TERM 200

#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT5

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
