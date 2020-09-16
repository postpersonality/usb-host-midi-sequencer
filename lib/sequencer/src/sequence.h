#pragma once
#include <stdint.h>
#include <LinkedList.h>
#include "pattern.h"

struct Sequence {
    uint8_t patternLength { 8 };
    bool looped { true };
    LinkedList<Pattern*> patterns { LinkedList<Pattern*>() };
    LinkedList<uint8_t> patternIds { LinkedList<uint8_t>() };

    Sequence() {
        this->patterns.add(new Pattern());
        this->patternIds.add(0);
    }
};
