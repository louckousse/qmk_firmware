/* Copyright 2020 louckousse
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

enum {
    TD_UNO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            TD(TD_UNO)
          )
};

// void dance_each(qk_tap_dance_state_t *state, void *user_data) {
//     switch (state->count) {
//         case 1:
//             SEND_STRING("Comment vas-tu ?");
//             register_code(KC_ENT);
//             unregister_code(KC_ENT);
//             break;
//         case 2:
//             SEND_STRING("send two");
//             rgblight_enable_noeeprom();
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
//             break;
//     }
// }

void dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("One string");
            register_code(KC_ENT);
            unregister_code(KC_ENT);
            break;
        case 2:
            SEND_STRING("another String");
            register_code(KC_ENT);
            unregister_code(KC_ENT);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
            break;
        default:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(0, 0, 50);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            reset_keyboard();
    }
}

// If the flash state didn't happen, then turn off LEDs, left to right
void dance_reset(qk_tap_dance_state_t *state, void *user_data) {
}

// All tap dances now put together. Example 3 is "CT_FLASH"
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_UNO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_finished, dance_reset)
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(225, 240, 50);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
