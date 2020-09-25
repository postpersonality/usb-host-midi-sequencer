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
    LinkedList<Pattern*> patterns;
    LinkedList<uint8_t> patternIds;

    Sequence();
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
