#include "sequence.h"
#include <stdint.h>

using namespace uhms::sequencer::data;

Sequence::Sequence() {
    this->patterns.add(new Pattern());
    this->patternIds.add(0);
};
