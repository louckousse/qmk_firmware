#include QMK_KEYBOARD_H

#define _BL 0
#define _NL 1
#define _CL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap _BL: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | E    | R    | T    |                              | Y    | U    | I    | O    | P    | `~     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   Esc  | A    | S    | D    | F    | G    |                              | H    | J    | K    | L    | ; :  | ' "    |
     * |--------+------+------+------+------+------|							  |------+------+------+------+------+--------|
     * | Shift  | Z    | X    | C    | V    | B    |                              | N    | M    | , <  | . >  | / ?  | CTRL   |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |             		  | Super|
     *          `------'      				`------+------+-----'  `-------+------+-----'					  `------'
    */
	[_BL] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   	            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_T(KC_CAPS), KC_Z, KC_X, KC_C,   KC_V,    KC_B, 					                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                 KC_LGUI,          KC_LALT, LT(_CL, KC_DEL), LT(_NL, KC_BSPC), LT(_NL, KC_SPC), LT(_CL, KC_ENT), KC_RALT,		KC_LGUI
    ),

    /*
     * Keymap _NL: Number and navigation Layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  = +   | / ?  | 7 &  | 8 *  | 9 (  | - _  |                              |      | Home | Up   | End  | Pg up|        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | . >  | 4 $  | 5 %  | 6 ^  | +    |                              |      | Left | Down | Right| Pgdwn|        |
     * |--------+------+------+------+------+------|							  |------+------+------+------+------+--------|
     * |        | 0 )  | 1 !  | 2 @  | 3 #  | *    |                              | Vol d| Vol u| Play | Mute | PSCR |        |
     * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
     *          | Alt  |                    | Enter|      |      |  |      |      |      |             		  |      |
     *          `------'      				`------+------+-----'   `------+------+-----'			          `------'
    */

	[_NL] = LAYOUT(
        KC_EQL,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,                   _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PPLS,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PAST, 					KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, KC_PSCR, _______,
                 KC_LALT,                   KC_ENT,  _______, _______, _______, _______, _______,					_______
	),

	/*
	 * Keympa _CL : Code Layer
	 *
	 * ,-------------------------------------------.                              ,-------------------------------------------.
	 * | ` ~    | !    | @    | #    | $    | %    |                              | \ |  | &    | *    |      |      |        |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      | [ {  | ] }  | (    | )    |                              | [ {  | ] }  | \ |  | SAI  | HUI  | VAI    |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |                              |      |      |      | SAD  | HUD  | VAD    |
	 * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
	 *          | Reset|                    |      |      |      |  |      |      |      |             		 |      |
	 *          `------'      			    `------+------+-----'   `------+------+-----'			         `------'
	 */
	[_CL] = LAYOUT(
	      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_BSLS, KC_AMPR, KC_ASTR, _______, _______, _______,
	      _______, _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,                   KC_LBRC, KC_RBRC, KC_BSLS, RGB_SAI, RGB_HUI, RGB_VAI,
	      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,
	               RESET,                     _______, _______, _______, _______, _______ , _______,				  _______
	    ),

	// /*
	//  * Layer template
	//  *
	//  * ,-------------------------------------------.                              ,-------------------------------------------.
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * `--------+------+--------------------+------+------+------.  ,------+------+------+--------------------+------+--------'
	//  *          |      |                    |      |      |      |  |      |      |      |                    |      |
	//  *          `------'                    `------+------+-----'  `-------+------+-----'                     `------'
	//  */
	//     [_LAYERINDEX] = LAYOUT(
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//                _______,                   _______, _______, _______, _______, _______, _______,                   _______
	//     ),


};

const rgblight_segment_t PROGMEM base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_RED}
);
const rgblight_segment_t PROGMEM number[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CYAN}
);
const rgblight_segment_t PROGMEM code[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base,
    number,
    code
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, _BL));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CL));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, true);
    return true;
}
