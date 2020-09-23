#include "note.h"
#include <stdint.h>

using namespace uhms::sequencer::data;

Note::Note(uint8_t pitch, uint8_t volume, uint8_t duration) {
    this->pitch = pitch;
    this->volume = volume;
    this->duration = duration;
}
