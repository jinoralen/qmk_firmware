#include QMK_KEYBOARD_H

enum sofle_layers {
      _QWERTY,
      _SYMR,
      _SYML, 
      _SYM,
      _GAME
};

#define SYMR    MO(_SYMR)
#define SSYMR   LM(_SYMR, MOD_LSFT)

#define S_SPC   LT(_SYML, KC_SPC)
#define SFT_SPC SFT_T(KC_SPC)

#define S_UP    MT(MOD_LGUI, KC_UP)
#define S_DOWN  MT(MOD_LALT, KC_DOWN)

#define S_LEFT  MT(MOD_LGUI, KC_LEFT)
#define S_RIGHT MT(MOD_LALT, KC_RGHT)

#define S_HOME  MT(MOD_MEH, KC_HOME)
#define S_END   MT(MOD_LGUI, KC_END)

#define S_ESC   MT(MOD_LALT, KC_ESC)
#define S_ENT   MT(MOD_LCTL, KC_ENT)

#define MT_TAB  MT(MOD_LSFT, KC_TAB)
#define MT_RBRC MT(MOD_LSFT, KC_RBRC)
#define MT_F1   MT(MOD_LSFT, KC_F1)
#define MT_F12  MT(MOD_LSFT, KC_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      [_QWERTY] = LAYOUT(
    	KC_1    , KC_2   , KC_3    , KC_4    , KC_5      , KC_6                           , KC_7       , KC_8    , KC_9   , KC_0   , KC_MINS  , KC_EQL  ,  
	KC_GRV  , KC_Q   , KC_W    , KC_E    , KC_R      , KC_T                           , KC_Y       , KC_U    , KC_I   , KC_O   , KC_P     , KC_LBRC , 
      KC_DEL  , KC_A   , KC_S    , KC_D    , KC_F      , KC_G                           , KC_H       , KC_J    , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
      MT_TAB  , KC_Z   , KC_X    , KC_C    , KC_V      , KC_B    , KC_MUTE    , QK_BOOT , KC_N       , KC_M    , KC_COMM, KC_DOT , KC_SLSH  , MT_RBRC , 
	                   S_DOWN  , S_UP    , KC_BSPC   , S_ENT   , S_SPC      , SYMR    , SFT_SPC    , S_ESC   , S_LEFT , S_RIGHT  
	),

	[_SYMR] = LAYOUT(
	_______, _______, _______, _______, _______, _______ ,                              _______   , _______ , _______  , _______, _______, _______, 
      _______, KC_2   , KC_3   , KC_4   , KC_5   , KC_6    ,                              KC_7      , KC_8    , KC_9     , KC_0   , KC_MINS, KC_BSPC, 
	KC_DEL , KC_1   , KC_NUBS, KC_LPRN, KC_RPRN, KC_BSLS ,                              KC_LEFT   , KC_DOWN , KC_UP    , KC_RGHT, KC_EQL , KC_ENT , 
	MT_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   , _______          , _______  ,KC_F7     , KC_F8   , KC_F9    , KC_F10 , KC_F11 , MT_F12 , 
	                  _______, _______, _______, _______ , _______          , _______  ,_______   , _______ , KC_BRK   , KC_INS

	),
			
	[_SYML] = LAYOUT(
	_______ , _______ , _______ , _______ , _______ , _______ ,                        _______, _______ , _______ , _______ , _______ , _______ , 
	_______ , KC_MUTE , KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP ,                        _______, KC_BTN1 , KC_BTN2 , _______ , KC_WH_U , KC_BSPC ,  
	KC_BSPC , KC_PSCR , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN ,                        KC_MS_L, KC_MS_D , KC_MS_U , KC_MS_R , KC_WH_D , KC_ENT  , 
	MT_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , _______     , _______ ,KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_F11  , MT_F12  , 
	                    KC_LALT , KC_LWIN , _______ , KC_LCTL , _______     , _______ ,_______, _______ , KC_HOME , KC_END   
	), 

      [_SYM] = LAYOUT(
	_______ , _______ , _______ , _______ , _______ , _______ ,                        _______  , _______ , _______ , _______ , _______ , _______ , 
	_______ , KC_MUTE , KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP ,                        _______  , KC_BTN1 , KC_BTN2 , _______ , KC_WH_U , KC_BSPC ,  
	KC_BSPC , KC_PSCR , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN ,                        KC_MS_L  , KC_MS_D , KC_MS_U , KC_MS_R , KC_WH_D , KC_ENT  , 
	MT_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , _______     , _______ ,KC_F7    , KC_F8   , KC_F9   , KC_F10  , KC_F11  , MT_F12  , 
	                    KC_LALT , KC_LWIN , _______ , KC_LCTL , _______     , _______ ,TO(_GAME), _______ , KC_HOME , KC_END   
	), 

      [_GAME] = LAYOUT(
    	KC_1    , KC_2   , KC_3    , KC_4    , KC_5      , KC_6                                , _______       , _______    , _______   , _______   , _______  , _______ ,  
	KC_T    , KC_TAB , KC_Q    , KC_W    , KC_E      , KC_R                                , _______       , _______    , _______   , _______   , _______  , _______ , 
      KC_G    , KC_LSFT, KC_A    , KC_S    , KC_D      , KC_F                                , _______       , _______    , _______   , _______   , _______  , _______ , 
      KC_B    , KC_LCTL, KC_X    , KC_C    , KC_V      , KC_B    , KC_MUTE     , _______     , _______       , _______    , _______   , _______   , _______  , _______ , 
	                   KC_LALT , KC_LGUI , KC_BSPC   , KC_ENT  , KC_SPC      , TO(_QWERTY) , _______       , _______    , _______   , _______  
	)
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	// define keys that should be handle as modifiers after pressing some other keys withing tap term
    switch (keycode) {
		case S_SPC:
            case SFT_SPC:

		case S_ESC:
            case S_ENT:
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
        case SFT_SPC:
        case S_ENT:
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

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYML, _SYMR, _SYM);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
	  if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif
