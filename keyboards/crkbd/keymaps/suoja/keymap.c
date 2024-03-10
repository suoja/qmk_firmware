/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
enum unicode_names {
    ae,
    AE,
    oe,
    OE
};

const uint32_t PROGMEM unicode_map[] = {
    [ae] = 0x00E4,
    [AE] = 0x00C4,
    [oe] = 0x00F6,
    [OE] = 0x00D6,
};

// Turn of the power LED on Liatris
void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
      KC_GRAVE,    KC_B,       KC_Y,       KC_O,       KC_U,      KC_QUOTE,                       KC_SEMICOLON,   KC_L,      KC_D,       KC_W,      KC_V,    KC_Z,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
      LALT_T(KC_TAB),  LT(2,KC_C),    LT(1,KC_I),  LCTL_T(KC_E),    LGUI_T(KC_A),    KC_COMMA,                         KC_DOT,    KC_H,    KC_T,    KC_S, LT(3,KC_N), KC_Q,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
    KC_ESC,    KC_G,    KC_X,    KC_J,    KC_K,   KC_MINUS,                         KC_SLASH,    KC_R, KC_M,  KC_F, KC_P,  KC_ESC,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                XP(ae, AE), LSFT_T(KC_BSPC),  KC_ESC,     KC_ENT,   LCTL_T(KC_SPC), XP(oe, OE)
                                                        //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______,  KC_7,    KC_8,   KC_9,   XXXXXXX,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______,  KC_4,    KC_5,   KC_6,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______,  KC_1,   KC_2,    KC_3,    XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, _______,  _______,     _______,   _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, KC_AMPR, KC_ASTR, KC_EQL, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LBRC ,   LSFT(KC_9),  LSFT(KC_LBRC),     LSFT(KC_RBRC), LSFT(KC_0), KC_RBRC
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOWN, KC_UP, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, _______,  _______,     _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
