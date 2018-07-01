#include <SD_t3.h>
#include <SD.h>
#include "Pad.h"
#include "ProfileReader.h"
#include <MIDI.h>

Pad pads[BUFFER_SIZE];	// container for all pads

/**************************
* program initialization *
**************************/
void setup() {
	pinMode(PEDAL_PIN, INPUT);

	pads[0].setVals(acoustic_bass_drum, A0, 50);
	pads[1].setVals(snare, A1, 50);
	pads[2].setVals(hi_tom, A2, 50);
	pads[3].setVals(low_tom, A3, 50);
	pads[4].setVals(deactivated, A4, 0);
	pads[5].setVals(hi_hat_closed, A5, 30);
	pads[6].setVals(ride_bell, A6, 100);
	pads[7].setVals(chinese_cymbal, A7, 30, 100);
	pads[8].setVals(deactivated, A8, 0);
	pads[9].setVals(deactivated, A9, 0);

	
}

/*************
* main loop *
*************/
void loop() {
	//updateHat();

	for (int i = 0; i < NUM_PADS; ++i) {
		updatePad(pads[i]);
		playMidiNote(pads[i].getNote());
	}
}

/*********************************************
* get input and update specified pad buffer *
*********************************************/
void updatePad(Pad& pad) {
	unsigned int val = analogRead(pad.getPin());
	pad.update(val);
}

void updateHat() {
	if (PEDAL_COMMAND != CC_DEACTIVATED) {
		usbMIDI.sendControlChange(PEDAL_COMMAND, digitalReadFast(PEDAL_PIN), CHANNEL);
	}
}

/**************************************
 * play note using data stored in pad *
 **************************************/
void playMidiNote(MidiNote note) {
	//skip if note is zero (deactivated);
	if (note.note == deactivated) return;
	
	/*
	Serial.print(note.note);
	Serial.print(":");
	Serial.println(note.velocity);
	*/

	/*
	if (note.velocity > MAX_MIDI_VELOCITY) note.velocity = MAX_MIDI_VELOCITY;
	if (note.velocity > 0 && note.velocity > note.prevVelocity) {
		usbMIDI.sendNoteOff(note.note, note.velocity, CHANNEL);
		usbMIDI.sendNoteOn(note.note, note.velocity, CHANNEL);
	}
	else usbMIDI.sendNoteOff(note.note, note.velocity, CHANNEL);
	*/

	
	if (note.velocity > MAX_MIDI_VELOCITY) note.velocity = MAX_MIDI_VELOCITY;
	usbMIDI.sendNoteOn(note.note, note.velocity, CHANNEL);
	usbMIDI.sendNoteOff(note.note, note.velocity, CHANNEL);
	
}
