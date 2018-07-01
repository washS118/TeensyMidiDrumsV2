#include "ProfileReader.h"

ProfileReader::ProfileReader()
{
}


ProfileReader::~ProfileReader()
{
}

bool ProfileReader::loadProfile(std::string file, Pad* head, int size){
	return false;
}

bool ProfileReader::saveProfile(std::string file, Pad* head, int size){
	if (!startSd()) return false;

	file = PROFILE_DIR + file;
	File pFile = SD.open(file.c_str(), FILE_WRITE);

	for (int i = 0; i < size; i++) {
		unsigned int pin = head[i].pin - PIN_START;
		unsigned int note = head[i].note;
		unsigned int thresh = head[i].threshold;
		unsigned int delay = head[i].minDelay;
		unsigned int vel = head[i].velocity;

		pFile.printf("%u,%u,%u,%u,%u\n", pin, note, thresh, delay, vel);
	}

	pFile.close();

	return true;
}

bool ProfileReader::startSd(){
	if (SdRunning) return true;
	SdRunning = SD.begin(CS_PIN);
	return SdRunning;
}


