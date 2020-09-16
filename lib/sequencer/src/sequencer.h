#pragma once
#include <stdint.h>
#include <LinkedList.h>
#include "sequence-state.h"
#include "sequence.h"
#include "pattern.h"
#include "pattern-tick.h"
#include "note.h"

class Sequencer {
private:
    uint8_t bpm { 120 };
    LinkedList<Sequence> sequences;
    LinkedList<SequenceState> states;
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
