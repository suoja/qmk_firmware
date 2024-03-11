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
#include "ocean_dream.h"

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
    setPinOutput(24);
    writePinHigh(24);
}

/*
 * TODO: QWERTY to pinkies
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
      KC_GRAVE,    KC_B,       KC_Y,       KC_O,       KC_U,      KC_QUOTE,                       KC_SEMICOLON,   KC_L,      KC_D,       KC_W,      KC_V,    KC_Z,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
      LALT_T(KC_TAB),  LT(4,KC_C),    LCTL_T(KC_I),  LT(2,KC_E),    LT(1,KC_A),    KC_COMMA,                         KC_DOT,    KC_H,    KC_T,    KC_S, LT(3,KC_N), KC_Q,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
      KC_DEL,    KC_G,    KC_X,    KC_J,    KC_K,   KC_MINUS,                         KC_SLASH,    KC_R, KC_M,  KC_F, KC_P,  KC_BSLS,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                XP(ae, AE), LSFT_T(KC_BSPC),  KC_ESC,     KC_ENT,   LGUI_T(KC_SPC), XP(oe, OE)
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
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, LCTL(KC_WH_U), KC_BRIU, KC_VOLU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  LCTL(KC_WH_D), KC_BRID, KC_VOLD, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    DF(0), XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, DF(5),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, _______,  _______,     _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
    KC_GRAVE,    KC_Q,       KC_W,       KC_E,       KC_R,      KC_T,                       KC_Y,   KC_U,      KC_I,       KC_O,      KC_P,   XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
      LALT_T(KC_TAB),  LT(4,KC_A),    LCTL_T(KC_S),  LT(2,KC_D),    LT(1,KC_F),    KC_G,                         KC_H,    KC_J,    KC_K,    KC_K, LT(3,KC_SEMICOLON), KC_QUOTE,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
    KC_DEL,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                         KC_N,    KC_M, KC_COMMA,  KC_DOT, KC_SLASH,  DF(0),
  //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                XP(ae, AE), LSFT_T(KC_BSPC),  KC_ESC,     KC_ENT,   LGUI_T(KC_SPC), XP(oe, OE)
                                                        //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_270;
    }

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case KC_LCTL:
            case KC_RCTL:

    #ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
    #endif
                break;
        }
        return true;
    }

    bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        #    ifdef OCEAN_DREAM_ENABLE
            render_stars();
        #    endif
            }

        return false;
    }
#endif
