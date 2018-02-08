#pragma once

#define deactivated 00
#define acoustic_bass_drum 35
#define bass_drum_1 36
#define side_stick 37
#define snare 38
#define hand_clap 39
#define electric_snare 40
#define low_floor_tom 41
#define hi_hat_closed 42
#define high_floor_tom 43			
#define pedal_hi_hat 44
#define low_tom 45
#define hi_hat_open 46
#define low_mid_tom 47
#define hi_mid_tom 48
#define crash1 49
#define hi_tom 50
#define ride_bow 51
#define chinese_cymbal 52
#define ride_bell 53
#define tambourine 54
#define splash_cymbal 55
#define cowbell 56
#define crash2 57
#define vibraslap 58
#define ride_cymbal_2 59
#define hi_bongo 60
#define low_bongo 61
#define mute_hi_conga 62
#define open_hi_conga 63
#define low_conga 64
#define high_timbale 65
#define low_timbale 66
#define high_agogo 67
#define low_agogo 68
#define cabasa 69
#define maracas 70
#define short_whisle 71
#define long_whisle 72
#define short_guiro 73
#define long_guiro 74
#define claves 75
#define hi_wood_block 76
#define low_wood_block 77
#define mute_cuica 78
#define open_cuica 79
#define mute_triangle 80
#define open_triangle 81

#define NUM_PADS 10					// how many pads are supported by the controller
#define CHANNEL 10					// the midi channel
#define BUFFER_SIZE 10				// how many inputs should be stored
#define MIN_TIME_BETWEEN_NOTES 75	// how many milliseconds before next hit
#define MAX_MIDI_VELOCITY 127		// the largest velocity accepted by the midi standard
#define USE_MAX true				// should the default velocity be used

typedef struct {
	unsigned char note;
	unsigned char velocity;
} MidiNote;