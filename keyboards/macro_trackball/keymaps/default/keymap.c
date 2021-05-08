#include QMK_KEYBOARD_H

#define _NUMPAD 0
#define _MEDIA 1
#define _SETTINGS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUMPAD] = KEYMAP(
		  KC_MUTE,                             KC_NUMLOCK, 
          KC_P7, KC_P8  , KC_P9                 , KC_PSLS, 
          KC_P4, KC_P5  , KC_P6                 , KC_PAST, 
          KC_P1, KC_P2  , KC_P3                 , KC_PPLS, 
          KC_P0, KC_PDOT, LT(_SETTINGS, KC_PENT), KC_PMNS 
	),
	
	[_MEDIA] = KEYMAP(
		  _______ ,                                   _______  , 
          KC_ESC  , C(KC_C) , C(KC_X)               , C(KC_V)  , 
          KC_DEL  , KC_UP   , KC_TAB                , KC_PGUP  , 
          KC_LEFT , KC_DOWN , KC_RGHT               , KC_PGDOWN, 
          KC_LALT , KC_SPC  , LT(_SETTINGS, KC_ENT) , KC_LWIN 
	),
	
	[_SETTINGS] = KEYMAP(
		  _______    ,                       _______, 
          C(KC_W)     , A(KC_F4)  , _______ , RESET  , 
          _______    , _______   , _______ , _______, 
          _______    , _______   , _______ , _______, 
          TO(_NUMPAD), TO(_MEDIA), _______ , _______ 
	),
};

