#include QMK_KEYBOARD_H
#include "german_input.h"
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define BSE 0
#define SYM 1
#define NUM 2
#define NAV 3
#define FNC 4
#define MTA 5

#define LC(kc) LCTL_T(kc)
#define LG(kc) LGUI_T(kc)
#define LA(kc) LALT_T(kc)
#define LS(kc) LSFT_T(kc)
#define RS(kc) RSFT_T(kc)
#define RG(kc) RGUI_T(kc)
#define RC(kc) RCTL_T(kc)

enum my_keycodes {
  MY_1 = SAFE_RANGE,  // Workaround KC_1 to enable usage of LCTL_T for KC_EXLM
  MY_AE,
  MY_OE,
  MY_UE,
  MY_SS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BSE] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TAB,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                 KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSPC,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_CAPS,      LC(KC_A),     LG(KC_S),     LA(KC_D),     LS(KC_F),     KC_G,                 KC_H,         RS(KC_J),     LA(KC_K),     RG(KC_L),     RC(KC_SCLN),  KC_ENT,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_NUBS,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                 KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_MINS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  OSL(NUM),     KC_SPC,       OSL(FNC),             OSL(MTA),     OSL(SYM),     OSL(NAV)
    //                                           `-----------------------------------------'       `-----------------------------------------'
    ),
    [SYM] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TRNS,      KC_TILD,      KC_PIPE,      KC_NUHS,      KC_DLR,       KC_PERC,              KC_NO,        KC_AMPR,      KC_ASTR,      KC_LCBR,      KC_RCBR,      KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      LC(KC_EXLM),  LG(KC_DQUO),  LA(KC_AT),    RS(KC_QUOT),  KC_GRV,               KC_CIRC,      LS(KC_LPRN),  LA(KC_RPRN),  RG(KC_LBRC),  RC(KC_RBRC),  KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_LCTL,      KC_LGUI,      MY_SS,        MY_AE,        KC_NO,                KC_NO,        MY_OE,        MY_UE,        KC_RGUI,      KC_RCTL,      KC_TRNS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_TRNS
    //                                           `-----------------------------------------'       `-----------------------------------------'
    ),
    [NUM] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                KC_PSLS,      KC_PMNS,      KC_PAST,      KC_PPLS,      KC_EQL,       KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      LC(MY_1),     LG(KC_2),     LA(KC_3),     RS(KC_4),     KC_5,                 KC_6,         LS(KC_7),     LA(KC_8),     RG(KC_9),     RC(KC_0),     KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_LCTL,      KC_LGUI,      KC_LALT,      KC_LSFT,      KC_NO,                KC_NO,        KC_RSFT,      LA(KC_COMM),  RG(KC_DOT),   KC_RCTL,      KC_TRNS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_TRNS
    //                                           `-----------------------------------------'       `-----------------------------------------'
    ),
    [NAV] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,       KC_DEL,       KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_LCTL,      KC_LGUI,      KC_LALT,      KC_LSFT,      KC_NO,                KC_LEFT,      RS(KC_DOWN),  LA(KC_UP),    RG(KC_RGHT),  RC(KC_INS),   KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                KC_NO,        KC_APP,       KC_NO,        KC_NO,        KC_NO,        KC_TRNS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_TRNS
    //                                           `-----------------------------------------'       `-----------------------------------------'
    ),
    [FNC] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TRNS,      KC_ESC,       KC_NUM,       KC_SCRL,      KC_PAUS,      KC_F11,               KC_F12,       KC_PSCR,      KC_NO,        KC_NO,        KC_NO,        KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      LC(KC_F1),    LG(KC_F2),    LA(KC_F3),    LS(KC_F4),    KC_F5,                KC_F6,        RS(KC_F7),    LA(KC_F8),    RG(KC_F9),    RC(KC_F10),   KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,                KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_TRNS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_TRNS
    //                                           `-----------------------------------------'       `-----------------------------------------'
    ),
    [MTA] = LAYOUT_split_3x6_3(
    // ,-----------------------------------------------------------------------------------.       ,-----------------------------------------------------------------------------------.
        KC_TRNS,      RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_SPI,              KC_NO,        KC_MPLY,      KC_MSTP,      KC_NO,        KC_NO,        KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      RGB_RMOD,     RGB_HUD,      RGB_SAD,      RGB_VAD,      RGB_SPD,              KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      KC_MUTE,      KC_TRNS,
    // |-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------|
        KC_TRNS,      KC_NO,        KC_NO,        KC_NO,        KC_NO,        RGB_TOG,              KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_TRNS,
    // `-------------+-------------+-------------+-------------+-------------+-------------|       |-------------+-------------+-------------+-------------+-------------+-------------'
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,      KC_TRNS
    //                                           `-----------------------------------------'       `-----------------------------------------'
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
        // Send German characters using the detected OS's native input sequences.
        case MY_AE:
        case MY_OE:
        case MY_UE:
        case MY_SS:
            if (record->event.pressed) {
                send_german_character((german_character_t)(keycode - MY_AE));
            }
            return false;
        // Mod-tap only stores basic tap keycodes. Handle shifted symbols explicitly
        // and translate the MY_1 placeholder back to KC_1 on the number layer.
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
        ENABLE_MOD_TAP(LALT_T, KC_RPRN)
        ENABLE_MOD_TAP(RGUI_T, KC_LBRC)
        ENABLE_MOD_TAP(RCTL_T, KC_RBRC)
        ENABLE_MOD_TAP(LCTL_T, KC_DQUO)
    }
    return true;
}


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


