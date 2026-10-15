#include "quantum.h"
#include "os_detection.h"
#include "german_input.h"

static void tap_character_key(uint8_t keycode) {
    tap_code_delay(keycode, keycode == KC_CAPS ? TAP_HOLD_CAPS_DELAY : 10);
    wait_ms(10);
}

static void set_character_mods(uint8_t mods) {
    set_mods(mods);
    send_keyboard_report();
}

static void send_windows_character(uint8_t code, bool num_lock) {
    if (!num_lock) {
        tap_character_key(KC_NUM);
        wait_ms(100);
    }

    set_character_mods(MOD_BIT(KC_LALT));
    // A leading zero selects Windows ANSI Alt codes, not OEM code-page codes.
    tap_character_key(KC_P0);
    for (uint8_t divisor = 100; divisor > 0; divisor /= 10) {
        uint8_t digit = (code / divisor) % 10;
        tap_character_key(digit == 0 ? KC_P0 : KC_P1 + digit - 1);
    }
    set_character_mods(0);

    if (!num_lock) {
        tap_character_key(KC_NUM);
    }
}

// Requires standard UK layouts on Linux/Windows and British input on macOS.
// Windows Alt codes assume the Windows-1252 ANSI code page.
void send_german_character(german_character_t character) {
    os_variant_t os = detected_host_os();
    if ((unsigned)character > GERMAN_SS || (os != OS_LINUX && os != OS_WINDOWS && os != OS_MACOS)) {
        // Do not emit a potentially destructive shortcut before OS detection finishes.
        return;
    }

    uint8_t mods         = get_mods();
    uint8_t weak_mods    = get_weak_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    led_t   leds         = host_keyboard_led_state();
    bool    shifted     = ((mods | weak_mods | oneshot_mods) & MOD_MASK_SHIFT) != 0;
    bool    uppercase   = character != GERMAN_SS && (shifted != leds.caps_lock);

    clear_weak_mods();
    clear_oneshot_mods();
    set_character_mods(0);

    if (os == OS_WINDOWS) {
        const uint8_t lower[] = {228, 246, 252, 223};
        const uint8_t upper[] = {196, 214, 220, 223};
        send_windows_character(uppercase ? upper[character] : lower[character], leds.num_lock);
    } else {
        // Native UK dead-key sequences need a predictable Caps Lock state.
        if (leds.caps_lock) {
            tap_character_key(KC_CAPS);
        }

        if (character == GERMAN_SS) {
            set_character_mods(MOD_BIT(os == OS_LINUX ? KC_RALT : KC_LALT));
            tap_character_key(KC_S);
            set_character_mods(0);
        } else {
            const uint8_t letters[] = {KC_A, KC_O, KC_U};
            set_character_mods(MOD_BIT(os == OS_LINUX ? KC_RALT : KC_LALT));
            tap_character_key(os == OS_LINUX ? KC_LBRC : KC_U);
            set_character_mods(uppercase ? MOD_BIT(KC_LSFT) : 0);
            tap_character_key(letters[character]);
            set_character_mods(0);
        }

        if (leds.caps_lock) {
            tap_character_key(KC_CAPS);
        }
    }

    set_weak_mods(weak_mods);
    set_character_mods(mods);
    // One-shot modifiers are consumed by this character, not applied to the next key.
}
