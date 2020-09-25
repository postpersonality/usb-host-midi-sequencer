#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "note.h"

namespace uhms {
namespace sequencer {
namespace data {

struct PatternRow {
    uint8_t notePitch;
    LinkedList<Note*> notes;

    PatternRow() = default;
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
