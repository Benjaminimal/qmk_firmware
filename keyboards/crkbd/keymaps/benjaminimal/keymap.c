#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define BSE 0
#define SYM 1
#define NUM 2
#define NAV 3
#define FNC 4
#define MTA 5

enum my_keycodes {
  MY_1 = SAFE_RANGE,  // Workaround KC_1 to enable usage of LCTL_T for KC_EXLM
};

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //`--------------------------'  `--------------------------'

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_CAPS, LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        OSL(NUM), KC_SPC, OSL(FNC), OSL(MTA), OSL(SYM), OSL(NAV)
                                      //`--------------------------'  `--------------------------'
        ),
    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_TILD, KC_PIPE, KC_NUHS, KC_DLR, KC_PERC, KC_NO, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, LCTL_T(KC_EXLM), LGUI_T(KC_DQUO), LALT_T(KC_AT), RSFT_T(KC_QUOT), KC_GRV, KC_CIRC, LSFT_T(KC_LPRN), RALT_T(KC_RPRN), RGUI_T(KC_LCBR), RCTL_T(KC_RCBR), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        ),
    [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PMNS, KC_PAST, KC_PPLS, KC_EQL, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, LCTL_T(MY_1), LGUI_T(KC_2), LALT_T(KC_3), RSFT_T(KC_4), KC_5, KC_6, LSFT_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RCTL_T(KC_0), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_RSFT, RALT_T(KC_COMM), RGUI_T(KC_DOT), KC_RCTL, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        ),
    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO, KC_LEFT, RSFT_T(KC_DOWN), RALT_T(KC_UP), RGUI_T(KC_RGHT), RCTL_T(KC_INS), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, KC_NO, KC_NO, KC_NO, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        ),
    [FNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_ESC, KC_NUM, KC_SCRL, KC_PAUS, KC_F6, KC_F7, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, LCTL_T(KC_F1), LGUI_T(KC_F2), LALT_T(KC_F3), LSFT_T(KC_F4), KC_F5, KC_F8, RSFT_T(KC_F9), RALT_T(KC_F10), RGUI_T(KC_F11), RCTL_T(KC_F12), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        ),
    [MTA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_MPLY, KC_MSTP, KC_NO, KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        )
};


/**
 * This code is needed to enable mod tap for non basic key codes
 * https://docs.qmk.fm/mod_tap#intercepting-mod-taps
 */

#define ENABLE_MOD_TAP(mod_tap, key_code) \
        case mod_tap(key_code): \
            if (record->tap.count && record->event.pressed) { \
                tap_code16(key_code); \
                return false; \
            } \
            break;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(MY_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_1);
                return false;
            }
            break;
        ENABLE_MOD_TAP(LCTL_T, KC_EXLM)
        ENABLE_MOD_TAP(LGUI_T, KC_DQUO)
        ENABLE_MOD_TAP(LALT_T, KC_AT)
        ENABLE_MOD_TAP(LSFT_T, KC_LPRN)
        ENABLE_MOD_TAP(RALT_T, KC_RPRN)
        ENABLE_MOD_TAP(RGUI_T, KC_LCBR)
        ENABLE_MOD_TAP(RCTL_T, KC_RCBR)
        ENABLE_MOD_TAP(LCTL_T, KC_DQUO)
    }
    return true;
}


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


