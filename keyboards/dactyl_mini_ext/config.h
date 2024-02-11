#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// #define IGNORE_MOD_TAP_INTERRUPT
// #define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// #define TAPPING_FORCE_HOLD
// #define TAPPING_FORCE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


// LEDs
#define WS2812_DI_PIN F4
#define RGBLED_NUM 8

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS