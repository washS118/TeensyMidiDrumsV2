#include "HatControl.h"

void setupHiHat() {
	pinMode(PEDAL_PIN, INPUT);
	hatNote.note = PEDAL_NOTE;
}

MidiNote getHatNote(){
	MidiNote result;
	result.note = PEDAL_NOTE;

	if (digitalRead(PEDAL_PIN) == HIGH) {
		result.velocity = MAX_MIDI_VELOCITY;
	}
	else {
		result.velocity = 0;
	}

	return result;
}
