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
#include "louckousse.h"

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

    [CMT] = LAYOUT_kyria_pretty_wrapper(
      KC_TAB,  ______________COLEMAK_DH_MT_L1_____________,                                     ______________COLEMAK_DH_MT_R1_____________,  KC_CIRC,
      KC_ESC,  ______________COLEMAK_DH_MT_L2_____________,                                     ______________COLEMAK_DH_MT_R2_____________,  KC_QUOT,
      KC_CAPS, ______________COLEMAK_DH_MT_L3_____________, KC_RALT, KC_PAUS, PRINT,   KC_OS,   ______________COLEMAK_DH_MT_R3_____________,  KC_GRV,
                                 XXXXXXX, XXXXXXX, KC_MINS, FUN_ENT, NAV_DEL, SYM_BSP, NUM_SPC, KC_TAB,  XXXXXXX, XXXXXXX
    ),

    [FUNMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________FUN_L1___________________,                                     ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L2___________________,                                     ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_ALGR, _______, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [NAVMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________NAV_L1___________________,                                     KC_CIRC, GO_GAME, KC_OS,   GO_SC2,  _______, XXXXXXX,
      XXXXXXX, __________________NAV_L2___________________,                                     KC_QUOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
      XXXXXXX, __________________NAV_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  _______, _______, KC_ALGR, _______, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_SPC,  KC_ENT, XXXXXXX, XXXXXXX
    ),

    [SYMMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________SYM_L1___________________,                                     ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L2___________________,                                     ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ________________NUMBER_L3__________________, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [NUMMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, ___________________BLANK___________________,                                     ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, ___________________MOD_L___________________,                                     ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, _______, KC_ALGR, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ________________NUMBER_L3__________________,  XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [LWR] = LAYOUT_kyria_pretty_wrapper(
      KC_TL,   __________________SYM_L1___________________,                                     ________________NUMBER_L1__________________, KC_COMM,
      KC_BT,   __________________SYM_L2___________________,                                     ________________NUMBER_L2__________________, KC_DOT,
      KC_QT,   __________________SYM_L3___________________, _______, _______, GO_GAME, _______, ________________NUMBER_L3__________________,  _______,
                                 ___________________BLANK___________________, ___________________BLANK___________________
    ),

    [RSE] = LAYOUT_kyria_pretty_wrapper(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                                     KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
      LOCK,    KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,  _______, _______,
      KC_SLEP, _______, KC_MPRV, KC_MNXT, DSK_PRV, DSK_NXT, _______, GO_SC2,  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______, _______,
                                 ___________________BLANK___________________, ___________________BLANK___________________
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
      _______, KC_LCTL, KC_1,     KC_2,    KC_3,    KC_F3,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
      KC_P,    KC_F3,   KC_7,     KC_8,    KC_9,    KC_M,    _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
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

