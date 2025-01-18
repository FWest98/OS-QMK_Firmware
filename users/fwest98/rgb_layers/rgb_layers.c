#include "rgb_layers.h"

#include <stdint.h>
#include "../rgb_helpers/rgb_helpers.h"

#ifdef RGB_MATRIX_LAYERS

uint8_t matrix_layers[] = { RGB_LAYERS, 255 };
uint8_t layer_colors[] = { RGB_LAYERS_COLORS };

bool rgb_matrix_indicators_advanced_layers(uint8_t led_min, uint8_t led_max) {
    uint8_t i = 0;
    while(matrix_layers[i] != 255) {
        uint8_t layers[2];
        layers[0] = matrix_layers[i];
        layers[1] = 255;

        if(!rgb_matrix_set_color_for_keycodes_on_layers(led_min, led_max, layers, all, layer_colors[3*i], layer_colors[3*i + 1], layer_colors[3*i + 2])) {
            return false;
        }

        i++;
    }

    return true;
}

#endif
