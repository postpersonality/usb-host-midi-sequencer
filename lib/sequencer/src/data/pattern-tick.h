#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "note.h"

namespace uhms {
namespace sequencer {
namespace data {

struct PatternTick {
    uint8_t tickNumber;
    LinkedList<Note*> notes{LinkedList<Note*>()};

    PatternTick() = default;
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
