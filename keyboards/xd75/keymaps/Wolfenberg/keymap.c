/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QW 0
#define SYMB 1 // symbols
#define MDIA 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .----------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     |    F2    |  F3    |  F4    |  F5    |   `    |        |    \   | F6     |  F7    |    F8  |    F9  |  F10   |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | ESC    | Q      |   W      | E      | R      | T      |        |        |        | Y      | U      | I      | O      | P      | =      |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TAB    | A      |   S      | D      | F      | G      |        |        |    [   | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z\Ctrl |   X      | C      | V      | B      | Enter  |        |    ]   | N      | M      | ,      | .      | /\Ctrl | RSHIFT |
 * |--------+--------+----------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |          | LALT   | Cmd    |SPACE/L1|        |        |        |BckSp/L1| L2     | RALT   |        |        |        |
 * '----------------------------------------------------------------------------------------------------------------------------------------'
 */

#define WLF_SPC LT(SYMB, KC_SPC)
// #define WLF_SPC KC_SPC
#define WLF_BSPC LT(SYMB, KC_BSPACE)
// #define WLF_BSPC KC_BSPACE

#define WLF_RCTL CTL_T(KC_SLSH)
// #define WLF_RCTL KC_SLSH
#define WLF_LCTR CTL_T(KC_Z)
// #define WLF_LCTR KC_Z

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    _______, KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_GRAVE,_______, KC_BSLASH,  KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,   _______,
    KC_ESC,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,   _______, _______, _______,    KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,     KC_EQUAL,
    KC_TAB,  KC_A,       KC_S,    KC_D,    KC_F,    KC_G,   _______, _______, KC_LBRACKET,KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
    KC_LSFT, WLF_LCTR,   KC_X,    KC_C,    KC_V,    KC_B,   KC_ENT , _______, KC_RBRACKET,KC_N,    KC_M,    KC_COMM, KC_DOT,WLF_RCTL, KC_RSFT,
    _______, _______,    _______, KC_LALT, KC_LGUI, WLF_SPC,_______, _______, _______,    WLF_BSPC,MO(MDIA),KC_RALT, _______, _______,_______
  ),

/* Keymap 1: Symbol Layer
 * .----------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |          |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |          |        |        |        |        |        |        | 7      | 8      | 9      |        |        |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |   !    |     @    |   #    |    $   |    %   |        |        |        | 4      | 5      | 6      |        |        |   -    |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |   ^    |     &    |   *    |    (   |    )   |        |        |    0   | 1      | 2      | 3      |        |        |        |
 * |--------+--------+----------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |          |        |        |        |        |        |        |        |        |        |        |        |        |
 * '----------------------------------------------------------------------------------------------------------------------------------------'
 */

  [SYMB] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_EXLM, KC_AT,     KC_HASH, KC_DOLLAR,KC_PERC,KC_TRNS,KC_TRNS, KC_TRNS,  KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS, KC_MINUS,
    KC_TRNS,  KC_CIRC, KC_AMPR,   KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,KC_TRNS, KC_0,     KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

/* Keymap 2: Media and mouse keys
 * .----------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |          |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |          |        |        |        |        |        |        |        |  PgUp  |  Up    | PgDown |        |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |          |        |        |        |        |        |        |        |  Left  | Down   | Right  |        |        |
 * |--------+--------+----------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |          |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+----------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |          |        |        |        |        |        |        |        |        |        |        |        |        |
 * '----------------------------------------------------------------------------------------------------------------------------------------'
 */

  [MDIA] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_PGUP, KC_UP,   KC_PGDOWN,KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
