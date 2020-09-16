#pragma once
#include <stdint.h>

struct Note {
    uint8_t pitch;
    uint8_t volume;
    uint8_t duration;

    Note(uint8_t pitch, uint8_t volume, uint8_t duration) {
        this->pitch = pitch;
        this->volume = volume;
        this->duration = duration;
    }
};
