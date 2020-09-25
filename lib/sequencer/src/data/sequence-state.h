#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "instrument.h"
#include "pattern.h"
#include "sequence.h"

namespace uhms {
namespace sequencer {
namespace data {

struct SequenceState {
    Sequence* sequence;
    Pattern* currentPattern{nullptr};
    uint8_t currentTickNumber{0};
    uint8_t volume{127};
    Instrument instrument;

    SequenceState(Sequence* sequence);
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
