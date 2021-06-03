#include "ScreenManager.h"



ScreenManager::ScreenManager()
{
	currentScreen = LEVEL;
}


ScreenManager::~ScreenManager()
{
}

ScreenManager::screens ScreenManager::getCurrentScreen() {
	return currentScreen;
}

void ScreenManager::changeScreen(screens screen) {
	currentScreen = screen;
}
