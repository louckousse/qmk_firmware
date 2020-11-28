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

