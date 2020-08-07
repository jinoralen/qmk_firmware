#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _SYM 1

#define _OTHER 2
#define _RGB 3

#define CS(kc) MT(MOD_LCTL | MOD_LSFT, kc)
#define CA(kc) MT(MOD_LCTL | MOD_LALT, kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		KC_ESC , KC_GRV    , KC_2     , KC_3         , KC_4          , KC_5          , KC_6          , TG(_OTHER)   ,                    TO(_QWERTY), KC_7      , KC_8            , KC_9          , KC_0          , KC_MINS, KC_EQL , KC_DELETE, 
		KC_TAB , KC_1      , KC_Q     , KC_W         , KC_E          , KC_R          , KC_T          , KC_PGUP      ,                    KC_HOME    , KC_Y      , KC_U            , KC_I          , KC_O          , KC_P   , KC_LBRC, KC_BSPC  , 
		KC_VOLU, KC_DEL    , KC_A     , KC_S         , KC_D          , KC_F          , KC_G          , KC_PGDOWN    ,                    KC_END     , KC_H      , KC_J            , KC_K          , KC_L          , KC_SCLN, KC_QUOT, KC_ENT   , 
		KC_VOLD, KC_TAB    , KC_Z     , KC_X         , KC_C          , KC_V          , KC_B          , KC_LALT      ,                    KC_RALT    , KC_N      , KC_M            , KC_COMM       , KC_DOT        , KC_SLSH, KC_RBRC, KC_BSLS  , 
		KC_MUTE, CS(KC_F1) , CA(KC_F2), LALT_T(KC_F3), LCTL_T(KC_F4) , LSFT_T(KC_F5) , KC_F6         , KC_LWIN      ,                    KC_APP     , KC_F7     , LSFT_T(KC_F8)   , RCTL_T(KC_F9) , LALT_T(KC_F10), KC_F11 , KC_F12 , KC_PSCR  , 
		                                               KC_LCTL       , KC_SPC        , KC_ENT        , KC_BSPC      ,                    KC_ESC     , MO(_SYM)  , KC_RSFT         , KC_RCTL
	),
	[_SYM] = KEYMAP(
		_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , _______,     _______, KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11   , KC_F12 , _______,
		_______, _______, KC_HASH, KC_DLR , KC_LCBR, KC_RCBR, KC_MINS, KC_ASTR,     KC_BRK , KC_HOME   , C(KC_LEFT), C(KC_RGHT), KC_END    , KC_PGUP  , _______, _______,
		_______, _______, KC_PERC, KC_UNDS, KC_LPRN, KC_RPRN, KC_EQL , KC_CIRC,     KC_INS , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , KC_PGDOWN, _______, _______, 
		_______, _______, KC_AMPR, KC_PIPE, KC_LT  , KC_GT  , KC_PLUS, KC_SLSH,     _______, S(KC_LEFT), S(KC_DOWN), S(KC_UP)  , S(KC_RGHT), KC_DEL   , _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______   , _______   , _______   , _______   , _______  , _______, _______, 
				                            KC_LCTL, KC_LSFT, KC_LALT, _______,     _______, _______   , _______   , _______
	),
	
	[_OTHER] = KEYMAP(
		KC_SLEP, _______      , _______  , _______, _______, _______, _______  , _______,     _______, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, RESET  ,
		XXXXXXX, _______      , A(KC_F4) , KC_DEL , KC_UP  , KC_BSPC, KC_PGUP  , KC_VOLU,     XXXXXXX, XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, XXXXXXX, XXXXXXX, 
		XXXXXXX, OSM(MOD_LSFT), C(KC_W)  , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN, KC_VOLD,     XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, OSM(MOD_LCTL), XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , KC_MUTE,     XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, _______      , _______  , _______, _______, _______, _______  , KC_APP ,     XXXXXXX, XXXXXXX, KC_P0  , KC_PDOT, KC_PENT, XXXXXXX, XXXXXXX, TG(_RGB),
		                                            KC_ESC , KC_SPC , KC_ENT   , KC_TAB ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT   
	),	
	[_RGB] = KEYMAP(
		RGB_TOG         , RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_T, XXXXXXX,     _______, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, XXXXXXX, XXXXXXX,
		RGB_MODE_REVERSE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		RGB_MODE_REVERSE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX         , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX         , RGB_HUI, RGB_HUI, RGB_SAI, RGB_SAD , RGB_VAI , RGB_VAI, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		                                             KC_LCTL , KC_LSFT , KC_LALT, XXXXXXX,     _______, _______, _______, _______                     
	)
};


#ifdef RGBLIGHT_ENABLE

void keyboard_pre_init_user(void) {
   	rgblight_disable_noeeprom();
}

void keyboard_post_init_user(void) {
	rgblight_sethsv_noeeprom(HSV_BLUE);
    rgblight_mode_noeeprom(23);
	rgblight_disable_noeeprom();
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _QWERTY:
	        rgblight_disable_noeeprom();
            break;
        case _SYM:
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
        case _RGB:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(14);
			rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
	rgblight_set();

    return state;
}

#endif // RGBLIGHT_ENABLE

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case LALT_T(KC_F3):
            return true;
	    case LCTL_T(KC_F4):
            return true;
	    case LSFT_T(KC_F5):
            return true;
			
		case LSFT_T(KC_F8):
            return true;
	    case RCTL_T(KC_F9):
            return true;
	    case LALT_T(KC_F10):
            return true;
		
        case LCTL_T(KC_DEL):
            return true;
	    case RCTL_T(KC_TAB):
            return true;
			
        default:
            return false;
    }
}