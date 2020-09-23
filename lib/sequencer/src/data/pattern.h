#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "pattern-tick.h"

namespace uhms {
namespace sequencer {
namespace data {

struct Pattern {
    LinkedList<PatternTick*> ticks{LinkedList<PatternTick*>()};

    Pattern() = default;
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
