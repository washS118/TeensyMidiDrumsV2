#pragma once

#include "DataDefines.h"
#include <LiquidCrystal_I2C.h>
#include "Pad.h"

class Display
{
private:
	enum menue { main, profile, edit, save, saveAs };

	Display();
	~Display();

	static void upInterrupt();
	static void downInterrupt();
	static void enterInterrupt();
	static void backInterrupt();
	static void sensAInterrupt();
	static void sensBInterrupt();
	static void noteAInterrupt();
	static void noteBInterrupt();

	static void showMain();
	static void showProfile();
	static void showEdit();
	static void showSave();
	static void showSaveAs();

	static LiquidCrystal_I2C lcd;
	static Pad* myPads;
	static menue currentMenu;
	static int currentLine;
	static char* profileName;

public:
	static void start(Pad* firstPad);
	

};

