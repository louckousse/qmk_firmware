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

#define KC_MED TD(0)
#define ST_ENT SFT_T(KC_ENT)
#define CTRL_MN CTL_T(KC_MINS)
#define ALT_BO ALT_T(KC_LBRC)
#define ALT_BE ALT_T(KC_RBRC)
#define RSE_DEL LT(RSE, KC_DEL)
#define LWR_BSP LT(LWR, KC_BSPC)
#define ST_SPC SFT_T(KC_SPC)
#define GO_SC2 DF(SC2_B)
#define GO_GAME DF(GAME_B)
#define KC_EUR ALGR(KC_5)
// Myryoku specific keycodes
#define MK_A LGUI_T(KC_A)
#define MK_R LALT_T(KC_R)
#define MK_S LCTL_T(KC_S)
#define MK_T LSFT_T(KC_T)
#define MK_N LSFT_T(KC_N)
#define MK_E LCTL_T(KC_E)
#define MK_I LALT_T(KC_I)
#define MK_O LGUI_T(KC_O)
#define MK_X ALGR_T(KC_X)
#define MK_DOT ALGR_T(KC_DOT)
#define KC_NP KC_NO // key is not present
#define KC_NA KC_NO // present but not available for use
#define KC_NU KC_NO // available but not used

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
 * | Caps |   Z  |   X  |   C  |   D  |   V  | Altgr| Pause|  | Prnt |  OS  |   K  |   H  | ,  < | . >  | /  ? | ` ~  |
 * `--------------------+------+------+------+------+------|  |------|------+------+------+------+--------------------'
 *                      | Play | Alt  | Ctrl | Shift| Lower|  | Lower| Shift| Ctrl | Alt  | GUI  |
 *                      |      |      |  - _ | Del  | Enter|  | Space| Space|      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [CMK] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_CIRC,
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
      KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_RALT, KC_PAUS, PRINT,   KC_OS,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_GRV,
                                 KC_MED,  ALT_BO,  CTRL_MN, ST_ENT,  RSE_DEL, LWR_BSP, ST_SPC,  KC_RCTL, ALT_BE,  KC_LGUI
    ),

/*
 * Lower Layer: Numpad, Symbol
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ~    |  $   |  @   |  [ { |  ] } |  \   |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |  , <   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   `    |  #   |  !   |  (   |  )   |  |   |                              | *    | 4 $  | 5 %  | 6 ^  |  +   |  . >   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   '    |  %   |  €   |  {   |  }   |  &   |      |      |  |  FPS |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  | Colemak|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [LWR] = LAYOUT(
      KC_TL,   KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_COMM,
      KC_BT,   KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_PIPE,                                     KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_DOT,
      KC_QT,   KC_PERC, KC_EUR,  KC_LCBR, KC_RCBR, KC_AMPR, _______, DF(MRK), GO_GAME, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  DF(CMK),
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
 * |  Sleep |      |  <M  |  M>  | <D   | D>   |      |  SC2 |  |      |      |  F1  |  F2  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                                     KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,
      LOCK,    KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,  _______, _______,
      KC_SLEP, _______, KC_MPRV, KC_MNXT, DSK_PRV, DSK_NXT, _______, GO_SC2,  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  _______, _______,
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

    [MRK] = LAYOUT(
      XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,  XXXXXXX,
      XXXXXXX, MK_A,    MK_R,    MK_S,    MK_T,    KC_G,                                        KC_M,    MK_N,    MK_E,    MK_I,    MK_O,     XXXXXXX,
      XXXXXXX, KC_Z,    MK_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, DF(CMK), XXXXXXX, XXXXXXX, KC_K,    KC_H,    KC_COMM, MK_DOT,  KC_SLSH,  XXXXXXX,
      XXXXXXX, XXXXXXX, LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  XXXXXXX, XXXXXXX
    ),

    [NAVR] = LAYOUT(
        XXXXXXX, RESET,   KC_NA,   XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, KC_NA,   KC_ALGR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),

    [MOUR] = LAYOUT(
        XXXXXXX, RESET,   KC_NA,   KC_NA,   KC_NA,   KC_NA,                                       KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,                                       KC_NU,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
        XXXXXXX, KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NU,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX
    ),

    [MEDR] = LAYOUT(
        XXXXXXX, RESET,   KC_NA,   KC_NA,   KC_NA,   KC_NA,                                       RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,                                       KC_NU,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_NA,   KC_NA,   KC_NA,   KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
    ),

    [FUNL] = LAYOUT(
        XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                                     KC_NA,   KC_NA,   KC_NA,   KC_NA,   RESET,   XXXXXXX,
        XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                                     KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
        XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,   XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_APP,  KC_SPC,  KC_TAB,  KC_NA,   KC_NA,   KC_NA,   XXXXXXX, XXXXXXX
    ),

    [NSL] = LAYOUT(
        XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                     KC_NA,   KC_NA,   KC_NA,   KC_NA,   RESET,   XXXXXXX,
        XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                      KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
        XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,   XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_DOT,  KC_0,    KC_MINS, KC_NA,   KC_NA,   KC_NA,   XXXXXXX, XXXXXXX
    ),

    [NSSL] = LAYOUT(
        XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     KC_NA,   KC_NA,   KC_NA,   KC_NA,   RESET,   XXXXXXX,
        XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
        XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,   XXXXXXX,
                                   XXXXXXX, XXXXXXX, KC_GT,   KC_RPRN, KC_UNDS, KC_NA,   KC_NA,   KC_NA,   XXXXXXX, XXXXXXX
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

void media(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code(KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance(state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_FN(media),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MED:
            return 3000; break;
        default:
            return TAPPING_TERM;
    }
}
