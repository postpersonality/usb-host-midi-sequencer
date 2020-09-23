#include "sequencer.h"
#include <LinkedList.h>
#include <stdint.h>
#include "data/note.h"
#include "data/pattern-tick.h"
#include "data/pattern.h"
#include "data/sequence-state.h"
#include "data/sequence.h"

using namespace uhms::sequencer::data;

class Sequencer {
   private:
    uint8_t bpm{120};
    LinkedList<SequenceState*> states;
    uint8_t defaultNoteDuration;
    uint8_t numberOfTicksToProcess;

   public:
    Sequencer() : Sequencer(120u) {}

    Sequencer(uint8_t bpm) {
        this->setBpm(bpm);
        this->initDefaultSequence();
    }

    void setBpm(uint8_t bpm) {
        this->bpm = bpm;
        // TODO set defaultNoteDuration
    }

    void initDefaultSequence() {
        this->states = LinkedList<SequenceState*>();
        this->states.add(new SequenceState(new Sequence()));
    }
};
