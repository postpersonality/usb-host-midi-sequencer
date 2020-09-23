#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "pattern.h"

namespace uhms {
namespace sequencer {
namespace data {

struct Sequence {
    uint8_t patternLength{8};
    bool looped{true};
    LinkedList<Pattern*> patterns{LinkedList<Pattern*>()};
    LinkedList<uint8_t> patternIds{LinkedList<uint8_t>()};

    Sequence();
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
