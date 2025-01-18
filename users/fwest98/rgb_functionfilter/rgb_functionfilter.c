#include "rgb_functionfilter.h"

#include <stdint.h>
#include "../rgb_helpers/rgb_helpers.h"

#ifdef RGB_MATRIX_FUNCTIONFILTER

uint8_t functionfilter_layers[] = { FUNCTIONFILTER_LAYERS, 255 };

bool rgb_matrix_indicators_advanced_functionfilter(uint8_t led_min, uint8_t led_max) {
    uint8_t i = 0;
    while(functionfilter_layers[i] != 255) {
        uint8_t layers[2];
        layers[0] = functionfilter_layers[i];
        layers[1] = 255;

        if(!rgb_matrix_set_color_for_keycodes_on_layers(led_min, led_max, layers, is_transparent, RGB_OFF)) {
            return false;
        }

        i++;
    }

    return true;
}

#endif
