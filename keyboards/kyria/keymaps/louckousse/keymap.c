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
 * |  Prns  | Home | cLeft| Up   | cRght| Pgup |                              |  F9  |  F10 |  F11 |  F12 |  SAI |  VAI   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Lock  | End  | Left | Down | Right| Pgdn |                              |  F5  |  F6  |  F7  |  F8  |      |  HUI   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Sleep |      |  <M  |  M>  | <D   | D>   |      |      |  |      |      |  F1  |  F2  |  F2  |  F3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [RSE] = LAYOUT(
      PRINT, KC_HOME,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_PGUP,                                     KC_F9,   KC_F10,  KC_F11,  KC_F12, RGB_SAI, RGB_VAI,
      LOCK,    KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     KC_F5,   KC_F6,   KC_F7,   KC_F8,  _______, RGB_HUI,
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 20 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 35 // above this wpm value typing animation to trigger

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024
#define LINE_SIZE 128

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
#define FRAME_SIZE 636
static const uint16_t PROGMEM diff_regions_boundaries[9] = {58, 58, 58, 84, 92, 100, 120, 152, 174};
static const uint16_t PROGMEM diff_regions[174] = {2, 8, 9, 15, 16, 22, 23, 25, 26, 32, 58, 79, 125, 128, 132, 159, 177, 186, 190, 192, 201, 202, 203, 205, 206, 216, 219, 253, 258, 261, 262, 285, 286, 289, 304, 308, 315, 320, 321, 347, 365, 380, 386, 389, 390, 413, 414, 451, 493, 508, 512, 543, 621, 625, 626, 631, 632, 636, 58, 69, 71, 74, 75, 79, 177, 181, 183, 187, 190, 192, 201, 202, 203, 205, 206, 216, 304, 308, 315, 320, 323, 330, 334, 338, 51, 53, 69, 76, 177, 183, 304, 307, 69, 70, 71, 77, 177, 181, 304, 307, 51, 53, 69, 76, 177, 183, 185, 188, 206, 217, 304, 307, 310, 321, 322, 323, 336, 345, 441, 451, 51, 53, 69, 76, 86, 90, 95, 97, 177, 183, 185, 188, 206, 210, 214, 218, 219, 227, 304, 307, 310, 321, 322, 323, 346, 355, 416, 417, 441, 451, 477, 480, 51, 53, 69, 76, 177, 183, 206, 217, 304, 307, 315, 319, 336, 345, 433, 441, 448, 452, 565, 572, 576, 584};
static const uint16_t PROGMEM diff_bytes_boundaries[9] = {336, 336, 336, 397, 415, 429, 492, 570, 639};
static const char PROGMEM diff_bytes[639] = {126, 126, 24, 60, 102, 66, 12, 28, 112, 112, 28, 12, 116, 116, 20, 20, 124, 104, 124, 124, 112, 120, 44, 36, 124, 124, 128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 4, 4, 4, 8, 48, 64, 128, 128, 128, 128, 192, 96, 48, 24, 12, 132, 198, 98, 35, 51, 17, 145, 113, 241, 113, 145, 17, 51, 35, 98, 198, 132, 12, 24, 48, 96, 192, 24, 100, 130, 2, 2, 2, 2, 2, 1, 128, 128, 128, 48, 48, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 196, 4, 196, 4, 196, 2, 194, 2, 194, 1, 1, 1, 1, 252, 15, 1, 248, 14, 31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109, 31, 14, 248, 1, 15, 252, 192, 56, 4, 3, 12, 12, 12, 13, 1, 64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8, 8, 4, 4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 170, 170, 255, 255, 195, 191, 127, 3, 127, 191, 195, 255, 255, 170, 170, 31, 120, 192, 15, 56, 124, 219, 152, 20, 20, 18, 50, 207, 3, 255, 3, 207, 50, 18, 20, 20, 152, 219, 124, 56, 15, 192, 120, 31, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8, 8, 8, 8, 7, 2, 130, 135, 31, 7, 159, 7, 28, 7, 159, 7, 159, 7, 2, 130, 32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98, 102, 68, 68, 71, 71, 71, 68, 68, 102, 98, 35, 49, 16, 24, 12, 6, 3, 1, 7, 8, 8, 23, 15, 1, 2, 1, 15, 15, 2, 5, 8, 0, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 4, 2, 2, 24, 96, 128, 0, 60, 194, 1, 1, 4, 4, 2, 1, 0, 0, 0, 96, 96, 129, 130, 130, 132, 8, 16, 32, 64, 128, 0, 128, 112, 25, 6, 24, 24, 24, 27, 3, 34, 36, 20, 18, 18, 18, 11, 5, 5, 9, 9, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 128, 112, 12, 8, 4, 2, 2, 2, 4, 56, 28, 226, 1, 1, 128, 112, 12, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 24, 6, 5, 152, 153, 132, 195, 124, 65, 65, 64, 32, 4, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 8, 4, 2, 1, 1, 2, 12, 248, 248, 248, 248, 128, 128, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 1, 2, 67, 135, 7, 1, 184, 188, 190, 159, 95, 95, 79, 76, 128, 112, 12, 24, 6, 5, 152, 153, 132, 67, 124, 65, 65, 64, 32, 61, 124, 252, 252, 252, 252, 252, 60, 12, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 0, 0, 0, 1, 4, 4, 4, 4, 2, 2, 2, 1, 1, 122, 122, 121, 121, 121, 121, 57, 49, 136, 136, 135, 128, 48, 120, 124, 254, 255, 63, 7, 255, 255, 127, 127, 63, 62, 28, 24};

void write_frame(const uint16_t* regions, const uint16_t regions_len, const char* diff, const uint16_t diff_len) {
	uint16_t diff_index = 0;
	for (uint16_t region_index = 0; region_index < regions_len; region_index += 2) {
		uint16_t start = pgm_read_word_near(regions + region_index);
		uint16_t end = pgm_read_word_near(regions + region_index + 1);
		oled_write_raw_range_P(diff + diff_index,start , end);
		diff_index += end - start;
	}
}

void write_frame_diff(const uint16_t region_begin, const uint16_t region_end, const uint16_t bytes_begin) {
	uint16_t diff_index = 0;
	for (uint16_t region_index = region_begin; region_index < region_end; region_index += 2) {
		uint16_t start = pgm_read_word_near(&diff_regions[region_index]);
		uint16_t end = pgm_read_word_near(&diff_regions[region_index + 1]);
		oled_write_raw_range_P(&diff_bytes[bytes_begin + diff_index], start, end);
		diff_index += end - start;
	}
}

void write_base_frame(void) {
	oled_clear();
	const uint16_t region_begin = 0;
	const uint16_t region_end = pgm_read_word_near(&diff_regions_boundaries[0]);
	const uint16_t bytes_begin = 0;
	write_frame_diff(region_begin, region_end, bytes_begin);
}

void write_frame_at_index(int index) {
	write_base_frame();
	const uint16_t region_begin = pgm_read_word_near(&diff_regions_boundaries[index]);
	const uint16_t region_end = pgm_read_word_near(&diff_regions_boundaries[index + 1]);
	const uint16_t bytes_begin = pgm_read_word_near(&diff_bytes_boundaries[index]);
	write_frame_diff(region_begin, region_end, bytes_begin);
}

static void render_anim(void) {
  void animation_phase(void) {
    if(get_current_wpm() <=IDLE_SPEED){
        current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
		int index = abs(IDLE_FRAMES - 1 - current_idle_frame);
		write_frame_at_index(index);
     }
     if(get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED){
	     int index = IDLE_FRAMES;
		 write_frame_at_index(index);
     }
     if(get_current_wpm() >= TAP_SPEED){
         current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
		 int index = IDLE_FRAMES + 1 + abs(TAP_FRAMES - 1 - current_tap_frame);
         write_frame_at_index(index);
     }
  }

  if(get_current_wpm() != 0) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress

        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
			oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
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
