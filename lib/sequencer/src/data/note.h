#pragma once
#include <stdint.h>

namespace uhms {
namespace sequencer {
namespace data {

struct Note {
    uint8_t pitch;
    uint8_t volume;
    uint8_t duration;

    Note(uint8_t pitch, uint8_t volume, uint8_t duration);
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
