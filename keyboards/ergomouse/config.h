#pragma once

#include "config_common.h"
#define PRODUCT ERGOMOUSe

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
//#define MANUFACTURER    tshort
// defined in subfolder
#define DESCRIPTION     A ergo mouse

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

#define MATRIX_COL_PINS { B4 }
#define MATRIX_ROW_PINS { B5 }

#define DIODE_DIRECTION COL2ROW

// SPI_SCK_PIN B1
// SPI_MOSI_PIN B2
// SPI_MISO_PIN B3
#define ADNS9800_CS_PIN B6

#define ANALOG_JOYSTICK_X_AXIS_PIN F4
#define ANALOG_JOYSTICK_Y_AXIS_PIN F5
#define ANALOG_JOYSTICK_CLICK_PIN F6