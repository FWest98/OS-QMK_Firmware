#include QMK_KEYBOARD_H
#include "keychron_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_1] = LAYOUT_numpad_6x5(
        KC_MUTE,    RGB_TOG,  KC_ESC,  KC_BSPC,  KC_TAB,
        MO(FN_1),   KC_NUM,   KC_PSLS, KC_PAST,  KC_PMNS,
        TO(BASE_2), KC_P7,    KC_P8,   KC_P9,    KC_PPLS,
        TO(BASE_3), KC_P4,    KC_P5,   KC_P6,
        TO(BASE_4), KC_P1,    KC_P2,   KC_P3,    KC_PENT,
        TO(BASE_5), KC_P0,             KC_PDOT),

    [FN_1] = LAYOUT_numpad_6x5(
        RGB_TOG, _______,  KC_MUTE, KC_VOLD,  KC_VOLU,
        _______, RGB_MOD,  RGB_VAI, RGB_HUI,  KC_DEL,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD,  _______,
        _______, RGB_SAI,  RGB_SPI, KC_MPRV,
        _______, RGB_SAD,  RGB_SPD, KC_MPLY,  _______,
        _______, RGB_TOG,           KC_MNXT),

    [BASE_2] = LAYOUT_numpad_6x5(
        XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_1), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        MO(FN_2),   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_3), XXXXXXX,  XXXXXXX, XXXXXXX,
        TO(BASE_4), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_5), XXXXXXX,           XXXXXXX),

    [FN_2] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,           _______),

    [BASE_3] = LAYOUT_numpad_6x5(
        XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_1), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_2), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        MO(FN_3),   XXXXXXX,  XXXXXXX, XXXXXXX,
        TO(BASE_4), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_5), XXXXXXX,           XXXXXXX),

    [FN_3] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,           _______),

    [BASE_4] = LAYOUT_numpad_6x5(
        XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_1), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_2), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_3), XXXXXXX,  XXXXXXX, XXXXXXX,
        MO(FN_4),   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_5), XXXXXXX,           XXXXXXX),

    [FN_4] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,           _______),

    [BASE_5] = LAYOUT_numpad_6x5(
        XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_1), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_2), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(BASE_3), XXXXXXX,  XXXXXXX, XXXXXXX,
        TO(BASE_4), XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
        MO(FN_5),   XXXXXXX,           XXXXXXX),

    [FN_5] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,           _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE_1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN_1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [BASE_2] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FN_2]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [BASE_3] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FN_3]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [BASE_4] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FN_4]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [BASE_5] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [FN_5]   = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    return true;
}
