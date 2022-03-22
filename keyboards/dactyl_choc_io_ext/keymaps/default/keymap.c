#include QMK_KEYBOARD_H

#include "pointing_device.h"

#define _QWERTY 0

#define _SYMR 1
#define _SYML 2

#define _OTHER 3

#define SYMR MO(_SYMR)

#define S_UP    MT(MOD_LGUI, KC_UP)
#define S_DOWN  MT(MOD_LALT, KC_DOWN)
#define S_LEFT  MT(MOD_LGUI, KC_LEFT)
#define S_RIGHT MT(MOD_LALT, KC_RGHT)

#define S_HOME  MT(MOD_MEH, KC_HOME)
#define S_END   MT(MOD_MEH, KC_END)

#define S_SPC   LT(_SYML, KC_SPC)
#define S_TAB   MT(MOD_LSFT, KC_TAB)

#define S_BSLS  MT(MOD_LCTL, KC_BSLS)
#define S_ESC   MT(MOD_LALT, KC_ESC)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LWIN OSM(MOD_LGUI)

static bool is_mouse_enabled = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = KEYMAP(
    	KC_GRV  , KC_2   , KC_3    , KC_4    , KC_5      , KC_6              , KC_7       , KC_8      , KC_9   , KC_0   , KC_MINS  , KC_EQL  , 
		KC_1    , KC_Q   , KC_W    , KC_E    , KC_R      , KC_T              , KC_Y       , KC_U      , KC_I   , KC_O   , KC_P     , KC_LBRC , 
        KC_DEL  , KC_A   , KC_S    , KC_D    , KC_F      , KC_G              , KC_H       , KC_J      , KC_K   , KC_L   , KC_SCLN  , KC_QUOT , 
        S_BSLS  , KC_Z   , KC_X    , KC_C    , KC_V      , KC_B              , KC_N       , KC_M      , KC_COMM, KC_DOT , KC_SLSH  , KC_RBRC , 
		                   S_DOWN  , S_UP    , S_HOME    , S_TAB             , KC_LWIN    , S_END     , S_LEFT , S_RIGHT,  
		                                       KC_LCTL   , S_SPC             , KC_LSFT    , KC_LCTL   , 
		                                       KC_BSPC   , KC_ENT            , SYMR       , S_ESC
	),

	[_SYMR] = KEYMAP(
	    KC_MUTE, _______, _______, _______, _______, _______ ,         _______   , _______ , _______  , _______, _______, _______, 
	    _______, KC_2   , KC_3   , KC_4   , KC_5   , KC_6    ,         KC_7      , KC_8    , KC_9     , KC_0   , KC_MINS, KC_BSLS, 
		KC_1   , KC_VOLD, KC_VOLU, KC_LPRN, KC_RPRN, KC_PSCR ,         KC_LEFT   , KC_DOWN , KC_UP    , KC_RGHT, KC_EQL , KC_ENT , 
		KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   ,         KC_F7     , KC_F8   , KC_F9    , KC_F10 , KC_F11 , KC_F12 , 
	                      _______, _______, _______, _______ ,         _______   , _______ , KC_BRK   , KC_INS,  
		                                    _______, _______ ,         _______   , _______ , 
		                                    _______, _______ ,         _______   , KC_LSFT
	),
			
	[_SYML] = KEYMAP(
	    KC_MUTE , _______ , _______ , _______ , _______ , _______   ,         _______, _______ , _______ , _______ , _______ , _______ , 
	    _______ , _______ , KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP   ,         _______, KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U , _______ , 
		_______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN   ,         _______, KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , _______ , 
		KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6     ,         KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , 
		                    OS_LALT , OS_LWIN , KC_SLEP , TO(_OTHER),         _______, _______ , KC_BTN1 , KC_BTN2 ,  
		                                        _______ , _______   ,         _______, _______ , 
		                                        KC_LALT , _______   ,         _______, _______
	), 

	[_OTHER] = KEYMAP(
        KC_MUTE , _______ , _______ , _______ , _______ , _______    ,         _______     , _______ , _______ , _______ , RGB_RMOD , RGB_MOD ,
	    _______ , A(KC_F4), KC_VOLD , KC_UP   , KC_VOLU , KC_PGUP    ,         _______     , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U  , RGB_HUI ,
		_______ , C(KC_W) , KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN    ,         _______     , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D  , RGB_SAI , 
		_______ , _______ , _______ , _______ , _______ , _______    ,         _______     , _______ , _______ , _______ , _______  , RGB_VAI , 
		                    _______ , _______ , KC_APP  , TO(_QWERTY),         _______     , RESET   , _______ , _______ , 
		                                        _______ , _______    ,         KC_RGHT     , KC_UP   , 
		                                        _______ , _______    ,         KC_LEFT     , KC_DOWN
	),
	
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case S_SPC:
            return true;		
		case S_TAB:
            return true;	
		case S_BSLS:
            return true;	
		case S_ESC:
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

			
        default:
            return false;
    }
} 

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM osm_ctl_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_PURPLE},
    {10, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM osm_alt_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 1, HSV_CYAN},
    {11, 1, HSV_CYAN}
);

const rgblight_segment_t PROGMEM osm_sft_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 1, HSV_CHARTREUSE},
    {12, 1, HSV_CHARTREUSE}
);

const rgblight_segment_t PROGMEM osm_gui_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_SPRINGGREEN},    
    {18, 2, HSV_SPRINGGREEN}      
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    osm_ctl_layer,
    osm_alt_layer,   
    osm_sft_layer,
    osm_gui_layer
);

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	
	rgblight_layers = my_rgb_layers;
}


void update_mod_layers(uint16_t mods) {
	rgblight_set_layer_state(0, mods & MOD_MASK_CTRL);
	rgblight_set_layer_state(1, mods & MOD_MASK_ALT);
	rgblight_set_layer_state(2, mods & MOD_MASK_SHIFT);
	rgblight_set_layer_state(3, mods & MOD_MASK_GUI);
}

#endif // RGBLIGHT_ENABLE

uint32_t layer_state_set_user(uint32_t state) {
	int highest_layer = get_highest_layer(state); 
	
	is_mouse_enabled = highest_layer == _SYML;

#ifdef RGBLIGHT_ENABLE
    switch (highest_layer) {
        case _QWERTY:
		    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_sethsv_noeeprom(0, 0, 0);
            break;
        case _SYML:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 3);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;
        case _SYMR:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 7);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;

        case _OTHER: 
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
			rgblight_sethsv_noeeprom(170, 255, 170);
            break;
	}

#endif // RGBLIGHT_ENABLE
    return state;
}


void post_process_record_user(uint16_t keycode, keyrecord_t *record) {	
#ifdef RGBLIGHT_ENABLE
	update_mod_layers(get_mods() | get_oneshot_mods());
#endif // RGBLIGHT_ENABLE
}							

void pointing_device_init_user(void){
    pointing_device_set_cpi(5000);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
	if(!is_mouse_enabled) {
		mouse_report.x = 0;
		mouse_report.y = 0;
	}

    return mouse_report;
}