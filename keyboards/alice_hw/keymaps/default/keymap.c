#include QMK_KEYBOARD_H

#define _QWERTY 0

#define S_UP    MT(MOD_LGUI, KC_UP)
#define S_DOWN  MT(MOD_LALT, KC_DOWN)

#define S_LEFT  MT(MOD_LGUI, KC_LEFT)
#define S_RIGHT MT(MOD_LALT, KC_RGHT)

#define S_HOME  MT(MOD_MEH, KC_HOME)
#define S_END   MT(MOD_LGUI, KC_END)

#define S_ESC   MT(MOD_LALT, KC_ESC)

#define MT_TAB  MT(MOD_LSFT, KC_TAB)
#define MT_RBRC MT(MOD_LSFT, KC_RBRC)
#define MT_F1   MT(MOD_LSFT, KC_F1)
#define MT_F12  MT(MOD_LSFT, KC_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_PGUP,  KC_ESC , KC_1    , KC_2    , KC_3      , KC_4    , KC_5       , KC_6          , KC_7   , KC_8   , KC_9   , KC_0     , KC_MINS, KC_EQL   , KC_BSPC ,
        KC_GRV  , KC_TAB , KC_Q    , KC_W    , KC_E      , KC_R    , KC_T                       , KC_Y   , KC_U   , KC_I   , KC_O     , KC_P   , KC_LBRC  , KC_RBRC , KC_BSLS ,
        QK_BOOT , KC_DEL , KC_A    , KC_S    , KC_D      , KC_F    , KC_G                       , KC_H   , KC_J   , KC_K   , KC_L     , KC_SCLN, KC_QUOT  , KC_ENT  ,
        MT_TAB  , KC_LSFT, KC_Z    , KC_X    , KC_C      , KC_V    , KC_B                       , KC_B   , KC_N   , KC_M   , KC_COMM  , KC_DOT , KC_SLSH  , KC_LSFT , KC_UP   ,  KC_DEL, 
	    KC_PGDN , KC_LCTL, KC_LALT , KC_LGUI , KC_SPC    , S_END                                , KC_SPC , KC_LGUI, KC_LALT, KC_LCTL, KC_LEFT  , KC_DOWN , KC_RGHT
	),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	// define keys that should be handle as modifiers after pressing some other keys withing tap term
    switch (keycode) {
		case S_ESC:
		case MT_TAB:
		case MT_RBRC:
        case MT_F1:
        case MT_F12:
		case S_HOME:
		case S_END:

		case S_UP:
		case S_DOWN:
		case S_LEFT:
		case S_RIGHT:
            return true;

        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_TAB:
        case MT_RBRC:
        case MT_F1:
        case MT_F12:
            return true;

        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}