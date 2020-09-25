/*
 *******************************************************************************
 * eVY1 Shield sample - Say 'Konnichiwa'
 * Copyright (C) 2014-2016 Yuuichi Akagawa
 *
 * This is sample program. Do not expect perfect behavior.
 *******************************************************************************
 */
#include <usbh_midi.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub(&Usb);
USBH_MIDI Midi(&Usb);

void MIDI_poll();
void noteOn(uint8_t note);
void noteOff(uint8_t note);
void setInstrument(uint8_t instrument);

uint8_t channel = 9;
uint8_t instrument = 0;
uint16_t pid, vid;
uint8_t exdata[] = {
    0xf0, 0x43, 0x79, 0x09, 0x00, 0x50, 0x10,
    'k', ' ', 'o', ',',       //Ko
    'N', '\\', ',',           //N
    'J', ' ', 'i', ',',       //Ni
    't', 'S', ' ', 'i', ',',  //Chi
    'w', ' ', 'a',            //Wa
    0x00, 0xf7};

// Amen Break
// http://www.simonv.com/tutorials/drum_patterns.php

uint8_t tick = 0;

uint8_t note1 = 82;  // Tambourine 82/70/54/44/42
uint8_t amen1[] = {
    2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0,
    2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0,
    2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 0};

uint8_t note2 = 51;  // Hihat normal
uint8_t amen2[] = {
    0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0};

uint8_t note3 = 38;  // Snare light
uint8_t amen3[] = {
    0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0};

uint8_t note4 = 40;  // Snare
uint8_t amen4[] = {
    0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,
    0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0};

uint8_t note5 = 36;  // Kick
uint8_t amen5[] = {
    2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};

uint8_t note6 = 49;  // Crash
uint8_t amen6[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};

uint8_t state1 = 0;
uint8_t state2 = 0;
uint8_t state3 = 0;
uint8_t state4 = 0;
uint8_t state5 = 0;
uint8_t state6 = 0;

void setup() {
    vid = pid = 0;
    Serial.begin(115200);

    if (Usb.Init() == -1) {
        while (1)
            ;  //halt
    }          //if (Usb.Init() == -1...
    delay(200);
}

void loop() {
    Usb.Task();
    if (Usb.getUsbTaskState() == USB_STATE_RUNNING) {
        MIDI_poll();
        //    setInstrument(instrument++);
        state1 = play(amen1[tick], state1, note1);
        state2 = play(amen2[tick], state2, note2);
        state3 = play(amen3[tick], state3, note3);
        state4 = play(amen4[tick], state4, note4);
        state5 = play(amen5[tick], state5, note5);
        state6 = play(amen6[tick], state6, note6);
        //    noteOn(0x2b);
        //    delay(80*4);
        //    noteOff(0x2b);
        //    delay(20*4);
        delay(120);
        tick++;
        if (tick == 16 * 3) {
            tick = 0;
        }
    }
}

uint8_t play(uint8_t dur, uint8_t state, uint8_t note) {
    if (dur == 0) {
        state--;
        if (state == 0) {
            noteOff(note);
        }
    } else {
        state = dur;
        noteOn(note);
    }
    return state;
}

// Poll USB MIDI Controler
void MIDI_poll() {
    uint8_t inBuf[3];

    //first call?
    if (Midi.vid != vid || Midi.pid != pid) {
        vid = Midi.vid;
        pid = Midi.pid;
        Midi.SendSysEx(exdata, sizeof(exdata));
        delay(500);
    }
    Midi.RecvData(inBuf);
}

//note On
void noteOn(uint8_t note) {
    uint8_t buf[3];
    buf[0] = 0x90 | channel;
    buf[1] = note;
    buf[2] = 0x3f;  // volume
    Midi.SendData(buf);
}

//note Off
void noteOff(uint8_t note) {
    uint8_t buf[3];
    buf[0] = 0x80 | channel;
    buf[1] = note;
    buf[2] = 0x00;
    Midi.SendData(buf);
}

//set instrument
void setInstrument(uint8_t inst) {
    uint8_t buf[3];
    buf[0] = 0xc0 | channel;
    buf[1] = inst & 0x7f;
    buf[2] = 0x00;
    Midi.SendData(buf);
}
