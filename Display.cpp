#include "Display.h"
LiquidCrystal_I2C Display::lcd(DISPLAY_ADDRESS, DISPLAY_COLUMNS, DISPLAY_ROWS);
Pad* Display::myPads;
Display::menue Display::currentMenu;
int Display::currentLine;
char* Display::profileName;

Display::Display()
{
}

Display::~Display()
{
}

void Display::showMain()
{
	currentLine = 0;

	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Profile:");
	lcd.print(profileName);

	lcd.setCursor(0, 1);
	lcd.print("Load Profile");

	lcd.setCursor(0, 2);
	lcd.print("Edit Current Profile");

	lcd.setCursor(0, 3);
	lcd.print("Save");

	lcd.setCursor(0, 0);
	lcd.blink_on();
}

void Display::showProfile()
{

}

void Display::showEdit()
{
	currentLine = 0;
	lcd.clear();

	lcd.setCursor(0, 0);
	lcd.print("Pad:");
	lcd.setCursor(4, 0);
	lcd.print(currentLine + 1);

	lcd.setCursor(0, 1);
	lcd.print("Sensitivity:");
	lcd.setCursor(12, 1);
	lcd.print(myPads[currentLine].getThresh());

	lcd.setCursor(0, 2);
	lcd.print("Note:");
	lcd.setCursor(5, 2);
	lcd.print(myPads[currentLine].getNote().note);
	lcd.setCursor(0, 3);
	lcd.print("Acoustic Bass Drum");
}

void Display::showSave()
{
}

void Display::showSaveAs()
{
}

void Display::start(Pad* firstPad)
{
	myPads = firstPad;
	profileName = "default";
	lcd.begin();
	currentMenu = main;
	showEdit();
}

void Display::upInterrupt()
{
}

void Display::downInterrupt()
{
}

void Display::enterInterrupt()
{
}

void Display::backInterrupt()
{
}

void Display::sensAInterrupt()
{
}

void Display::sensBInterrupt()
{
}

void Display::noteAInterrupt()
{
}

void Display::noteBInterrupt()
{
}
