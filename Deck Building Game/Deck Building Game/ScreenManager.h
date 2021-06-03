#pragma once
class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	enum screens { MAIN, LEVEL, PAUSESCREEN };
	screens getCurrentScreen();
	void changeScreen(screens);

private:
	screens currentScreen;
};

