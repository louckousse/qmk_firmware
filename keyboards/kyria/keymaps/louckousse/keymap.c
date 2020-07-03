/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <string.h>
#include <stdio.h>
#include QMK_KEYBOARD_H

enum layers {
    CMK = 0,
    LWR,
    RSE,
    SC2_B,
    SC2_L,
    GAME_B,
    GAME_L,
};

typedef union {
    uint32_t raw;
    struct {
        bool osIsLinux;
    };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
    KC_GG = SAFE_RANGE,
    KC_GL,
    DSK_NXT,
    DSK_PRV,
    PRINT,
    LOCK,
    KC_OS,
    KC_BT,
    KC_QT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak-dhm
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ; : |  ^   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |  O   | ' "  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | ; :  |   Z  |   X  |   C  |   D  |   V  | Pause| CtEnt|  | ESC  |Leader|   K  |   H  | ,  < | . >  | /  ? | ` ~  |
 * `--------------------+------+------+------+------+------|  |------|------+------+------+------+--------------------'
 *                      | Play | Alt  | Ctrl | Shift| Lower|  | Lower| Shift| Ctrl | Alt  | GUI  |
 *                      |      |      |  - _ | Del  | Enter|  | Space| Space|      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [CMK] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_CIRC,
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
      KC_SCLN, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_PAUS, LT(LWR, C(KC_ENT)),  LT(RSE, KC_ESC), KC_OS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH, KC_GRV,
          KC_MPLY, KC_LALT, MT(MOD_LCTL, KC_MINS), MT(MOD_LSFT, KC_DEL), LT(RSE, KC_ENT), LT(LWR, KC_BSPC), MT(MOD_LSFT, KC_SPC), KC_RCTL, KC_RALT, KC_LGUI
    ),

/*
 * Lower Layer: Numpad, Symbol
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ~    |  $   |  @   |  [ { |  ] } |  \   |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |  SC2   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   `    |  #   |  !   |  (   |  )   |  /   |                              | *    | 4 $  | 5 %  | 6 ^  |  +   | Qwerty |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   '    |      |  €   |  {   |  }   |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  | Colemak|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LWR] = LAYOUT(
      KC_TILD, KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, DF(GAME_B),
      KC_BT,   KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_SLSH,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_PLUS, DF(SC2_B),
      KC_QT,  _______,ALGR(KC_5),KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  DF(CMK),
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Media, nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Prns  |      | Home | Up   | End  | Pgup |                              |  F9  |  F10 |  F11 |  F12 |  SAI |  VAI   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Lock  |  Tab | Left | Down | Right| Pgdn |                              |  F5  |  F6  |  F7  |  F8  |      |  HUI   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Sleep |      |  <M  |  M>  | <D   | D>   |      |      |  |      |      |  F1  |  F2  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      PRINT,   _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                                     KC_F9,   KC_F10,  KC_F11,  KC_F12, RGB_SAI, RGB_VAI,
      LOCK,    KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,  _______, RGB_HUI,
      KC_SLEP, _______, KC_MPRV, KC_MNXT, DSK_PRV, DSK_NXT, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SC2_B] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                        KC_GL,   _______, KC_GG,   _______, _______, _______,
      KC_ESC,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                        _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_TAB,  KC_2,    KC_5,  MO(SC2_L), _______, _______, _______, _______, _______
    ),

    [SC2_L] = LAYOUT(
      _______, KC_GRV,  KC_7,     KC_8,    KC_9,    KC_F1,                                       _______, _______, _______, _______, _______, _______,
      _______, _______, KC_4,     KC_5,    KC_6,    KC_F2,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_LCTL, KC_1,     KC_2,    KC_3,    KC_F3,   _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(CMK),
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [GAME_B] = LAYOUT(
      KC_TAB,  _______, KC_Q,    KC_W,    KC_E,    KC_R,                                        _______, _______, _______, _______, _______, _______,
      KC_ESC,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                                        _______, _______, _______, _______, _______, _______,
      KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_C,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_C, LT(GAME_L, KC_ENT), KC_LSFT, KC_SPC,  _______, _______, _______, _______, _______
    ),

    [GAME_L] = LAYOUT(
      KC_N,    KC_F1,   KC_4,     KC_5,    KC_6,    KC_LALT,                                     _______, _______, _______, _______, _______, _______,
      KC_Y,    KC_F2,   KC_1,     KC_2,    KC_3,    KC_J,                                        _______, _______, _______, _______, _______, _______,
      KC_P,    KC_F3,   KC_7,     KC_8,    KC_9,    KC_M,    _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, DF(CMK),
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GG:  // One key copy/paste
            if (record->event.pressed) {
                SEND_STRING("\nGG\n");
            } else {
                tap_code16(KC_F10);
                tap_code16(KC_W);
            }
            break;
        case KC_GL:
            if (record->event.pressed) {
                SEND_STRING("\ngl hf\n");
            }
            break;
        case DSK_PRV:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_LEFT)));
                } else {
                    tap_code16(C(G(KC_LEFT)));
                }
            }
            break;
        case DSK_NXT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_RIGHT)));
                } else {
                    tap_code16(C(G(KC_RIGHT)));
                }
            }
            break;
        case PRINT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(S(KC_PSCR)));
                } else {
                    tap_code16(S(G(KC_S)));
                }
            }
            break;
        case LOCK:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(LCA(KC_L));
                } else {
                    tap_code16(G(KC_L));
                }
            }
            break;
        case KC_OS:
            if(record->event.pressed) {
                user_config.osIsLinux = !user_config.osIsLinux;
                eeconfig_update_user(user_config.raw);
            }
        case KC_BT:
            if(record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_SPC);
            }
        case KC_QT:
            if(record->event.pressed) {
                tap_code16(KC_QUOT);
                tap_code16(KC_SPC);
            }
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

