#pragma once
#include <stdint.h>

namespace uhms {
namespace sequencer {
namespace data {

struct Instrument {
    uint8_t program{0};
    uint8_t channel{9};

    Instrument() = default;

    Instrument(uint8_t program, uint8_t channel);
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
