#pragma once
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define ______________COLEMAK_DH_MT_L1_____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_DH_MT_L2_____________       MK_A,    MK_R,    MK_S,    MK_T,    KC_G
#define ______________COLEMAK_DH_MT_L3_____________       KC_Z,    MK_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_DH_MT_R1_____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_DH_MT_R2_____________       KC_M,    MK_N,    MK_E,    MK_I,    MK_O
#define ______________COLEMAK_DH_MT_R3_____________       KC_K,    KC_H,    KC_COMM, MK_DOT,  KC_SLASH

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
#define ___________________MOD_L___________________        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______
#define ___________________MOD_R___________________        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI

#define __________________SYM_L1___________________        KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS
#define __________________SYM_L2___________________        KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_PIPE
#define __________________SYM_L3___________________        KC_PERC, KC_EUR,  KC_LCBR, KC_RCBR, KC_AMPR

#define ________________NUMBER_L1__________________        KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS
#define ________________NUMBER_L2__________________        KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS
#define ________________NUMBER_L3__________________        KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL

#define __________________NAV_L1___________________        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP
#define __________________NAV_L2___________________        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define __________________NAV_L3___________________        KC_MPRV, KC_MPLY, KC_MNXT, DSK_PRV, DSK_NXT

#define __________________FUN_L1___________________        KC_F9,   KC_F10,  KC_F11,  KC_F12,  PRINT
#define __________________FUN_L2___________________        KC_F5,   KC_F6,   KC_F7,   KC_F8,   LOCK
#define __________________FUN_L3___________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SLEP

#define __________________NROW_L___________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __________________NROW_R___________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
