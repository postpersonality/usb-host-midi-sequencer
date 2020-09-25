#pragma once
#include <stdint.h>

namespace uhms {
namespace sequencer {
namespace data {

struct Note {
    uint8_t patternOffset;
    uint8_t volume : 4;
    uint8_t duration : 4;

    Note(uint8_t patternOffset, uint8_t volume, uint8_t duration);
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
