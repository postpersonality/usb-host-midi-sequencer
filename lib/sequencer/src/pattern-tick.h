#pragma once
#include <stdint.h>
#include <LinkedList.h>
#include "note.h"

struct PatternTick {
    uint8_t tickNumber;
    LinkedList<Note*> notes;
};
