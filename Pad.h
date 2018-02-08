#ifndef _PAD_h
#define _PAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "wprogram.h"
#else
	#include "WProgram.h"
#endif


#endif

#include "DataDefines.h"

class Pad {
public:
	Pad();
	void setVals(unsigned char midiNote, unsigned char pin, unsigned char defaultVelocity, unsigned int threshold);
	Pad operator=(const Pad& rhs);

	void update(unsigned int nextVal);
	MidiNote getNote();
	unsigned char getPin();

private:
	unsigned char note;
	unsigned char pin;
	unsigned char velocity;
	unsigned int threshold;
	unsigned int buffer[BUFFER_SIZE];
	unsigned char bufferIndex;
	unsigned int lastHitTime;
};