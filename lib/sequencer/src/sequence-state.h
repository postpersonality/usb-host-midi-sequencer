#pragma once
#include <stdint.h>
#include <LinkedList.h>
#include "sequence.h"
#include "pattern.h"
#include "instrument.h"

struct SequenceState {
    Sequence* sequence;
    Pattern* currentPattern { nullptr };
    uint8_t currentTickNumber { 0 };
    uint8_t volume { 127 };
    Instrument instrument { Instrument() };

    SequenceState(Sequence* sequence) {
        this->sequence = sequence;
    }
};
