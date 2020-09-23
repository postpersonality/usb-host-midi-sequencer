#pragma once
#include <stdint.h>

namespace uhms {
namespace sequencer {
namespace data {

struct Instrument {
    uint8_t patch{0};
    uint8_t bank{0};
    uint8_t channel{10};

    Instrument() = default;

    Instrument(uint8_t patch, uint8_t bank, uint8_t channel);
};

}  // namespace data
}  // namespace sequencer
}  // namespace uhms
