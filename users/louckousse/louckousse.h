#pragma once
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    CMT = 0,
    NAVMT,
    FUNMT,
    NUMMT,
    SYMMT,
    LWR,
    RSE,
    SC2_B,
    SC2_L,
    GAME_B,
    GAME_L
};

typedef union {
    uint32_t raw;
    struct {
        bool osIsLinux;
    };
} user_config_t;

user_config_t user_config;

#define KC_MED KC_MPLY
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
// Mod tap specific keycodes
#define NAV_DEL LT(NAVMT, KC_DEL)
#define FUN_ENT LT(FUNMT,KC_ENT)
#define NUM_SPC LT(NUMMT,KC_SPC)
#define SYM_BSP LT(SYMMT,KC_BSPC)
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

#define LAYOUT_kyria_pretty_wrapper(...) LAYOUT(__VA_ARGS__)
