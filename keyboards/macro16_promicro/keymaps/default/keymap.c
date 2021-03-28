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
		  KC_MUTE ,                                   _______  , 
          KC_ESC  , A(KC_F4), C(KC_W)               , _______  , 
          KC_DEL  , KC_UP   , KC_TAB                , KC_PGUP  , 
          KC_LEFT , KC_DOWN , KC_RGHT               , KC_PGDOWN, 
          _______ , KC_SPC  , LT(_SETTINGS, KC_ENT) , KC_LWIN 
	),
	
	[_SETTINGS] = KEYMAP(
		  _______    ,                       _______, 
          _______    , _______   , _______ , RESET  , 
          _______    , _______   , _______ , _______, 
          _______    , _______   , _______ , _______, 
          TO(_NUMPAD), TO(_MEDIA), _______ , _______ 
	),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {	
        case LT(_SETTINGS, KC_PENT):
            return true;	
	    case LT(_SETTINGS, KC_ENT):
            return true;	
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LT(_SETTINGS, KC_PENT):
            return true;
		case LT(_SETTINGS, KC_ENT):
            return true;	
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SETTINGS, KC_PENT):
            return 370;		
		case LT(_SETTINGS, KC_ENT):
            return 370;		
        default:
            return TAPPING_TERM;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
        case _NUMPAD:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(2);
	        rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _MEDIA:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(42);
			rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case _SETTINGS:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(25);
			rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
    }
	rgblight_set();
#endif // RGBLIGHT_ENABLE
    return state;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
    	if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDOWN);
        }
    }
}

#endif

#ifdef RGBLIGHT_ENABLE

void keyboard_pre_init_user(void) {
   	rgblight_disable_noeeprom();
}

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(2);
	rgblight_sethsv_noeeprom(HSV_RED);
}

#endif // RGBLIGHT_ENABLE
