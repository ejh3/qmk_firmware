/*
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

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */
#define OS_LSFT OSM(MOD_LSFT)

enum layer_names {
    _CMK,
    _NUM,
    _SYM,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
/*  [_QW] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        OS_LSFT, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_RGUI, KC_RCTL
        ),*/
    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
/*  [_FN] = LAYOUT_ortho_5x15(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, MAGIC_TOGGLE_NKRO
        ),*/

    /* COLEMAK
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | XXXXXX | F1     | F2     | F3     | F4     | F5     | XXXXXX | XXXXXX | XXXXXX | F8     | F9     | F10    | F11    | F12    | XXXXXX |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | `      | Q      | W      | F      | P      | B      | F6     | XXXXXX | F7     | J      | L      | U      | Y      | '      | RGUI   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | BACKSP | A      | R      | S      | T      | G      | XXXXXX | XXXXXX | XXXXXX | M      | N      | E      | I      | O      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | D      | V      | XXXXXX | XXXXXX | XXXXXX | K      | H      | ,      | .      | /      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | SPACE  | XXXXXX | XXXXXX | ESC    | CTRL   | TAB    | ALT    | XXXXXX | RSHIFT | SYM    | SPACE  | NAV    | XXXXXX | XXXXXX | NUM    |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_CMK] = LAYOUT_ortho_5x15(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
        KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_F6,   XXXXXXX, KC_F7,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_RGUI,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    XXXXXXX, XXXXXXX, XXXXXXX, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        OS_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, XXXXXXX, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        KC_SPC,  XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, MO(_SYM),KC_TAB,  XXXXXXX, KC_RSFT, MO(_NAV),KC_SPC,  KC_ESC,  XXXXXXX, XXXXXXX, MO(_NUM)
    ),
/*  [_QWE] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, _______, KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        ),*/

    /* NUMBERS
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | XXXXXX | F1     | F2     | F3     | F4     | F5     | XXXXXX | XXXXXX | XXXXXX | F8     | F9     | F10    | F11    | F12    | XXXXXX |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | `      | Q      | W      | F      | P      | B      | F6     | XXXXXX | F7     | J      | L      | U      | Y      | '      | RGUI   |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | BACKSP | A      | R      | S      | T      | G      | XXXXXX | XXXXXX | XXXXXX | M      | N      | E      | I      | O      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | D      | V      | XXXXXX | XXXXXX | XXXXXX | K      | H      | ,      | .      | /      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | SPACE  | XXXXXX | XXXXXX | ESC    | CTRL   | TAB    | ALT    | XXXXXX | RSHIFT | SYM    | SPACE  | NAV    | XXXXXX | XXXXXX | NUM    |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, 
        KC_EQL , KC_PLUS, KC_4,    KC_5,    KC_9,    KC_BSLS, _______, XXXXXXX, _______, KC_RCBR, KC_LCBR, _______, _______, _______, _______,
        _______, KC_ASTR, KC_3,    KC_2,    KC_1,    KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_LPRN, _______, _______, _______, _______,
        _______, KC_MINS, KC_7,    KC_6,    KC_8,    KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, KC_RBRC, KC_LBRC, _______, _______, _______, _______,
        _______, _______, _______, KC_ENT,  KC_P0,   _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
    ),


    /* NUMBER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_SYM] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, 
        _______, _______, KC_HASH, KC_DLR,  KC_PERC, _______, _______, XXXXXXX, _______, _______, _______, KC_AMPR, KC_PIPE, _______, _______,
        _______, _______, KC_EQL,  KC_MINS, KC_UNDS, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_COLN, KC_SCLN, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_ESC,  KC_LCTL, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   NK_TOGG, KC_CAPS, _______, _______, _______, 
        _______, _______, _______, KC_PSCR, _______, _______, _______, XXXXXXX, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
        _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_HOME, KC_END,  _______, _______, _______,
        _______, _______, _______, KC_LALT, KC_LCTL, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
    )


    
};
