#include "instrument.h"

using namespace uhms::sequencer::data;

Instrument::Instrument(uint8_t patch, uint8_t bank, uint8_t channel) {
    this->patch = patch;
    this->bank = bank;
    this->channel = channel;
}
