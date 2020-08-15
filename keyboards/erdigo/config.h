#pragma once

#include "config_common.h"
#define PRODUCT erdigo

/* key matrix size */
#define MATRIX_ROWS 9 
#define MATRIX_COLS 8

// wiring 
#define MATRIX_COL_PINS { F6, F7, B6, B5, B4, D7, D6, D4 }
#define MATRIX_ROW_PINS { B0, B1, B2, B3, B7, D2, C6, C7, D5 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { F5, F0 }
#define ENCODERS_PAD_B { F4, F1 }

#define RGB_DI_PIN D3

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define DESCRIPTION     Ergonomic keyboard

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
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLED_NUM 38    // Number of LEDs
#define RGBLED_SPLIT {19, 19}

#define TAPPING_TERM 200

#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY