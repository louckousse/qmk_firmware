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
#include QMK_KEYBOARD_H
#include "other.h"

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
    KC_TL,
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
      KC_SCLN, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_PAUS, C(KC_ENT),    LT(RSE, KC_ESC), KC_OS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH, KC_GRV,
          KC_MPLY, KC_LALT, CTL_T(KC_MINS), SFT_T(KC_ENT), LT(RSE, KC_DEL),   LT(LWR, KC_BSPC), SFT_T(KC_SPC), KC_RCTL, KC_RALT, KC_LGUI
    ),

/*
 * Lower Layer: Numpad, Symbol
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ~    |  $   |  @   |  [ { |  ] } |  \   |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |  SC2   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   `    |  #   |  !   |  (   |  )   |  /   |                              | *    | 4 $  | 5 %  | 6 ^  |  +   | Qwerty |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   '    |      |  €   |  {   |  }   |  |   |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  | Colemak|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LWR] = LAYOUT(
      KC_TL, KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, DF(GAME_B),
      KC_BT,   KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_SLSH,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_PLUS, DF(SC2_B),
      KC_QT,  _______,ALGR(KC_5),KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  DF(CMK),
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Media, nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Prns  | Home | cLeft| Up   | cRght| Pgup |                              |  F9  |  F10 |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Lock  | End  | Left | Down | Right| Pgdn |                              |  F5  |  F6  |  F7  |  F8  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Sleep |      |  <M  |  M>  | <D   | D>   |      |      |  |      |      |  F1  |  F2  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                                     KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
      LOCK,    KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,  _______, _______,
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
            break;
        case KC_BT:
            if(record->event.pressed) {
                tap_code16(KC_GRV);
                tap_code16(KC_SPC);
            }
            break;
        case KC_QT:
            if(record->event.pressed) {
                tap_code16(KC_QUOT);
                tap_code16(KC_SPC);
            }
            break;
        case KC_TL:
            if(record->event.pressed) {
                tap_code16(KC_TILD);
                tap_code16(KC_SPC);
            }
            break;
    }
    return true;
}
