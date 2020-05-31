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

#define ANIM_NUM_FRAMES 2 // number of frames in the animation
#define ANIM_FRAME_DURATION 100 // how long each frame lasts
#define ANIM_REVERSE // define this if you want the animation to run backwards at the end

#ifdef ANIM_REVERSE
#define ANIM_TOTAL_FRAMES (2*((ANIM_NUM_FRAMES)-1))
#else
#define ANIM_TOTAL_FRAMES ANIM_NUM_FRAMES
#endif

enum layers {
    CMK = 0,
    QWE,
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak-dhm
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |  ; : | `~   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |  O   | ' "  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | - _  |   Z  |   X  |   C  |   D  |   V  | CtEnt| Pause|  |      |Leader|   K  |   H  | ,  < | . >  | /  ? | ^    |
 * `--------------------+------+------+------+------+------|  | Lower|------+------+------+------+--------------------'
 *                      | Play | Alt  | Ctrl | Shift| Lower|  | Space| Shift| Ctrl | Alt  | GUI  |
 *                      |      |      |      | Del  | Enter|  |      | Space|      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [CMK] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_GRV,
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
      KC_MINS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, C(KC_ENT),  KC_PAUS,  XXXXXXX, KC_LEAD, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH, KC_CIRC,
               KC_MPLY, KC_LALT, KC_LCTL, MT(MOD_LSFT, KC_DEL), LT(RSE, KC_ENT), LT(LWR, KC_BSPC), MT(MOD_LSFT, KC_SPC), KC_RCTL, KC_RALT, KC_LGUI
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | `~   |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | ' "  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * | - _  |   Z  |   X  |   C  |   V  |   B  | - _  | Pause|  |      |Leader|   N  |   M  | ,  < | . >  | /  ? | ^    |
 * `--------------------+------+------+------+------+------|  | Lower|------+------+------+------+--------------------'
 *                      | GUI  | Alt  | Ctrl | Raise| Lower|  | Bcksp| Raise|      | Alt  | Play |
 *                      |      |      |      | Del  | Enter|  |      | Space| Shift|      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [QWE] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
      KC_ESC,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_MINS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,  KC_PAUS,  XXXXXXX, KC_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_CIRC,
              KC_LGUI, KC_LALT, KC_LCTL, LT(RSE, KC_DEL), LT(RSE, KC_ENT),  LT(LWR, KC_SPC), LT(RSE, KC_BSPC), KC_RSFT, KC_RALT, KC_MPLY
    ),

