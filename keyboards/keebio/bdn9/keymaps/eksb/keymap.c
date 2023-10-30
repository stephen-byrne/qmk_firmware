/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H
#include "print.h"

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // for OBS
    [0] = LAYOUT(
//      F13/F14  F16/F17  F18/F19
        KC_F15,  KC_F18,  KC_F21,
        KC_F22,  KC_F23,  KC_F24,
        DF(1),   KC_INT1, KC_INT2
    ),
    // mouse
    [1] = LAYOUT(
//      ms up/don   ms scroll   ms L/R
        KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3,
        DF(0),      KC_UP,      DF(0),
        KC_LEFT,    KC_DOWN,    KC_RIGHT
    )
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
        // left
        ENCODER_CCW_CW(KC_F14, KC_F13),
        // right
        ENCODER_CCW_CW(KC_F20, KC_F19),
        // middle
        ENCODER_CCW_CW(KC_F17, KC_F16)
    },
    [1] = {
        // left - mouse up/down
        ENCODER_CCW_CW(KC_MS_DOWN, KC_MS_UP),
        // right - mouse left/right
        ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT),
        // middle - mouse scroll
        ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)
    }
};

// backlight color is based on layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                // 00 09 55
                rgb_matrix_set_color(i, 0x00, 0x01, 0x05);
                break;
            default:
                // c0 40 00
                rgb_matrix_set_color(i, 0x15, 0x05, 0x00);
                break;
        }
    }
    return false;
}
