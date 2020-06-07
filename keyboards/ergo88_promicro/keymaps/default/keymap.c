#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _MEDIA 1
#define _ADDITIONS 2
#define _SYSTEM 3

enum custom_keycodes {
  MEDIA = SAFE_RANGE,
  ADDITIONS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
		KC_GRAVE           , KC_F1  , KC_F2, KC_F3, KC_F4  , KC_F5         , KC_F6          , MEDIA     ,                    ADDITIONS, KC_F7            , KC_F8         , KC_F9  , KC_F10, KC_F11 , KC_F12 , KC_DELETE, 
		KC_ENT             , KC_LPRN, KC_Q , KC_W , KC_E   , KC_R          , KC_T           , KC_PGUP   ,                    KC_HOME  , KC_Y             , KC_U          , KC_I   , KC_O  , KC_P   , KC_LBRC, KC_BSLS, 
		KC_LSFT            , KC_EQL , KC_A , KC_S , KC_D   , KC_F          , KC_G           , KC_PGDOWN	,                    KC_END   , KC_H             , KC_J          , KC_K   , KC_L  , KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LCTL            , KC_RPRN, KC_Z , KC_X , KC_C   , KC_V          , KC_B           , KC_LALT   ,                    KC_RALT  , KC_N             , KC_M          , KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, KC_INS, 
		LT(_MEDIA, KC_MUTE), KC_1   , KC_2 , KC_3 , KC_4   , KC_5          , KC_6           , KC_LWIN   ,                    KC_PSCR  , KC_7             , KC_8          , KC_9   , KC_0  , KC_MINS, KC_PLUS, KC_PAUSE, 
		                                            KC_LEFT, LSFT_T(KC_SPC), LCTL_T(KC_BSPC), KC_RIGHT  ,                    KC_UP    , RCTL_T(KC_ESC)   , RSFT_T(KC_TAB), KC_DOWN
	),
	[_MEDIA] = KEYMAP(
		KC_SLEP, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______,     _______, KC_CALC, KC_MYCM, KC_WHOM, KC_WREF, KC_WBAK, KC_WFWD, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		_______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, 
		                                    _______, _______, _______, _______,     _______, _______, _______, _______
	),
	[_ADDITIONS] = KEYMAP(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , _______,     _______, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, KC_PGUP  , KC_VOLU,     XXXXXXX, XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN, KC_VOLD,     XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , KC_MUTE,     XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX,     XXXXXXX, XXXXXXX, KC_P0  , KC_PDOT, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX,
		                                    KC_ESC , KC_SPC , KC_ENT   , KC_APP ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_SYSTEM] = KEYMAP(
		RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		DEBUG  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	)
	
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MEDIA:
      if (record->event.pressed) {
        layer_invert(_MEDIA);
      }
	  update_tri_layer(_MEDIA, _ADDITIONS, _SYSTEM);
      return false;
      break;
    case ADDITIONS:
      if (record->event.pressed) {
        layer_invert(_ADDITIONS);
      }
	  update_tri_layer(_MEDIA, _ADDITIONS, _SYSTEM);
      return false;
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	/*
        case LSFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
		case RSFT_T(KC_TAB):
            return TAPPING_TERM + 1250;
	*/
        default:
            return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
		case RSFT_T(KC_TAB):
			return true;
        default:
            return false;
    }
}