#pragma once
#include <stdint.h>
#include <LinkedList.h>
#include "pattern-tick.h"

struct Pattern {
    LinkedList<PatternTick*> ticks { LinkedList<PatternTick*>() };

    Pattern() {
    }
};
