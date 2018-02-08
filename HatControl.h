// HatControl.h

#ifndef _HATCONTROL_h
#define _HATCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "wprogram.h"
#else
	#include "WProgram.h"
#endif


#endif

#include "DataDefines.h"

#define PEDAL_NOTE	deactivated
#define PEDAL_PIN	0

MidiNote hatNote;

void setupHiHat();
MidiNote getHatNote();