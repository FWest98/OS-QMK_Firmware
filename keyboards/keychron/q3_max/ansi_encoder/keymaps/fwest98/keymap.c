/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"
#include "rgb_helpers/rgb_helpers.h"
#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum unicode_names {
    ALPHA, BETA, GAMMA, GGAMMA, DELTA, DDELTA, EPSILON, ZETA, ETA, THETA, TTHETA, IOTA,
    KAPPA, LAMBDA, LLAMBDA, MU, NU, XI, XXI, PI, PPI, RHO, SIGMA, SSIGMA, TAU, UPSILON,
    PHI, PPHI, PHIALT, XHI, PSI, PPSI, OMEGA, OOMEGA,

    CDOT, LNOT, FORALL, EXISTS, NEXISTS, EMPTYSET, NABLA, ELEM, NELEM, LAND, LOR, IMPL,
    RIMPL, CAP, CUP, OTIMES, OPLUS, OMINUS, ODOT, O, OCIRC, NAT, ZET, Q, REAL, COMPLEX,
    TIMES, DIAMOND, BOX, TOP, BOT
};

const uint32_t PROGMEM unicode_map[] = {
    [ALPHA] = 0x03B1, [BETA] = 0x03B2, [GAMMA] = 0x03B3, [GGAMMA] = 0x0393, [DELTA] = 0x03B4, [DDELTA] = 0x0394,
    [EPSILON] = 0x03B5, [ZETA] = 0x03B6, [ETA] = 0x03B7, [THETA] = 0x03B8, [TTHETA] = 0x0398, [IOTA] = 0x03B9,
    [KAPPA] = 0x03BA, [LAMBDA] = 0x03BB, [LLAMBDA] = 0x039B, [MU] = 0x03BC, [NU] = 0x03BD, [XI] = 0x03BE,
    [XXI] = 0x039E, [PI] = 0x03C0, [PPI] = 0x03A0, [RHO] = 0x03C1, [SIGMA] = 0x03C3, [SSIGMA] = 0x03A3,
    [TAU] = 0x03C4, [UPSILON] = 0x03C5, [PHI] = 0x03C6, [PPHI] = 0x03A6, [PHIALT] = 0x03D5, [XHI] = 0x03C7,
    [PSI] = 0x03C8, [PPSI] = 0x03A8, [OMEGA] = 0x03C9, [OOMEGA] = 0x03A9,

    [CDOT] = 0x22C5, [LNOT] = 0x00AC, [FORALL] = 0x2200, [EXISTS] = 0x2203, [NEXISTS] = 0x2204,
    [EMPTYSET] = 0x2205, [NABLA] = 0x2207, [ELEM] = 0x2208, [NELEM] = 0x2209, [LAND] = 0x2227,
    [LOR] = 0x2228, [IMPL] = 0x2192, [RIMPL] = 0x2190, [CAP] = 0x2229, [CUP] = 0x222A, [OTIMES] = 0x2297,
    [OPLUS] = 0x2295, [NAT] = 0x2115, [ZET] = 0x2124, [Q] = 0x211A, [REAL] = 0x211D, [COMPLEX] = 0x2102,
    [OMINUS] = 0x2296, [TIMES] = 0x00D7, [OCIRC] = 0x229A, [ODOT] = 0x2299, [O] = 0x2218,
    [DIAMOND] = 0x25CA, [BOX] = 0x25A1, [TOP] = 0x22A4, [BOT] = 0x22A5
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_F13,   KC_CALC,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_DEL,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        CW_TOGG,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,              KC_UP,
        SC_LCPO,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  OSL(GREEK),  LT(WIN_FN, KC_NO),   SC_RCPC,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  EE_CLR,   KC_APP,   QK_BOOT,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [GREEK] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  UP(PSI, PPSI),  UM(ETA),  UM(EPSILON),  UM(RHO),  UM(TAU),  UP(THETA, TTHETA),  UM(UPSILON),  UM(IOTA),  UP(OMEGA, OOMEGA),  UP(PI, PPI),  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  UM(ALPHA), UP(SIGMA, SSIGMA),  UP(DELTA, DDELTA),  UP(PHI, PPHI),  UP(GAMMA, GGAMMA),  UM(PHIALT),  _______,  UM(KAPPA),  UP(LAMBDA, LLAMBDA),  _______,  _______,              _______,
        KC_LSFT,            UM(ZETA),  UP(XI, XXI),  UM(XHI),  _______,  UM(BETA),  UM(NU),  UM(MU),  _______,  _______,  _______,              KC_RSFT,            _______,
        _______,  _______,  _______,                                _______,                                _______,  TO(WIN_BASE),  _______,    _______,  _______,  _______,  _______),

    [MATH] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  UM(LNOT),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  UM(EMPTYSET),  UM(OMINUS),  UM(OPLUS),    _______,  _______,  _______,  _______,
        UP(IMPL, RIMPL),  UM(Q),  _______,  UP(EXISTS, NEXISTS),  UM(REAL),  UP(TOP, BOT),  UM(CAP),  UM(CUP),  UP(ELEM, NELEM),  UP(O, OCIRC),  _______,  UM(BOX),  _______,    _______,  _______,  _______,  _______,
        _______,  UM(FORALL),  _______,  UM(NABLA),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        KC_LSFT,            UM(ZET),  UP(TIMES, OTIMES),  UM(COMPLEX),  UM(LOR),  UM(LAND),  UM(NAT),  _______,  UM(DIAMOND),  UP(CDOT, ODOT),  _______,              KC_RSFT,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  TO(WIN_BASE),    _______,  _______,  _______,  _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [GREEK]    = {ENCODER_CCW_CW(_______, _______)},
    [MATH]     = {ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    switch (keycode) {
        // Custom Caps Word activation; normal press of caps word button works like
        // normal, but when holding shift we activate full caps lock
        case CW_TOGG:
            if ((get_mods() & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock) && record->event.pressed) {
                tap_code(KC_CAPS);
                return false;
            } else {
                return true;
            }

        // Special behaviour for the layer switching: hold is to function layer,
        // tap is to math layer
        case LT(WIN_FN, KC_NO):
            if (record->tap.count && !record->event.pressed) {
                layer_on(MATH);
                return false;
            } else {
                return true;
            }
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode != LT(WIN_FN, KC_NO) && keycode != KC_LSFT && keycode != KC_RSFT) {
        layer_off(MATH);
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch(keycode) {
        // Keycodes that continue Caps Word with shift applied
        case KC_A ... KC_Z:
        case X(GGAMMA) ... X(OOMEGA):
        case KC_MINS:
            add_weak_mods(MOD_BIT_LSHIFT);
            return true;

        // Keycodes that continue Caps Word without shift applied
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        // Default deactivate caps word
        default:
            return false;
    }
}

bool is_not_shiftable_unicode(uint16_t keycode) {
    return keycode < QK_UNICODEMAP_PAIR;
}

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    // When shift is pressed, deactive non-shiftable custom keycodes
    uint8_t current_layer = get_highest_layer(layer_state);
    if(get_mods() & MOD_MASK_SHIFT && (current_layer == GREEK || current_layer == MATH)) {
        rgb_matrix_set_color_for_keycodes(led_min, led_max, current_layer, is_not_shiftable_unicode, RGB_OFF);
    }

    return true;
}
