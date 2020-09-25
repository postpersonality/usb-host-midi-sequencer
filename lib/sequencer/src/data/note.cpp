#include "note.h"
#include <stdint.h>

using namespace uhms::sequencer::data;

Note::Note(uint8_t patternOffset, uint8_t volume, uint8_t duration) {
    this->patternOffset = patternOffset;
    this->volume = volume;
    this->duration = duration;
}
