#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _OTHER 3

#define SYML LT(_SYML, KC_SPC)
#define SYMR MO(_SYMR)

#define S_UP    MT(MOD_LALT, KC_UP)
#define S_DOWN  MT(MOD_LCTL | MOD_LSFT, KC_DOWN)
#define S_LEFT  MT(MOD_LCTL, KC_LEFT)
#define S_RIGHT MT(MOD_LCTL | MOD_LALT, KC_RGHT)

#define S_HOME  MT(MOD_LSFT, KC_HOME)
#define S_END   MT(MOD_LGUI, KC_END)

#define S_BSLS  MT(MOD_LGUI | MOD_LALT, KC_BSLS)
#define S_ESC   MT(MOD_LGUI | MOD_LCTL, KC_ESC)

#define LG_LALT LGUI_T(KC_LALT)
#define LG_LCTL LGUI_T(KC_LCTL)
#define LC_LALT LCTL_T(KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
    	KC_GRV  , KC_2   , KC_3    , KC_4    , KC_5      , KC_6           ,         KC_7       , KC_8      , KC_9   , KC_0   , KC_MINS  , KC_EQL  , 
		KC_1    , KC_Q   , KC_W    , KC_E    , KC_R      , KC_T           ,         KC_Y       , KC_U      , KC_I   , KC_O   , KC_P     , KC_LBRC , 
        KC_DEL  , KC_A   , KC_S    , KC_D    , KC_F      , KC_G           ,         KC_H       , KC_J      , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
        KC_TAB  , KC_Z   , KC_X    , KC_C    , KC_V      , KC_B           ,         KC_N       , KC_M      , KC_COMM, KC_DOT , KC_SLSH  , KC_RBRC , 
		                   S_HOME  , S_END   , S_DOWN    , S_UP           ,         S_LEFT     , S_RIGHT   , KC_LWIN, S_BSLS,  
		                                       KC_LCTL   , SYML           ,         KC_LSFT    , KC_LALT   , 
		                                       KC_BSPC   , KC_ENT         ,         SYMR       , S_ESC
	),

	[_SYMR] = KEYMAP(
	    KC_GRV , KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC ,         KC_AMPR   , KC_ASTR , KC_LPRN  , KC_RPRN, KC_UNDS, KC_PLUS, 
	    KC_EXLM, KC_2   , KC_3   , KC_4   , KC_5   , KC_6    ,         KC_7      , KC_8    , KC_9     , KC_0   , KC_MINS, KC_BSLS, 
		KC_DEL , KC_1   , KC_HOME, KC_LPRN, KC_RPRN, KC_END  ,         KC_LEFT   , KC_DOWN , KC_UP    , KC_RGHT, KC_EQL , KC_ENT , 
		KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   ,         KC_F7     , KC_F8   , KC_F9    , KC_F10 , KC_F11 , KC_F12 , 
	                      _______, _______, _______, _______ ,         _______   , _______ , KC_BRK   , KC_INS,  
		                                    _______, _______ ,         _______   , _______ , 
		                                    _______, _______ ,         _______   , KC_LSFT
	),
			
	[_SYML] = KEYMAP(
	    KC_MUTE , _______ , _______ , _______ , _______ , _______   ,         _______, _______ , _______ , _______ , _______ , _______ , 
	    _______ , KC_VOLU , KC_HOME , KC_UP   , KC_END  , KC_PGUP   ,         _______, _______ , _______ , _______ , _______ , _______ , 
		KC_PSCR , KC_VOLD , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN ,         _______, _______ , _______ , _______ , _______ , _______ , 
		KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6     ,         KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , 
		                    _______ , _______ , KC_SLEP , TO(_OTHER),         KC_LCTL, LC_LALT , _______ , _______ ,  
		                                        _______ , _______   ,         _______, _______ , 
		                                        _______ , _______   ,         LG_LALT, LG_LCTL
	), 

	[_OTHER] = KEYMAP(
        KC_ESC  , _______ , _______ , _______ , _______ , _______    ,         _______     , _______ , _______ , _______ , _______ , _______ ,
	    _______ , A(KC_F4), KC_DEL  , KC_UP   , KC_TAB  , KC_PGUP    ,         KC_PSLS     , KC_7    , KC_8    , KC_9    , KC_MINS , KC_EQL  ,
		_______ , C(KC_W) , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDOWN  ,         KC_PAST     , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_NUBS , 
		_______ , _______ , KC_VOLD , KC_MUTE , KC_VOLU , _______    ,         KC_0        , KC_1    , KC_2    , KC_3    , KC_LPRN , KC_RPRN , 
		                    _______ , _______ , KC_APP  , TO(_QWERTY),         _______     , RESET   , KC_PDOT , KC_PENT , 
		                                        _______ , _______    ,         KC_RGHT     , KC_UP   , 
		                                        _______ , _______    ,         KC_LEFT     , KC_DOWN
	)
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SYML:
            return true;	
			
		case S_UP:
            return true;	
		case S_DOWN:
            return true;	
		case S_LEFT:
            return true;	
		case S_RIGHT:
            return true;	
			
		case S_HOME:
            return true;	
		case S_END:
            return true;	
			
		case S_BSLS:
            return true;	
		case S_ESC:
            return true;	
			
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SYML:
            return 270;	
			
		case S_UP:
            return 270;	
		case S_DOWN:
            return 270;	
		case S_LEFT:
            return 270;	
		case S_RIGHT:
            return 270;	
			
		case S_HOME:
            return 270;	
		case S_END:
            return 270;	
			
        case S_BSLS:
            return 270;			
        case S_ESC:
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
	rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
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
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;
        case _SYMR:
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 7);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;

        case _OTHER: 
	        rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;
	}
	
	rgblight_set();
#endif // RGBLIGHT_ENABLE
    return state;
}