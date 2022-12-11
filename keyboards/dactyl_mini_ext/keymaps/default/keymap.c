#include QMK_KEYBOARD_H

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _MEDIA 3

#define SYMR    MO(_SYMR)
#define SSYMR   LM(_SYMR, MOD_LSFT)

#define S_SPC   LT(_SYML, KC_SPC)

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
    [_QWERTY] = KEYMAP(
	KC_GRV  , KC_Q   , KC_W    , KC_E    , KC_R      , KC_T                           , KC_Y       , KC_U      , KC_I   , KC_O   , KC_P     , KC_LBRC , 
      KC_DEL  , KC_A   , KC_S    , KC_D    , KC_F      , KC_G                           , KC_H       , KC_J      , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
      MT_TAB  , KC_Z   , KC_X    , KC_C    , KC_V      , KC_B                           , KC_N       , KC_M      , KC_COMM, KC_DOT , KC_SLSH  , MT_RBRC , 
	                   S_DOWN  , S_UP    , S_HOME    , S_SPC   , KC_ENT,         SYMR , KC_LSFT    , S_END     , S_LEFT , S_RIGHT,  
	                                       KC_LCTL   , KC_BSPC ,                        SSYMR      , S_ESC 
	),

	[_SYMR] = KEYMAP(
	KC_GRV , KC_2   , KC_3   , KC_4   , KC_5   , KC_6                                 , KC_7      , KC_8    , KC_9     , KC_0   , KC_MINS, KC_BSPC, 
      KC_DEL , KC_1   , KC_LSFT, KC_LPRN, KC_RPRN, KC_BSLS                              , KC_LEFT   , KC_DOWN , KC_UP    , KC_RGHT, KC_EQL , KC_ENT ,
      MT_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6                                , KC_F7     , KC_F8   , KC_F9    , KC_F10 , KC_F11 , MT_F12 , 
                        _______, _______, _______, _______ , _______,           _______ , _______   , RESET   , KC_BRK   , KC_INS ,  
		                              _______, _______ ,                              KC_LSFT   , _______ 
	),

	[_SYML] = KEYMAP(
	KC_GRV  , KC_MUTE , KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP                          , _______, KC_BTN1 , KC_BTN2 , _______ , KC_WH_U , KC_BSPC ,  
      KC_DEL  , KC_PSCR , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN                          , KC_MS_L, KC_MS_D , KC_MS_U , KC_MS_R , KC_WH_D , KC_ENT  ,  
      MT_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6                            , KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_F11  , MT_F12  , 
	                    KC_LALT , KC_LWIN , KC_SLEP , _______, TO(_MEDIA),     _______ , _______, _______ , KC_BTN1 , KC_BTN2 ,  
	                                        _______ , _______,                           _______, _______ 
	),

	[_MEDIA] = KEYMAP(
	KC_MUTE , A(KC_F4), KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP                          , _______, KC_BTN1 , KC_BTN2 , _______ , KC_WH_U , _______ ,  
      KC_DEL  , C(KC_W) , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN                          , KC_MS_L, KC_MS_D , KC_MS_U , KC_MS_R , KC_WH_D , _______ ,  
      _______ , _______ , _______ , _______ , _______ , _______                          , _______, _______ , _______ , _______ , _______ , _______ , 
	                    _______ , _______ , _______ , _______, TO(_QWERTY),    _______ , _______, _______ , KC_BTN1 , KC_BTN2 ,  
	                                        _______ , _______,                           _______, _______ 
	),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	// define keys that aren't held (usually taped once)
    switch (keycode) {
		case S_ESC:
            return true;	

		case MT_TAB:
            return true;	
		case MT_RBRC:
            return true;	
        case MT_F1:
            return true;	
		case MT_F12:
            return true;	

		case S_HOME:
            return true;	
		case S_END:
            return true;	

        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	// define keys that should be handle as modifiers after pressing some other keys withing tap term
    switch (keycode) {
		case S_SPC:
            return true;		
		
		case S_ESC:
            return true;	

		case MT_TAB:
            return true;	
		case MT_RBRC:
            return true;	
        case MT_F1:
            return true;	
		case MT_F12:
            return true;	

		case S_HOME:
            return true;	
		case S_END:
            return true;	
	
		case S_UP:
            return true;	
		case S_DOWN:
            return true;	
		case S_LEFT:
            return true;	
		case S_RIGHT:
            return true;	

        default:
            return false;
    }
} 

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case S_ESC:
            return true;	

		case MT_TAB:
            return true;	
		case MT_RBRC:
            return true;	
        case MT_F1:
            return true;	
		case MT_F12:
            return true;	

		case S_HOME:
            return true;	
		case S_END:
            return true;	

        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_TAB:
            return true;	
		case MT_RBRC:
            return true;	
        case MT_F1:
            return true;	
		case MT_F12:
            return true;	

        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}