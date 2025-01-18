#pragma once

#include <stdint.h>
#include "color.h"

#define RGB_DEF uint8_t red, uint8_t green, uint8_t blue
#define RGB_VAL red, green, blue

bool rgb_matrix_set_color_for_keycodes_on_layers(
    uint8_t led_min, uint8_t led_max,
    uint8_t active_layers[], bool (*should_set)(uint16_t),
    RGB_DEF
);

void rgb_matrix_set_color_for_keycode(
    uint8_t led_min, uint8_t led_max,
    uint8_t layer, uint16_t keycode,
    RGB_DEF
);

void rgb_matrix_set_color_for_keycodes(
    uint8_t led_min, uint8_t led_max,
    uint8_t layer, bool (*should_set)(uint16_t),
    RGB_DEF
);

bool is_transparent(uint16_t keycode);
bool is_opaque(uint16_t keycode);
bool is_num_lock_indicator(uint16_t keycode);
bool is_caps_lock_indicator(uint16_t keycode);
bool all(uint16_t keycode);

void rgb_matrix_init_user(void);
