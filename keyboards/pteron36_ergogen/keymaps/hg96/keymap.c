/*
Copyright 2023 Harshit Goel <@harshitgoel96>
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
#include "oneshot.h"
#include "swapper.h"

enum my_layers {
    _BASE,
    _NAV,
    _NUM,
    _ADJUST,
};

enum my_keycodes {
    // Callum oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    OS_CAPS, // for use as Globe on iPadOS, via remapping in Settings.app

    APP_SWITCH_FRWD, // cmd-tab but holds cmd between invocations
};

#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define ENT_SHFT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E,    KC_R, KC_T,         KC_Y,   KC_U, KC_I,    KC_O,   KC_P,   
        KC_A, KC_S, KC_D,    KC_F, KC_G,         KC_H,   KC_J, KC_K,    KC_L,   KC_QUOT, 
        KC_Z, KC_X, KC_C,    KC_V, KC_B,         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                            NAV, KC_SPC, KC_LEFT_SHIFT,      KC_ENT, KC_BSPC,  NUM
  ),

  [_NAV] = LAYOUT_split_3x5_3(
       KC_ESC, _______, _______,    _______, _______,         _______,   _______, _______,    _______,   _______,   
        OS_CMD, OS_ALT, OS_CTRL,    OS_SHFT, _______,         _______,   KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, 
        _______, _______, _______,    _______, _______,         _______, OS_SHFT, OS_CTRL, OS_ALT, OS_CMD, 
            _______, _______, _______,             _______, _______, _______
  ),

  [_NUM] = LAYOUT_split_3x5_3(
    KC_LBRC, KC_7, KC_8,    KC_9, KC_RBRC,         _______,   _______, _______,    _______,   _______,   
        KC_SCLN, KC_4, KC_5,    KC_6, KC_EQUAL,         _______,   OS_SHFT, OS_CTRL,    OS_ALT,   OS_CMD, 
        KC_GRAVE, KC_1, KC_2,    KC_3, KC_BSLS,         _______, _______, _______, _______, _______, 
            KC_DOT, KC_0, KC_MINS,             _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_E,    KC_R, KC_T,         KC_Y,   KC_U, KC_I,    KC_O,   KC_P,   
        KC_A, KC_DOLLAR, KC_D,    KC_F, KC_G,         KC_H,   KC_J, KC_K,    KC_L,   KC_QUOT, 
        KC_Z, KC_EXCLAIM, KC_AT,    KC_HASH, KC_B,         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
            _______, _______, _______,             _______, _______, _______
  )
};


// ====================================================
// Callum One-Shot Modifiers
// ====================================================

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
   // add keycode to cancle onshot mod, need some mode in layers so keeping it for now.
    // case NAV:
    // case NUM:
    // //case B_NUM:
    // //case SPC_NAV:
    // //case KC_ESC:
    //     return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case NAV:
    case NUM:
    //case B_NUM:
    //case SPC_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
    case OS_CAPS:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_caps_state = os_up_unqueued;

bool app_switch_frwd_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &app_switch_frwd_active, KC_LGUI, KC_TAB, APP_SWITCH_FRWD,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
    update_oneshot(
        &os_caps_state, KC_CAPS, OS_CAPS,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}
