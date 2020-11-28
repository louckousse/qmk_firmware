#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    MED = 0,
    LED,
};

enum custom_keycodes {
    HS_PCB = SAFE_RANGE,
    HS_CASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MED] = LAYOUT(
                 TO(LED),  KC_WBAK,  KC_WFWD,
                 RGB_HUI,  RGB_SAI,  RGB_VAI,
                 KC_LSFT,  KC_MUTE,  AU_TOG,
                 KC_MPRV,  KC_MPLY,  KC_MNXT),
    [LED] = LAYOUT(
                 TO(MED),  RGB_TOG,  KC_WFWD,
                 RGB_HUI,  RGB_SAI,  RGB_VAI,
                 RGB_HUD,  RGB_SAD,  RGB_VAD,
                 RGB_MOD,  RGB_RMOD, KC_MNXT)
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void display_led_layer(void) {
    oled_write_P(PSTR("It's Disco Time\n"), false);
    oled_write_P(PSTR("Mode:  "), false);

    int mode = rgblight_get_mode();

    if (mode >= RGBLIGHT_MODE_BREATHING && mode <=RGBLIGHT_MODE_BREATHING + 3) {
        oled_write_P(PSTR("BREATHING\n"), false);
    } else if (mode >= RGBLIGHT_MODE_RAINBOW_MOOD && mode <= RGBLIGHT_MODE_RAINBOW_MOOD + 2) {
        oled_write_P(PSTR("RAINBOW\n"), false);
    } else if (mode >= RGBLIGHT_MODE_KNIGHT && mode <= RGBLIGHT_MODE_KNIGHT + 2) {
        oled_write_P(PSTR("KNIGHT\n"), false);
    } else if (mode == RGBLIGHT_MODE_CHRISTMAS) {
        oled_write_P(PSTR("CHRISTMAS\n"), false);
    } else if (mode >= RGBLIGHT_MODE_STATIC_GRADIENT && mode <= RGBLIGHT_MODE_STATIC_GRADIENT + 9) {
        oled_write_P(PSTR("GRADIENT\n"), false);
    } else {
        oled_write_P(PSTR("BASE\n"), false);
    }

    static char hsvVal[21] = {0};
    snprintf(hsvVal, sizeof(hsvVal), "h:%d s:%d v:%d %d", rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), rgblight_get_mode());
    oled_write_ln(hsvVal, false);
}

static void render_layer_status(void) {
    switch (get_highest_layer(layer_state)) {
        case MED:
            oled_write_P(PSTR("Media Player\n"), false);
            oled_write_ln(" ", false);
            oled_write_ln(" ", false);
            oled_write_ln(" ", false);
            break;
        case LED:
            display_led_layer();
            break;
        default:
            oled_write_P(PSTR("Base\n"), false);
            oled_write_ln(" ", false);
            oled_write_ln(" ", false);
            oled_write_ln(" ", false);
    }
}

void oled_task_user(void) {
    render_layer_status();
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
