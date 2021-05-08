#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _OTHER 3
#define _GAME 4


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		KC_ESC , KC_Q   , KC_W    , KC_E    , KC_R     , KC_T           ,         KC_Y     , KC_U      , KC_I   , KC_O   , KC_P     , KC_LBRC , 
        KC_DEL , KC_A   , KC_S    , KC_D    , KC_F     , KC_G           ,         KC_H     , KC_J      , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
        KC_BSLS, KC_Z   , KC_X    , KC_C    , KC_V     , KC_B           ,         KC_N     , KC_M      , KC_COMM, KC_DOT , KC_SLSH  , KC_RBRC , 
		                  KC_LALT , KC_MUTE , KC_TAB   , LSFT_T(KC_ENT) ,         KC_ENT   , KC_LWIN   , KC_LPRN, KC_RPRN,  
		                                      MO(_SYML), KC_SPC         ,         KC_LSFT  , MO(_SYMR) , 
		                                      KC_LCTL  , KC_BSPC        ,         KC_ESC   , KC_LALT
	),

	[_SYMR] = KEYMAP(
	    KC_GRV  , KC_BRK  , KC_UNDS , KC_ASTR , KC_AMPR , _______ ,         KC_PSLS   , KC_7    , KC_8    , KC_9    , KC_MINS , KC_EQL  , 
		_______ , KC_LSFT , KC_CIRC , KC_PERC , KC_DLR  , _______ ,         KC_PAST   , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_NUBS , 
		_______ , KC_LALT , KC_HASH , KC_AT   , KC_EXLM , _______ ,         KC_0      , KC_1    , KC_2    , KC_3    , KC_LPRN , KC_RPRN , 
		                    _______ , _______ , _______ , _______ ,         TO(_GAME) , KC_SLEP , KC_PDOT , KC_PENT ,  
		                                        _______ , _______ ,         _______   , _______ , 
		                                        _______ , _______ ,         KC_NLCK   , _______
	),
			
	[_SYML] = KEYMAP(
	    KC_GRV  , KC_BRK  , KC_HOME , KC_UP   , KC_END  , KC_PGUP   ,         _______ , _______ , _______ , _______ , _______ , _______ , 
		_______ , KC_INS  , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN ,         _______ , _______ , _______ , _______ , _______ , _______ , 
		KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6     ,         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , 
		                    _______ , KC_PSCR , KC_APP  , TO(_OTHER),         _______ , _______ , KC_VOLD , KC_VOLU ,  
		                                        _______ , RESET     ,         _______ , KC_LCTL , 
		                                        _______ , KC_SLEP   ,         _______ , _______
	), 

	[_OTHER] = KEYMAP(
	    KC_ESC  , A(KC_F4), KC_DEL  , KC_UP   , KC_TAB  , KC_PGUP    ,         KC_PSLS , KC_7        , KC_8    , KC_9    , KC_MINS , KC_EQL  ,
		KC_LSFT , C(KC_W) , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN  ,         KC_PAST , KC_4        , KC_5    , KC_6    , KC_PLUS , KC_NUBS , 
		KC_LALT , _______ , KC_VOLD , KC_MUTE , KC_VOLU , _______    ,         KC_0    , KC_1        , KC_2    , KC_3    , KC_LPRN , KC_RPRN , 
		                    _______ , _______ , KC_APP  , TO(_QWERTY),         _______ , MO(_QWERTY) , KC_PDOT , KC_PENT , 
		                                        KC_ENT  , _______    ,         KC_DOWN , KC_UP       , 
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
            return TAPPING_TERM + 50;
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
