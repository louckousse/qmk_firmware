#include <stdio.h>
#include QMK_KEYBOARD_H

typedef union {
    uint32_t raw;
    struct {
        bool osIsLinux;
    };
} user_config_t;

user_config_t user_config;

enum layers {
    CMK = 0,
    LWR,
    RSE,
    SC2_B,
    SC2_L,
    GAME_B,
    GAME_L,
    CMT,
    NAVMT,
    FUNMT,
    MRK,
    MEDR,
    NAVR,
    MOUR,
    NSSL,
    NSL,
    FUNL
};
