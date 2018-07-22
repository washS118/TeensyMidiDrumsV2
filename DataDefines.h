#pragma once
#include "MidiNotes10.h"
#include "MidiCcCommands.h"

//data defines
#define PEDAL_COMMAND CC_DEACTIVATED
#define PEDAL_PIN 0
#define NUM_PADS 10					// how many pads are supported by the controller
#define CHANNEL 10					// the midi channel
#define BUFFER_SIZE 10				// how many smoothed inputs should be stored
#define SMOOTHING_SIZE 5			// how many raw inputs should be stored
#define DEFAULT_MIN 50				// how many milliseconds before next hit
#define MAX_MIDI_VELOCITY 127		// the largest velocity accepted by the midi standard
#define USE_MAX true				// should the default velocity be used
#define PIN_START A0

//sd card defines
#define CS_PIN 4
#define PROFILE_DIR "profiles/"

//display defines
#define DISPLAY_ADDRESS	 0x27
#define	DISPLAY_ROWS 4
#define DISPLAY_COLUMNS 20

//display controll pins
#define UP_PIN 0
#define DOWN_PIN 0
#define BACK_PIN 0
#define ENTER_PIN 0

typedef struct {
	unsigned char note;
	unsigned char velocity;
	unsigned char prevVelocity;
} MidiNote;