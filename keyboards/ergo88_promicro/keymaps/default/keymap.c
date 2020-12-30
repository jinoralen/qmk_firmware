#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2
#define _SYM 3

#define _OTHER 4
#define _GAME 5

#define _FN 6

#define FN(mod) LM(_FN, mod)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		KC_BRK        , KC_GRV , KC_2   , KC_3   , KC_4   , KC_5   , KC_6     , KC_MUTE,         KC_PSCR  , KC_7     , KC_8   , KC_9   , KC_0  , KC_MINS, KC_EQL , KC_BSPC   , 
		KC_ESC        , KC_1   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T     , KC_LPRN,         KC_HOME  , KC_Y     , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC, KC_BSLS   , 
		LSFT_T(KC_ENT), KC_DEL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G     , KC_RPRN,         KC_END   , KC_H     , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT, KC_ENT    , 
		KC_LALT       , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B     , KC_TAB ,         KC_LWIN  , KC_N     , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, KC_INS    , 
		C(KC_LSFT)    , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6    , KC_APP ,         G(KC_TAB), KC_F7    , KC_F8  , KC_F9  , KC_F10, KC_F11 , KC_F12 , C(KC_LALT), 
		                                           KC_LCTL, KC_SPC , MO(_SYML), KC_BSPC,         KC_ESC   , MO(_SYMR), KC_LSFT, KC_LALT
	),

	[_SYMR] = KEYMAP(
		_______     , KC_1        , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , _______,     _______  , KC_7      , KC_8      , KC_9      , KC_0      , KC_MINS   , KC_EQL    , XXXXXXX,
		_______     , S(KC_1)     , S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______,     _______  , S(KC_7)   , S(KC_8)   , S(KC_9)   , S(KC_0)   , S(KC_MINS), S(KC_EQL) , XXXXXXX,
		FN(MOD_LSFT), KC_DEL      , KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL , _______,     _______  , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , KC_MINS   , KC_EQL    , XXXXXXX, 
		FN(MOD_LALT), FN(MOD_LCTL), KC_LT  , _______, _______, _______, _______, _______,     TO(_GAME), S(KC_LEFT), S(KC_DOWN), S(KC_UP)  , S(KC_RGHT), KC_GT     , KC_COLN   , XXXXXXX, 
		_______     , _______     , _______, _______, _______, _______, _______, _______,     XXXXXXX  , _______   , _______   , _______   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX, 
				                                      _______, _______, _______, _______,     XXXXXXX  , _______   , XXXXXXX   , XXXXXXX
	),
			
	[_SYML] = KEYMAP(
		XXXXXXX, KC_F1  , KC_F2  , KC_F3     , KC_F4     , KC_F5    , KC_F6     , _______   ,     _______, KC_F7  , KC_F8  , KC_F9     , KC_F10   , KC_F11    , KC_F12    , _______   , 
		XXXXXXX, KC_ESC , KC_TAB , KC_HOME   , KC_UP     , KC_END   , KC_PGUP   , KC_VOLU   ,     _______, S(KC_Y), S(KC_U), S(KC_I)   , S(KC_O)  , S(KC_P)   , S(KC_LBRC), S(KC_BSLS),  
		KC_ENT , KC_DEL , KC_LSFT, KC_LEFT   , KC_DOWN   , KC_RGHT  , KC_PGDOWN , KC_VOLD   ,     _______, S(KC_H), S(KC_J), S(KC_K)   , S(KC_L)  , S(KC_SCLN), S(KC_QUOT), _______   , 
		XXXXXXX, KC_LALT, KC_LWIN, C(KC_LEFT), C(KC_DOWN), C(KC_UP) , C(KC_RGHT), TO(_OTHER),     _______, S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RBRC), _______   ,  
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , A(KC_TAB) , G(KC_TAB), C(KC_TAB) , XXXXXXX   ,     _______, _______, _______, _______   , _______  , _______   , _______   , _______   , 
				                               XXXXXXX   , XXXXXXX  , _______   , XXXXXXX   ,     KC_LWIN, _______, KC_LSFT, KC_LALT
	), 
	
	[_SYM] = KEYMAP(
	    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, KC_PAST, KC_7   , KC_8   , KC_9   , KC_PMNS, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, KC_EQL , KC_4   , KC_5   , KC_6   , KC_ENT , _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, KC_PSLS, KC_1   , KC_2   , KC_3   , KC_PPLS, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_0   , KC_DOT , _______, _______, _______, _______, 
				                            _______, _______, _______, _______,     _______, _______, _______, _______
	),

	[_OTHER] = KEYMAP(
		KC_SLEP, KC_ESC , _______ , _______, _______, _______, _______   , _______    ,     _______, _______, _______, _______, _______, _______, _______, RESET   ,
		XXXXXXX, _______, A(KC_F4), KC_DEL , KC_UP  , KC_BSPC, KC_PGUP   , KC_VOLU    ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P ,
		XXXXXXX, KC_LSFT, C(KC_W) , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN , KC_VOLD    ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD ,
		XXXXXXX, KC_LALT, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , TO(_QWERTY),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD,
		XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , KC_APP     ,     XXXXXXX, RGB_HUI, RGB_HUI, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_TOG ,
		                                     KC_LCTL, KC_SPC , KC_ENT    , KC_TAB     ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT   
	),	
	
	[_GAME] = KEYMAP(
		XXXXXXX, KC_GRV , KC_2     , KC_3   , KC_4   , KC_5   , KC_6     , _______,     _______    , _______, _______, _______, _______, _______, _______, _______,
		KC_VOLU, KC_1   , KC_TAB   , KC_Q   , KC_W   , KC_E   , KC_R     , KC_T   ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		KC_VOLD, KC_DEL , KC_LSFT  , KC_A   , KC_S   , KC_D   , KC_F     , KC_G   ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		XXXXXXX, KC_LALT, KC_LCTL  , KC_Z   , KC_X   , KC_C   , KC_V     , KC_B   ,     TO(_QWERTY), _______, _______, _______, _______, _______, _______, _______,
		XXXXXXX, _______, _______  , _______, _______, _______, _______  , KC_APP ,     _______    , _______, _______, _______, _______, _______, _______, _______,
		                                      KC_ESC , KC_SPC , KC_ENT   , KC_BSPC,     KC_LEFT    , KC_DOWN, KC_UP  , KC_RGHT   
	),	
	
	[_FN] = KEYMAP(
	    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , _______,     _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
				                            _______, _______, _______, _______,     _______, _______, _______, _______
	),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
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
	state = update_tri_layer_state(state, _SYML, _SYMR, _SYM);
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
		case _SYM:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(42);
			rgblight_sethsv_noeeprom(HSV_RED);
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
        case _FN:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(14);
			rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
	rgblight_set();
#endif // RGBLIGHT_ENABLE
    return state;
}
