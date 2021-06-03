#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Input.h"
#include "ScreenManager.h"
#include "Player.h"
#include "EnemyManager.h"

class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* inp, ScreenManager* screen);
	~Level();
	bool Update(float dt);
	void Render();

private:
	sf::RenderWindow* window_;
	Input* input_;
	ScreenManager* screens_;
	void Begin_Draw();
	void End_Draw();

	bool turn_ = true; //turn_ = true : player turn.
	Player player_;
	EnemyManager* enemy_manager_ = nullptr;
};

