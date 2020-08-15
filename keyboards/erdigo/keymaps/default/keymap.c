#include QMK_KEYBOARD_H

#define _QWERTY 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(										 							 
                 KC_GRV, KC_2, KC_3, KC_4, KC_5   , KC_6   ,                                              KC_7   , KC_8   , KC_9   , KC_0  , KC_MINS, KC_EQL , 
        KC_ESC , KC_1  , KC_Q, KC_W, KC_E, KC_R   , KC_T   , KC_PGUP  ,                          KC_HOME, KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC, KC_BSLS, 
        KC_LSFT, KC_DEL, KC_A, KC_S, KC_D, KC_F   , KC_G   , KC_PGDOWN,                          KC_END , KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT, KC_ENT , 
                 KC_TAB, KC_Z, KC_X, KC_C, KC_V   , KC_B   , _______  , KC_MUTE,        KC_MPLY, _______, KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
                                           _______, _______, _______  ,                          _______, _______, _______,      
										                         _______,                    _______,
										                             _______,            _______,  
																	 	 _______,     _______
	),
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
#endif

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (biton32(state)) {
        case _QWERTY:
	        rgblight_disable_noeeprom();
            break;
    }
	rgblight_set();
#endif // RGBLIGHT_ENABLE
    return state;
}

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

void oled_task_user(void) {
    render_logo();  // Renders a static logo
    oled_scroll_left();  // Turns on scrolling
}

#endif

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
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

#endif