/*
 * Lower Layer: Numpad, Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Prns   |      | Home | Up   | End  | Pgup |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  | +      |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Lock   |  <M  | Left | Down | Right| Pgdn |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | Qwerty |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |       |  M>  |       |      | <D   | D>   | Sleep| game |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  | Colemak|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LWR] = LAYOUT(
      PRINT,   _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, KC_PLUS,
      LOCK,    KC_MPRV, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_COMM, DF(QWE),
      _______, KC_MNXT, _______, _______, DSK_PRV, DSK_NXT, KC_SLEP, DF(GAME_B), XXXXXXX, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  DF(CMK),
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  SAI   |  $   |  @   |  [ { |  ] } |  \   |                              |  |   |  _   |  %   |  €   |  HUI |  VAI   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  SAD   |  #   |  !   |  (   |  )   |  /   |                              |   &  |  +   |  *   |  *   |  HUD |  VAD   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      | SC2  |  |      |      |   F7 |  F8  |  F9  |  F10 |  F11 | F12    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      RGB_SAI, KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_PIPE, KC_UNDS, KC_PERC,ALGR(KC_5),RGB_HUI,RGB_VAI,
      RGB_SAD, KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_SLSH,                                     KC_AMPR, KC_PLUS, KC_ASTR, KC_ASTR, RGB_HUD, RGB_VAD,
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, DF(SC2_B), XXXXXXX, RGB_MOD, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [SC2_B] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                        KC_GL,   _______, KC_GG,   _______, _______, _______,
      KC_ESC,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                        _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, LT(SC2_L, KC_SPC), _______, _______, _______, _______, _______
    ),

    [SC2_L] = LAYOUT(
      _______, KC_GRV,  KC_7,     KC_8,    KC_9,    KC_F1,                                       _______, _______, _______, _______, _______, _______,
      _______, _______, KC_4,     KC_5,    KC_6,    KC_F2,                                       _______, _______, _______, _______, _______, DF(QWE),
      _______, KC_LCTL, KC_1,     KC_2,    KC_3,    KC_F3,   _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, DF(CMK),
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [GAME_B] = LAYOUT(
      KC_TAB,  _______, KC_Q,    KC_W,    KC_E,    KC_R,                                        _______, _______, _______, _______, _______, _______,
      KC_ESC,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                                        _______, _______, _______, _______, _______, _______,
      KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_C,    _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_C, LT(GAME_L, KC_ENT), KC_LSFT, KC_SPC,  _______, _______, _______, _______, _______
    ),

    [GAME_L] = LAYOUT(
      KC_N,    KC_F1,   KC_4,     KC_5,    KC_6,    KC_LALT,                                     _______, _______, _______, _______, _______, _______,
      KC_Y,    KC_F2,   KC_1,     KC_2,    KC_3,    KC_J,                                        _______, _______, _______, _______, _______, DF(QWE),
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Set current OS indicator to Windows
        SEQ_ONE_KEY(KC_W) {
            user_config.osIsLinux = !user_config.osIsLinux;
            eeconfig_update_user(user_config.raw);
        }
    }
}

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
                SEND_STRING("\nGL HF\n");
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
    }
    return true;
}

uint16_t anim_timer = 0;
uint8_t current_anim_frame = 0;
uint16_t previous_wpm = 0;
uint16_t tic = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
    anim_timer = timer_read();
}

static void render_bongo_anim(void) {
    static const char PROGMEM frame[3][1024] = {
        {
            // bongocat frame 1
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0,
            0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
            0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x90, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x80,
            0xc0, 0xc0, 0x60, 0xe4, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x04, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0,
            0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xc4, 0xc0, 0x80, 0x80, 0x00,
            0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x04, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xdf,
            0xaf, 0xfe, 0x3d, 0x4c, 0xaf, 0x1f, 0x7d, 0xf1, 0xfb, 0xff, 0xfe, 0xf8, 0xf0, 0xe1, 0xe7, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x0f, 0x0f, 0x3f, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xfe, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f,
            0x1f, 0x1f, 0x3f, 0x3e, 0x3c, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
            0xff, 0xff, 0xf8, 0xf0, 0xf1, 0xf3, 0xf1, 0xf1, 0xe1, 0xc1, 0xc7, 0x8f, 0x8f, 0xcf, 0xcf, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f,
            0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xf0, 0xf8, 0xfc, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xc0, 0x04, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x01,
            0x01, 0x01, 0x03, 0x43, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x87, 0xc3, 0xf1, 0xf8, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf0,
            0x80, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x03, 0x0f, 0x0f, 0x1f, 0x1f,
            0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01,
            0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f,
            0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
        },
        {
            // bongocat frame 2
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8,
            0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
            0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x90, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0,
            0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe4, 0xc0, 0xc0, 0x80, 0x00,
            0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0x04, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x0f, 0x0f, 0x1f, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0xc0, 0xf0,
            0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
            0xff, 0xff, 0xf8, 0xf0, 0xf1, 0xf1, 0xf1, 0xf1, 0xe1, 0xc1, 0xc7, 0xcf, 0xcf, 0xc7, 0xcf, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0xff, 0xff,
            0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0xc7, 0xe7, 0x67, 0xe3, 0xe3, 0xe7, 0xe7, 0xc7, 0x8f, 0x1f, 0x3f,
            0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f,
            0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07,
            0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f,
            0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xff,
            0x07, 0x00, 0x00, 0xfe, 0xd7, 0xc7, 0xfe, 0x3d, 0xae, 0x4f, 0x1f, 0xf9, 0xfd, 0xfd, 0xff, 0xfe,
            0xf8, 0xf0, 0xe1, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf0, 0xc0, 0x84, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01,
            0x01, 0x01, 0x03, 0x43, 0x03, 0x03, 0x07, 0x07, 0x07, 0x47, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f,
            0x18, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7e, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
            0x80, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01,
            0x11, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f,
            0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00
        },
    };

    if (previous_wpm >= get_current_wpm()) {
        oled_write_raw_P(frame[current_anim_frame], sizeof(frame[2]));
    } else {
        if(timer_elapsed(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read();
            current_anim_frame = (current_anim_frame + 1) % ANIM_TOTAL_FRAMES;
            oled_clear();
            oled_write_raw_P(frame[abs((ANIM_NUM_FRAMES-1)-current_anim_frame)], 1024);
        }
    }
    tic++;
    if (tic == 1000) {
        tic = 0;
        previous_wpm = get_current_wpm();
    }
}

static void render_wpm_graph(uint8_t max_wpm, uint8_t graph_height) {
    static const uint8_t oled_row_count = OLED_DISPLAY_HEIGHT / OLED_FONT_HEIGHT;

    // Logic properties
    static uint16_t wpm_graph_timer = 0;
    static uint8_t inactivity_counter = 0;
    static uint8_t bar_count = 0;

    if (wpm_graph_timer == 0) {
        wpm_graph_timer = timer_read();
        return;
    }

    if(timer_elapsed(wpm_graph_timer) > 500) {
        wpm_graph_timer = timer_read();

        // WPM is read and clamped between [0, max_wpm]
        uint8_t wpm = get_current_wpm();
        if (wpm > max_wpm) {
            wpm = max_wpm;
        }

        // Inactivity check turns off the oled when no input is detected for a while.
        if(wpm == 0) {
            if (inactivity_counter > OLED_DISPLAY_WIDTH) {
                oled_off();
                return;
            } else {
                inactivity_counter++;
            }
        } else {
            inactivity_counter=0;
        }

        // Rendering the graph
        oled_pan(true);
        bar_count++;

        // Graph height is calculated from the ratio between the current and maximum wpm
        const uint8_t first_row = oled_row_count - graph_height;
        const uint8_t last_row = oled_row_count;
        uint8_t bar_height_px = (wpm * graph_height * OLED_FONT_HEIGHT) / max_wpm;

        // Refactor this if possible?
        for (uint8_t i = last_row; i > first_row; i--) {
            uint8_t bar_segment = 0;
            bool show_separator = i % 2 == 0 && bar_count % 3 == 0;

            if (bar_height_px > 7) {
                if (show_separator)
                    bar_segment = 254;
                else
                    bar_segment = 255;
                bar_height_px -= 8;
            } else {
                switch (bar_height_px) {
                    case 0:
                        bar_segment = 0;
                        break;
                    case 1:
                        bar_segment = 128;
                        break;
                    case 2:
                        bar_segment = 192;
                        break;
                    case 3:
                        bar_segment = 224;
                        break;
                    case 4:
                        bar_segment = 240;
                        break;
                    case 5:
                        bar_segment = 248;
                        break;
                    case 6:
                        bar_segment = 252;
                        break;
                    case 7:
                        bar_segment = 254;
                        break;
                }
                bar_height_px = 0;
                if (show_separator) {
                    bar_segment++;
                }
            }
            oled_write_raw_byte(bar_segment, i * OLED_DISPLAY_WIDTH - 1);
        }
    }
}

void render_default(void) {
    switch (get_highest_layer(default_layer_state)) {
        case QWE: oled_write_P(PSTR("Qwerty\n"), false); break;
        case CMK: oled_write_P(PSTR("Colemak-DHM\n"), false); break;
        case SC2_B: oled_write_P(PSTR("For the swarm\n"), false); break;
        case GAME_B: oled_write_P(PSTR("SHOOT\n"), false); break;
        default: oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case CMK:
            render_default();
            break;
        case LWR:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case RSE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case SC2_L:
            oled_write_P(PSTR("Select unit\n"), false);
            break;
        case GAME_L:
            oled_write_P(PSTR("Change weapon\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
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
        oled_write_P(PSTR("OS: Linux-mint\n"), false);
    } else {
        oled_write_P(PSTR("OS: Windows 10\n"), false);
    }
}

// OLED words per minute
void render_current_wpm(void) {
    char output[32] = "WPM:   ";
    uint8_t wpm = get_current_wpm();
    oled_write_with_int(output, wpm);
}

static void render_hsv(void) {
    char hue[32] = "HUE:   ";
    uint8_t huev = rgblight_get_hue();
    oled_write_with_int(hue, huev);

    char sat[32] = "SAT:   ";
    uint8_t satv = rgblight_get_sat();
    oled_write_with_int(sat, satv);

    char val[32] = "VAL:   ";
    uint8_t valv = rgblight_get_val();
    oled_write_with_int(val, valv);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_status();
        render_os();
        render_current_wpm();
        if (get_highest_layer(layer_state) == RSE) {
            render_hsv();
        } else {
            render_wpm_graph(100, 4);
        }
    } else {
        render_bongo_anim();
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
