#include "instrument.h"

using namespace uhms::sequencer::data;

Instrument::Instrument(uint8_t program, uint8_t channel) {
    this->program = program;
    this->channel = channel;
}
