#pragma once

#include "config_common.h"
#define PRODUCT Macropad

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { B4, B5, B2, B6, C6, F7 }
#define MATRIX_ROW_PINS { B3, B1, E6, D7, D4, F6 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { D1, F5 }
#define ENCODERS_PAD_B { D0, F4 }

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
//#define MANUFACTURER    tshort
// defined in subfolder
#define DESCRIPTION     Macropad

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
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define TAPPING_FORCE_HOLD

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLED_NUM 8    // Number of LEDs