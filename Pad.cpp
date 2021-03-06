#include "Pad.h"

Pad::Pad(){
	note = deactivated;
	pin = 0;
	velocity = 0;
	threshold = 0;
	bufferIndex = 0;
	smoothingIndex = 0;
	lastHitTime = 0;

	for (int i : buffer) i = 0;
	for (int i : smoothingBuffer) i = 0;
}

void Pad::setVals(unsigned char midiNote, unsigned char pin, unsigned int threshold, unsigned int minDelay, unsigned char defaultVelocity){
	this->note = midiNote;
	this->pin = pin;
	this->velocity = defaultVelocity;
	this->minDelay = minDelay;
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
	//nextVal = getSmoothedVal(nextVal);

	if (nextVal < threshold) nextVal = 0;

	buffer[bufferIndex] = nextVal;

	++bufferIndex;
	if (bufferIndex >= BUFFER_SIZE) bufferIndex = 0;
}

MidiNote Pad::getNote(){
	MidiNote result;
	result.velocity = 0;
  if(lastHitTime + minDelay > millis()){
    result.note = deactivated;
    return result;
  }

	for (int i = 0; i < BUFFER_SIZE; ++i) {
		if (buffer[i] > result.velocity) result.velocity = buffer[i];
	}

	/*
	result.note = note;
	if (result.velocity >= threshold) {
		if (USE_MAX) result.velocity = velocity;
		lastHitTime = millis();
	}
	else {
		result.velocity = 0;
	}
	result.prevVelocity = lastVelocity;
	lastVelocity = result.velocity;
	*/

	
	if (result.velocity < threshold) result.note = deactivated;
	else {
		result.note = note;
		if(USE_MAX) result.velocity = velocity;
		lastHitTime = millis();
	}
	
	result.note = note;
	return result;
}

unsigned char Pad::getPin(){
	return pin;
}

unsigned int Pad::getThresh()
{
	return threshold;
}

unsigned int Pad::getSmoothedVal(int nextVal){
	smoothingBuffer[smoothingIndex] = nextVal;
	++smoothingIndex;
	if (smoothingIndex >= SMOOTHING_SIZE) smoothingIndex = 0;

	unsigned int result = 0;
	for (int i : smoothingBuffer) result += i;
	result = result / SMOOTHING_SIZE;
	Serial.println(result);
	return result;
}
