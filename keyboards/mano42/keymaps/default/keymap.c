#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_default(
    KC_Q, KC_W, KC_E,KC_R, KC_T ,                               KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D,KC_F, KC_G ,                               KC_H, KC_J, KC_K, KC_L, KC_DQUOTE,
    KC_Z, KC_X, KC_C,KC_V, KC_B , KC_1, KC_2,       KC_4, KC_5, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH,
                KC_DOT, KC_SPACE, KC_ENTER,KC_3,   KC_6,KC_7, KC_8, KC_9
    )
};
