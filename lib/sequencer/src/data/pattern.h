#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "pattern-row.h"

namespace uhms {
namespace sequencer {
namespace data {

struct Pattern {
    LinkedList<PatternRow*> rows;

    Pattern() = default;
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
