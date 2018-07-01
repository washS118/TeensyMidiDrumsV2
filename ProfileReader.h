#pragma once
#include "Pad.h"
#include <string>
#include <SD.h>
#include "DataDefines.h"

class ProfileReader
{
public:
	static bool loadProfile(std::string file, Pad* head, int size);
	static bool saveProfile(std::string file, Pad* head, int size);

private:
	ProfileReader();
	~ProfileReader();

	static bool startSd();

	static bool SdRunning;
};

