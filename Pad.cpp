#include "Pad.h"

Pad::Pad(){
	note = deactivated;
	pin = 0;
	velocity = 0;
	threshold = 0;
	bufferIndex = 0;
	lastHitTime = 0;
}

void Pad::setVals(unsigned char midiNote, unsigned char pin, unsigned char defaultVelocity, unsigned int threshold){
	this->note = midiNote;
	this->pin = pin;
	this->velocity = defaultVelocity;
	this->threshold = threshold;
	bufferIndex = 0;
	lastHitTime = 0;
}

Pad Pad::operator=(const Pad& rhs){
	note = rhs.note;
	pin = rhs.pin;
	velocity = rhs.velocity;
	threshold = rhs.threshold;
	bufferIndex = 0;
	lastHitTime = 0;
	return *this;
}

void Pad::update(unsigned int nextVal){
	if (nextVal < threshold) nextVal = 0;

	buffer[bufferIndex] = nextVal;

	++bufferIndex;
	if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;
}

MidiNote Pad::getNote(){
	MidiNote result;
	result.velocity = 0;

	for (int i = 0; i < BUFFER_SIZE; ++i) {
		if (buffer[i] > result.velocity) result.velocity = buffer[i];
	}

	if (result.velocity < threshold) result.note = deactivated;
	else result.note = note;

	return result;
}

unsigned char Pad::getPin(){
	return pin;
}
