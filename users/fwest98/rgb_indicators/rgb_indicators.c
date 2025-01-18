#include <stdint.h>
#include "action_layer.h"
#include "bitwise.h"
#include "../rgb_helpers/rgb_helpers.h"
#include "caps_word.h"
#include "host.h"

#ifdef RGB_MATRIX_INDICATORS

#ifdef INDICATORS_NUMLOCK_ACTIVE_LAYERS
uint8_t numlock_active_layers[] = { INDICATORS_NUMLOCK_ACTIVE_LAYERS, 255 };
#else
uint8_t numlock_active_layers[] = { 255 };
#endif

#ifdef INDICATORS_NUMLOCK_LIGHT_NUMS
bool numlock_indicators = true;
#else
#ifdef INDICATORS_NUMLOCK_LIGHT_KEY
bool numlock_indicators = true;
#else
bool numlock_indicators = false;
#endif
#endif

#ifndef INDICATORS_NUMLOCK_COLOR
#define INDICATORS_NUMLOCK_COLOR RGB_OFF
#endif

#ifdef INDICATORS_NUMLOCK_INVERTED
bool numlock_inverted = true;
#else
bool numlock_inverted = false;
#endif

#ifdef INDICATORS_CAPSLOCK_ACTIVE_LAYERS
uint8_t capslock_active_layers[] = { INDICATORS_CAPSLOCK_ACTIVE_LAYERS, 255 };
#else
uint8_t capslock_active_layers[] = { 255 };
#endif

#ifdef INDICATORS_CAPSLOCK_LIGHT_ALPHA
bool capslock_indicators = true;
#else
#ifdef INDICATORS_CAPSLOCK_LIGHT_KEY
bool capslock_indicators = true;
#else
bool capslock_indicators = false;
#endif
#endif

#ifndef INDICATORS_CAPSLOCK_COLOR
#define INDICATORS_CAPSLOCK_COLOR RGB_OFF
#endif

#ifdef INDICATORS_CAPSLOCK_INVERTED
bool capslock_inverted = true;
#else
bool capslock_inverted = false;
#endif

bool rgb_matrix_indicators_advanced_indicators(uint8_t led_min, uint8_t led_max) {
    bool tookEffect = false;

    if(numlock_indicators) {
        if((host_keyboard_led_state().num_lock && !numlock_inverted) || (!host_keyboard_led_state().num_lock && numlock_inverted)) {
            tookEffect = tookEffect || !rgb_matrix_set_color_for_keycodes_on_layers(led_min, led_max, numlock_active_layers, is_num_lock_indicator, INDICATORS_NUMLOCK_COLOR);
        }
    }

    if(capslock_indicators) {
        bool is_capslock = host_keyboard_led_state().caps_lock || is_caps_word_on();
        if((is_capslock && !capslock_inverted) || (!is_capslock && capslock_inverted)) {
            tookEffect = tookEffect || !rgb_matrix_set_color_for_keycodes_on_layers(led_min, led_max, capslock_active_layers, is_caps_lock_indicator, INDICATORS_CAPSLOCK_COLOR);
        }
    }

    return !tookEffect;
}

#endif
