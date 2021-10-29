#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _OTHER 3
#define _GAME 4

#define SYML LT(_SYML, KC_SPC)
#define SYMR MO(_SYMR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		KC_BRK        , KC_GRV , KC_2 , KC_3 , KC_4   , KC_5   , KC_6   , KC_MUTE,         KC_PSCR, KC_7 , KC_8   , KC_9   , KC_0  , KC_MINS, KC_EQL , KC_BSPC, 
		KC_ESC        , KC_1   , KC_Q , KC_W , KC_E   , KC_R   , KC_T   , KC_LPRN,         KC_HOME, KC_Y , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC, KC_BSLS, 
		LSFT_T(KC_ENT), KC_DEL , KC_A , KC_S , KC_D   , KC_F   , KC_G   , KC_RPRN,         KC_END , KC_H , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT, KC_ENT , 
		KC_LALT       , KC_LWIN, KC_Z , KC_X , KC_C   , KC_V   , KC_B   , KC_TAB ,         KC_LWIN, KC_N , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, KC_INS , 
		KC_LCTL       , KC_F1  , KC_F2, KC_F3, KC_F4  , KC_F5  , KC_F6  , KC_APP ,         KC_ESC , KC_F7, KC_F8  , KC_F9  , KC_F10, KC_F11 , KC_F12 , KC_LWIN, 
		                                       KC_LCTL, SYML   , KC_ENT , KC_BSPC,         KC_ESC , SYMR , KC_LSFT, KC_LALT
	),
	

	[_SYMR] = KEYMAP(
		_______, _______, _______, _______, _______, _______, _______, _______,     _______  , _______, _______, _______, _______, _______, _______, XXXXXXX,
		_______, KC_GRV , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , _______,     _______  , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX,
		_______, KC_1   , KC_2   , XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, _______,     _______  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_MINS, KC_EQL , XXXXXXX, 
		_______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, _______,     TO(_GAME), KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, XXXXXXX, 
		_______, _______, _______, _______, _______, _______, _______, _______,     XXXXXXX  , _______, _______, _______, _______, _______, _______, XXXXXXX, 
				                            KC_LCTL, KC_LSFT, KC_LALT, KC_LWIN,     XXXXXXX  , _______, XXXXXXX, XXXXXXX
	),
			
	[_SYML] = KEYMAP(
		_______, _______, _______, _______, _______, _______, _______, _______   ,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, KC_VOLU   ,     _______, _______, _______, _______, _______, _______, _______, _______,  
		KC_ENT , _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_VOLD   ,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , TO(_OTHER),     _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,  
		_______, _______, _______, _______, _______, _______, _______, XXXXXXX   ,     _______, _______, _______, _______, _______, _______, _______, _______, 
				                            KC_SLEP, _______, _______, XXXXXXX   ,     KC_LWIN, KC_LCTL, KC_LSFT, KC_LALT
	),
	

	[_OTHER] = KEYMAP(
		KC_SLEP, KC_ESC , _______ , _______, _______, _______, _______   , _______    ,     _______, _______, _______, _______, _______, _______, _______, RESET   ,
		XXXXXXX, _______, A(KC_F4), KC_DEL , KC_UP  , KC_TAB , KC_PGUP   , KC_VOLU    ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P ,
		XXXXXXX, _______, C(KC_W) , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN , KC_VOLD    ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD ,
		XXXXXXX, _______, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , TO(_QWERTY),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,
		XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , KC_APP     ,     XXXXXXX, RGB_HUI, RGB_HUI, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_TOG ,
		                                     KC_LCTL, KC_SPC , KC_ENT    , KC_BSPC    ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT   
	),	
	
	[_GAME] = KEYMAP(
		XXXXXXX, KC_GRV , KC_2     , KC_3   , KC_4   , KC_5   , KC_6   , _______,     _______    , _______, _______, _______, _______, _______, _______, _______,
		KC_VOLU, KC_1   , KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		KC_VOLD, KC_DEL , KC_LSFT  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		XXXXXXX, KC_LALT, KC_LCTL  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     TO(_QWERTY), _______, _______, _______, _______, _______, _______, _______,
		XXXXXXX, _______, _______  , _______, _______, _______, _______, KC_APP ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		                                      KC_ESC , KC_SPC , KC_ENT , KC_BSPC,     KC_LEFT    , KC_DOWN, KC_UP  , KC_RGHT   
	),	
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SYML:
            return true;					
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYML:
            return true;			
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return true;			
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return 370;
		case SYML:
            return 270;	
        default:
            return TAPPING_TERM;
    }
}
	
#ifdef RGBLIGHT_ENABLE

void keyboard_pre_init_user(void) {
   	rgblight_disable_noeeprom();
}

void keyboard_post_init_user(void) {
	rgblight_sethsv_noeeprom(HSV_BLUE);
    rgblight_mode_noeeprom(23);
	rgblight_disable_noeeprom();
}

#endif // RGBLIGHT_ENABLE

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
        case _QWERTY:
	        rgblight_disable_noeeprom();
            break;
        case _SYML:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(34);
			rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _SYMR:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(25);
			rgblight_sethsv_noeeprom(HSV_GREEN);
            break;

        case _OTHER: 
			rgblight_sethsv_noeeprom(HSV_BLUE);
	        rgblight_enable_noeeprom();
			rgblight_sethsv_noeeprom(HSV_BLUE);
            rgblight_mode_noeeprom(2);
			rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
	    case _GAME: 
			rgblight_sethsv_noeeprom(HSV_GREEN);
	        rgblight_enable_noeeprom();
			rgblight_sethsv_noeeprom(HSV_GREEN);
            rgblight_mode_noeeprom(2);
			rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
    }
	rgblight_set();
#endif // RGBLIGHT_ENABLE
    return state;
}
