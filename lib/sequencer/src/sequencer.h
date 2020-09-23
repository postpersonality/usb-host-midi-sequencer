#pragma once
#include <LinkedList.h>
#include <stdint.h>
#include "data/instrument.h"
#include "data/note.h"
#include "data/pattern-tick.h"
#include "data/pattern.h"
#include "data/sequence-state.h"
#include "data/sequence.h"

namespace uhms {
namespace sequencer {

class Sequencer {
   private:
    uint8_t bpm{120};
    LinkedList<SequenceState*> states;
    uint8_t defaultNoteDuration;
    uint8_t numberOfTicksToProcess;

    // public:
    //     Sequencer();

    //     static void timerInterruptHandler();
    //     LinkedList<Note> getNotes();
    //     void play();
    //     void stop();
    //     void pause();
    //     void initInterruptHandler();
    //     void destroyInterruptHandler();

    // interface for note playing
    // interface for pattern render/display
};

}  // namespace sequencer
}  // namespace uhms
