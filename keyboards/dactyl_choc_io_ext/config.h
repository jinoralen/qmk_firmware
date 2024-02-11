#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

/* USB Device descriptor parameter */
//#define MANUFACTURER    tshort
// defined in subfolder

/* mouse config */

/* Set 0 if debouncing isn't needed */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define WS2812_DI_PIN D5 
#define RGBLED_NUM 20

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS

// SPI_SCK_PIN B1
// SPI_MOSI_PIN B2
// SPI_MISO_PIN B3
#define ADNS9800_CS_PIN B6