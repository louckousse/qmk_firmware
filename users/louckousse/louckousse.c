#include "louckousse.h"

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
    }
    return true;
}

enum combos {
  JM_QUOT,
  BG_GRV,
  GV_CIRC,
  JL_MINS
};

const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM bg_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM gv_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JM_QUOT] = COMBO(jm_combo, KC_QUOT),
  [BG_GRV] = COMBO(bg_combo, KC_GRV),
  [GV_CIRC] = COMBO(gv_combo, KC_CIRC),
  [JL_MINS] = COMBO(jl_combo, KC_MINS)
};
