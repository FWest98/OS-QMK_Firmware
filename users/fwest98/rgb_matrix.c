#include "rgb_matrix.h"
#include <stdint.h>
#include "rgb_helpers/rgb_helpers.h"
#include "rgb_functionfilter/rgb_functionfilter.h"
#include "rgb_indicators/rgb_indicators.h"
#include "rgb_layers/rgb_layers.h"

// We declare an overridable keymap-specific rgb matrix indicators function
__attribute__ ((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }

    bool tookEffect = false;

    #ifdef RGB_MATRIX_LAYERS
    tookEffect = tookEffect || !rgb_matrix_indicators_advanced_layers(led_min, led_max);
    #endif

    #ifdef RGB_MATRIX_INDICATORS
    tookEffect = tookEffect || !rgb_matrix_indicators_advanced_indicators(led_min, led_max);
    #endif

    #ifdef RGB_MATRIX_FUNCTIONFILTER
    tookEffect = tookEffect || !rgb_matrix_indicators_advanced_functionfilter(led_min, led_max);
    #endif

    return !tookEffect;
}
