#pragma once

#include <stdint.h>

typedef enum {
    GERMAN_AE,
    GERMAN_OE,
    GERMAN_UE,
    GERMAN_SS,
} german_character_t;

void send_german_character(german_character_t character);
