#include <stdint.h>
#include <stdio.h>
#include "action_layer.h"
#include "keyboard.h"
#include "keycodes.h"
#include "keymap_common.h"
#include "matrix.h"
#include "report.h"
#include "rgb_helpers.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"

keypos_t led_map_index_to_pos[RGB_MATRIX_LED_COUNT];

// We declare an overridable keymap-specific rgb matrix init function
__attribute__ ((weak)) void matrix_init_keymap(void) {}
__attribute__ ((weak)) void rgb_matrix_init_keymap(void) {}

void matrix_init_user() {
    matrix_init_keymap();

    rgb_matrix_init_user();
}

// We invert the default position to LED index mapping, which allows us
// to loop over the LEDs to enable and check their respective keycodes
void rgb_matrix_init_user(void) {
    rgb_matrix_init_keymap();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];

            if(led_index != NO_LED)
                led_map_index_to_pos[led_index] = (keypos_t) { .row = row, .col = col };
        }
    }
}

bool rgb_matrix_set_color_for_keycodes_on_layers(
    uint8_t led_min, uint8_t led_max,
    uint8_t active_layers[], bool (*should_set)(uint16_t),
    RGB_DEF
) {
    uint8_t current_layer = get_highest_layer(layer_state);

    // We activate on all layers if there are no special layers in our list
    if (active_layers[0] == 255) {
        rgb_matrix_set_color_for_keycodes(led_min, led_max, current_layer, should_set, RGB_VAL);
        return false;
    }

    int i = 0;
    while (active_layers[i] != 255) {
        if (active_layers[i] == current_layer) {
            rgb_matrix_set_color_for_keycodes(led_min, led_max, current_layer, should_set, RGB_VAL);

            return false;
        }

        i++;
    }

    return true;
}

// We have methods to set colors for specific keycodes
void rgb_matrix_set_color_for_keycode(
    uint8_t led_min, uint8_t led_max,
    uint8_t layer, uint16_t keycode,
    RGB_DEF
) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t current = keymap_key_to_keycode(layer, led_map_index_to_pos[i]);

        if(current == keycode) {
            rgb_matrix_set_color(i, RGB_VAL);
        }
    }
}

void rgb_matrix_set_color_for_keycodes(
    uint8_t led_min, uint8_t led_max,
    uint8_t layer, bool (*should_set)(uint16_t),
    RGB_DEF
) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t keycode = keymap_key_to_keycode(layer, led_map_index_to_pos[i]);

        if((*should_set)(keycode)) {
            rgb_matrix_set_color(i, RGB_VAL);
        }
    }
}

// Various keycode checkers
bool is_transparent(uint16_t keycode) {
    return keycode == KC_TRNS;
}

bool is_opaque(uint16_t keycode) {
    return !is_transparent(keycode);
}

bool is_num_lock_indicator(uint16_t keycode) {
    bool result = false;
    #ifdef INDICATORS_NUMLOCK_LIGHT_NUMS
        result = result || (KC_P1 <= keycode && keycode <= KC_P0) || keycode == KC_PDOT;
    #endif
    #ifdef INDICATORS_NUMLOCK_LIGHT_KEY
        result = result || keycode == KC_NUM_LOCK;
    #endif

    return result;
}

bool is_caps_lock_indicator(uint16_t keycode) {
    bool result = false;
    #ifdef INDICATORS_CAPSLOCK_LIGHT_ALPHAS
        result = result || (KC_A <= keycode && keycode <= KC_Z);
    #endif
    #ifdef INDICATORS_CAPSLOCK_LIGHT_KEY
        result = result || keycode == KC_CAPS;
    #endif
    #ifdef INDICATORS_CAPSLOCK_LIGHT_UNICODE_PAIRS
        result = result || keycode >= QK_UNICODEMAP_PAIR;
    #endif

    return result;
}

bool all(uint16_t keycode) { return true; }
