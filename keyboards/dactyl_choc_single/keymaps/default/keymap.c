#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _OTHER 3
#define _GAME 4

#define SYML LT(_SYML, KC_SPC)
#define SYMR MO(_SYMR)

#define ALT_H A(KC_HOME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		RESET   , KC_Q   , KC_W    , KC_E    , KC_R     , KC_T           ,         KC_Y       , KC_U     , KC_I   , KC_O   , KC_P     , RESET   , 
        KC_DEL  , KC_A   , KC_S    , KC_D    , KC_F     , KC_G           ,         KC_H       , KC_J     , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
        KC_LSFT , KC_Z   , KC_X    , KC_C    , KC_V     , KC_B           ,         KC_N       , KC_M     , KC_COMM, KC_DOT , KC_SLSH  , KC_RBRC , 
		                   KC_LALT , KC_LWIN , KC_TAB   , C(KC_LSFT)     ,         C(KC_LALT) , MO(_SYML), KC_LWIN, KC_LCTL,  
		                                       KC_LCTL  , SYML           ,         KC_LSFT    , KC_LALT  , 
		                                       KC_BSPC  , KC_ENT         ,         SYMR       , KC_ESC
	),

	[_SYMR] = KEYMAP(
	    KC_GRV , KC_2   , KC_3   , KC_4   , KC_5   , KC_6    ,         KC_7      , KC_8    , KC_9     , KC_0   , KC_MINS, KC_BSLS, 
		KC_1   , KC_2   , XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX ,         KC_LEFT   , KC_DOWN , KC_UP    , KC_RGHT, KC_MINS, KC_EQL , 
		KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC ,         KC_AMPR   , KC_ASTR , KC_LPRN  , KC_RPRN, KC_UNDS, KC_PLUS, 
	                      _______, _______, _______, _______ ,         TO(_GAME) , _______ , _______  , _______,  
		                                    _______, _______ ,         _______   , _______ , 
		                                    _______, _______ ,         _______   , KC_LSFT
	),
			
	[_SYML] = KEYMAP(
	    KC_MUTE , KC_VOLU , KC_HOME , KC_UP   , KC_END  , KC_PGUP   ,         _______ , _______ , _______ , _______ , _______ , _______ , 
		KC_PSCR , KC_VOLD , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN ,         _______ , _______ , _______ , _______ , _______ , _______ , 
		KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6     ,         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , 
		                    _______ , _______ , KC_SLEP , TO(_OTHER),         _______ , _______ , _______ , _______ ,  
		                                        _______ , _______   ,         _______ , _______ , 
		                                        _______ , _______   ,         _______ , _______
	), 

	[_OTHER] = KEYMAP(
	    _______ , A(KC_F4), KC_DEL  , KC_UP   , KC_TAB  , KC_PGUP    ,         KC_PSLS , KC_7        , KC_8    , KC_9    , KC_MINS , KC_EQL  ,
		_______ , C(KC_W) , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN  ,         KC_PAST , KC_4        , KC_5    , KC_6    , KC_PLUS , KC_NUBS , 
		_______ , _______ , KC_VOLD , KC_MUTE , KC_VOLU , _______    ,         KC_0    , KC_1        , KC_2    , KC_3    , KC_LPRN , KC_RPRN , 
		                    _______ , _______ , KC_APP  , TO(_QWERTY),         RESET   , MO(_QWERTY) , KC_PDOT , KC_PENT , 
		                                        _______ , _______    ,         KC_DOWN , KC_UP       , 
		                                        _______ , _______    ,         KC_LEFT , KC_RGHT
	),
	
	[_GAME] = KEYMAP(
	    _______ , _______ , _______ , _______ , _______ , _______ ,         _______     , _______ , _______ , _______ , _______ , _______ , 
		_______ , _______ , _______ , _______ , _______ , _______ ,         _______     , _______ , _______ , _______ , _______ , _______ , 
		_______ , _______ , _______ , _______ , _______ , _______ ,         _______     , _______ , _______ , _______ , _______ , _______ , 
		                    _______ , _______ , _______ , _______ ,         TO(_QWERTY) , _______ , _______ , _______ ,  
		                                        _______ , _______ ,         _______     , _______ , 
		                                        _______ , _______ ,         _______     , _______
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
        case ALT_H:
            return true;			
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_H:
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
	// state = update_tri_layer_state(state, _SYML, _SYMR, _SYM);
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
