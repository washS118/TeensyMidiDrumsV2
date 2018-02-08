#include "HatControl.h"
#include "Pad.h"
#include <MIDI.h>

Pad pads[BUFFER_SIZE];	// container for all pads

/**************************
* program initialization *
**************************/
void setup() {
	pads[0].setVals(acoustic_bass_drum, A0, 127, 30);
	pads[1].setVals(snare, A1, 127, 30);
	pads[2].setVals(hi_tom, A2, 127, 30);
	pads[3].setVals(low_tom, A3, 127, 20);
	pads[4].setVals(deactivated, A4, 127, 0);
	pads[5].setVals(hi_hat_open, A5, 127, 30);
	pads[6].setVals(ride_bell, A6, 50, 30);
	pads[7].setVals(crash1, A7, 127, 30);
	pads[8].setVals(deactivated, A8, 127, 0);
	pads[9].setVals(deactivated, A9, 127, 0);
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

/**************************************
 * play note using data stored in pad *
 **************************************/
void playMidiNote(MidiNote note) {
	//skip if note is zero (deactivated);
	if (note.note == deactivated) return;

	Serial.print(note.note);
	Serial.print(":");
	Serial.println(note.velocity);
	if (note.velocity > MAX_MIDI_VELOCITY) note.velocity = MAX_MIDI_VELOCITY;
	usbMIDI.sendNoteOn(note.note, note.velocity, CHANNEL);
	usbMIDI.sendNoteOff(note.note, note.velocity, CHANNEL);
}
