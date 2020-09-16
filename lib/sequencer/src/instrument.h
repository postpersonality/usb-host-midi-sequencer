#pragma once
#include <stdint.h>

struct Instrument {
    uint8_t patch { 0 };
    uint8_t bank { 0 };
    uint8_t channel { 10 };

    Instrument() {
    }

    Instrument(uint8_t patch, uint8_t bank, uint8_t channel) {
        this->patch = patch;
        this->bank = bank;
        this->channel = channel;
    }
};
