OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
LEADER_ENABLE = no        # Enable the Leader Key feature
MOUSEKEY_ENABLE = no
WPM_ENABLE = yes
LTO_ENABLE = yes

SRC += oled.c
SRC += encoder.c
