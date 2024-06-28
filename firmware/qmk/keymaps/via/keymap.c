#include QMK_KEYBOARD_H

// #include "print.h" // for debugging https://github.com/qmk/qmk_firmware/blob/master/docs/faq_debug.md

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,       KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL,     KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,           KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,             KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                MO(1), KC_LALT, KC_LGUI,            KC_SPC,          KC_RGUI, KC_RALT,
                                                                                                        KC_UP,
                                                                                            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    LAYOUT(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,  KC_NO,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                                                        KC_PGUP,
                                                                                                KC_HOME, KC_PGDN, KC_END
    ),
    LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                                                        KC_TRNS,
                                                                                                KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// void keyboard_post_init_user(void) {
//     // Customise these values to desired behaviour
//     debug_enable = true;
//     debug_matrix = true;
//     // debug_keyboard=true;
//     // debug_mouse=true;


//     // gpio_set_pin_output(GP25);

// }

// void matrix_scan_user(void) {
//     // writePin(GP25, !gpio_read_pin(GP25));
// }
