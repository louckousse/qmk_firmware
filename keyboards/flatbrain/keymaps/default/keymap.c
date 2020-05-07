#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap _QWERTY: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | E    | R    | T    |                              | Y    | U    | I    | O    | P    | `~     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   Esc  | A    | S    | D    | F    | G    |                              | H    | J    | K    | L    | ; :  | ' "    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * | Shift  | Z    | X    | C    | V    | B    |                              | N    | M    | , <  | . >  | / ?  | CTRL   |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Lead |
     *          `------'                    `------+------+-----'  `-------+------+-----'                     `------'
    */
	[_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   	            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_T(KC_CAPS), KC_Z, KC_X, KC_C,   KC_V,    KC_B, 					                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                 KC_LGUI,          KC_LALT, LT(_RAISE, KC_DEL), LT(_LOWER, KC_BSPC), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_RALT,		KC_LEAD
    ),

    /*
     * Keymap _COLEMAK: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | F    | P    | B    |                              | J    | L    | U    | Y    | ; :  | `~     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   Esc  | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | ' "    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * | Shift  | Z    | X    | C    | D    | V    |                              | K    | H    | , <  | . >  | / ?  | CTRL   |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Super|
     *          `------'                    `------+------+------'  `-------+------+-----'                    `------'
    */
	[_COLEMAK] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                   	            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        SFT_T(KC_CAPS), KC_Z, KC_X, KC_C,   KC_D,    KC_V, 					                KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                 KC_LGUI,          KC_LALT, LT(_RAISE, KC_DEL), LT(_LOWER, KC_BSPC), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ENT), KC_RALT,		KC_LGUI
    ),

    /*
     * Keymap _LOWER: Number and navigation Layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  = +   | / ?  | 7 &  | 8 *  | 9 (  | - _  |                              |      | Home | Up   | End  | Pg up|        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | . >  | 4 $  | 5 %  | 6 ^  | +    |                              |      | Left | Down | Right| Pgdwn|        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | 0 )  | 1 !  | 2 @  | 3 #  | *    |                              | Vol d| Vol u| Play | Mute | PSCR |        |
     * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
     *          | Alt  |                    | Enter|      |      |   |      |      |     |                    | Clmk |
     *          `------'                    `------+------+------'   `------+------+-----'                    `------'
    */

	[_LOWER] = LAYOUT(
        KC_EQL,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,                   _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PPLS,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PAST, 					KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, KC_PSCR, _______,
                 KC_LALT,                   KC_ENT,  _______, _______, _______, _______, _______,					DF(_COLEMAK)
	),

	/*
	 * Keympa _RAISE : Code Layer
	 *
	 * ,-------------------------------------------.                              ,-------------------------------------------.
	 * | ` ~    | !    | @    | #    | $    | %    |                              | \ |  | &    | *    | SAI  | HUI  | VAI    |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      | [ {  | ] }  | (    | )    |                              | [ {  | ] }  | \ |  | SAD  | HUD  | VAD    |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |   F1   | F2   | F3   | F4   | F5   | F6   |                              | F7   | F8   | F9   | F10  | F11  | F12    |
	 * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
	 *          | Reset|                    |      |      |      |   |      |      |     |            		 |      |
	 *          `------'                    `------+------+------'   `------+------+-----'                   `------'
	 */
	[_RAISE] = LAYOUT(
	      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_BSLS, KC_AMPR, KC_ASTR, RGB_SAI, RGB_HUI, RGB_VAI,
	      _______, _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,                   KC_LBRC, KC_RBRC, KC_BSLS, RGB_SAD, RGB_HUD, RGB_VAD,
	      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
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
	//  *          `------'                    `------+------+------'  `------+------+------'                    `------'
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
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, true);
    return true;
}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_T) { SEND_STRING(SS_LCTRL(SS_LSFT("t"))); }

        SEQ_TWO_KEYS(KC_E, KC_S) { SEND_STRING(":sunglasses:"); }

        SEQ_TWO_KEYS(KC_E, KC_O) { SEND_STRING(":okay_hand:"); }

        SEQ_TWO_KEYS(KC_G, KC_A) { SEND_STRING("git add ."SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_D) { SEND_STRING("git diff"SS_TAP(X_ENT)); }

        SEQ_THREE_KEYS(KC_G, KC_D, KC_S) { SEND_STRING("git diff --staged"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_L) { SEND_STRING("git l"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_F) { SEND_STRING("git fp"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_O) { SEND_STRING("git checkout"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_P) { SEND_STRING("git pull"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_S) { SEND_STRING("git status"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m "SS_DOWN(X_RALT)"''"SS_UP(X_RALT)SS_TAP(X_LEFT));
        }

        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) { SEND_STRING("git amend"SS_TAP(X_ENT)); }

        SEQ_ONE_KEY(KC_1) {
            // ¯\_(ツ)_/¯
            send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }

        SEQ_ONE_KEY(KC_2) {
            // ಠ_ಠ
            send_unicode_string("ಠ_ಠ");
        }

        SEQ_TWO_KEYS(KC_P, KC_O) {
            SEND_STRING(SS_LCTRL(SS_LALT("t"))"po"SS_TAP(X_ENT));
        }
    }
}