// WPM-responsive animation stuff here
#define IDLE_FRAMES 2

#define TAP_FRAMES 2
#define TAP_SPEED 35 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 640 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint16_t anim_timer = 0;
uint16_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

bool idle_bool = false;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
        32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8,  0,  0,  0,  0
        },
        {
        0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16,  8,  4,  2,  2,  4, 24, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,194,  1,  1,  2,  2,  4,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96, 96,  0,129,130,130,132,  8, 16, 32, 64,128,  0,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 25,  6,  0,  0,  0,  0,  0,  0,  0, 24, 24, 24, 27,  3,  0, 64,160, 34, 36, 20, 18, 18, 18, 11,  8,  8,  8,  8,  5,  5,  9,  9, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
        32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8,  0,  0,  0,  0
        },
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,  1,  2,  4,  8, 16, 32, 67,135,  7,  1,  0,184,188,190,159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132, 67,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1, 61,124,252,252,252,252,252, 60, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 63, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
        32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8,  0,  0,  0,  0
        },
        {
        0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,122,122,121,121,121,121, 57, 49,  2,  2,  4,  4,  8,  8,  8,136,136,135,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
        32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,120,124,254,255, 63,  7,  0,  0,  0,  0,255,255,127,127, 63, 62, 28, 24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8,  0,  0,  0,  0
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=TAP_SPEED){
            if (idle_bool) {
                idle_bool = false;
                return;
            }
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            idle_bool = true;
         } else {
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() > 0) {
        if(timer_elapsed(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read();
            animation_phase();
        }
        anim_sleep = timer_read();
    }
}

static void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case CMK: oled_write_P(PSTR("Colemak-DHM\n"), false); break;
        case SC2_B: oled_write_P(PSTR("For the swarm"), false); break;
        case GAME_B: oled_write_P(PSTR("SHOOT\n"), false); break;
        default: oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case LWR: oled_write_P(PSTR("Lower\n"), false); break;
        case RSE: oled_write_P(PSTR("Raise\n"), false); break;
        case SC2_L: oled_write_P(PSTR("Select unit\n"), false); break;
        case GAME_L: oled_write_P(PSTR("Change weapon\n"), false); break;
        default: oled_write_P(PSTR("Base\n"), false);
    }
}

void write_int_to_string(char* ref, uint8_t wpm) {
    // Words per minute is just assumed to remain under a thousand.
    char wpm_string[4];
    itoa(wpm, wpm_string, 10);
    strcat(ref, wpm_string);
}

void oled_write_with_int(char* str, uint8_t number) {
    write_int_to_string(str, number);
    oled_write_ln(str, false);
}

static void render_os(void) {
    if (user_config.osIsLinux) {
        oled_write_P(PSTR("OS:     Linux-mint\n"), false);
    } else {
        oled_write_P(PSTR("OS:     Windows 10\n"), false);
    }
}

static void render_hsv(void) {
    char hue[32] = "HUE:    ";
    oled_write_with_int(hue, rgblight_get_hue());

    char sat[32] = "SAT:    ";
    oled_write_with_int(sat, rgblight_get_sat());

    char val[32] = "VAL:    ";
    oled_write_with_int(val, rgblight_get_val());
}

char wpm_str[10];

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default();
        render_layer_status();
        render_os();
        render_hsv();
    } else {
        render_anim();
        oled_set_cursor(0,7);
        sprintf(wpm_str, "          %03d", get_current_wpm());
        oled_write(wpm_str, false);
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case RSE:
            case LWR:
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(S(KC_Z)));
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(C(KC_LEFT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case RSE:
            case LWR:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            default:
                if (clockwise) {
                    if (user_config.osIsLinux) {
                        tap_code16(C(A(KC_LEFT)));
                    } else {
                        tap_code16(C(G(KC_LEFT)));
                    }
                } else {
                    if (user_config.osIsLinux) {
                        tap_code16(C(A(KC_RIGHT)));
                    } else {
                        tap_code16(C(G(KC_RIGHT)));
                    }
                }
        }
    }
}
