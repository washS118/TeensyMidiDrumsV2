#pragma once
#include "MidiNotes10.h"
#include "MidiCcCommands.h"

#define PEDAL_COMMAND CC_DEACTIVATED
#define PEDAL_PIN 0
#define NUM_PADS 10					// how many pads are supported by the controller
#define CHANNEL 10					// the midi channel
#define BUFFER_SIZE 10				// how many inputs should be stored
#define DEFAULT_MIN 50				// how many milliseconds before next hit
#define MAX_MIDI_VELOCITY 127		// the largest velocity accepted by the midi standard
#define USE_MAX false				// should the default velocity be used

typedef struct {
	unsigned char note;
	unsigned char velocity;
} MidiNote;