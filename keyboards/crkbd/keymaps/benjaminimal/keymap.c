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

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //`--------------------------'  `--------------------------'

/* TODO
 *  - Mod-Tap not working for shifted keys
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NUBS, LCTL_T(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), LSFT_T(KC_V), KC_B, KC_N, RSFT_T(KC_M), RALT_T(KC_COMM), RGUI_T(KC_DOT), RCTL_T(KC_SLSH), KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        OSL(NUM), KC_SPC, OSL(FNC), OSL(MTA), OSL(SYM), OSL(NAV)
                                      //`--------------------------'  `--------------------------'
        ),
    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_TILD, KC_PIPE, KC_NUHS, KC_DLR, KC_PERC, KC_NO, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, KC_EXLM, KC_DQUO, KC_AT, KC_QUOT, KC_GRV, KC_CIRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_TRNS,
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
            KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
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
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_INS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
        ),
    [FNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TRNS, KC_ESC, KC_NUM, KC_SCRL, KC_PAUS, KC_F6, KC_F7, KC_APP, KC_PSCR, KC_NO, KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_LLCK, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO, KC_NO, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL, QK_LLCK,
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



#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


