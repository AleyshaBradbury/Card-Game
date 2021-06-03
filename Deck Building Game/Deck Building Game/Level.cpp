#include "Level.h"



Level::Level(sf::RenderWindow* hwnd, Input* inp, ScreenManager* screen)
{
	window_ = hwnd;
	input_ = inp;
	screens_ = screen;

	/* initialize random seed: */
	srand(time(NULL));

	enemy_manager_ = new EnemyManager();

	player_.DrawHand();
}


Level::~Level()
{
}

bool Level::Update(float dt)
{
	//If players turn.
	if (turn_) {
		enemy_manager_->AttackEnemy(player_.Turn(dt, input_, window_));
		if (input_->isKeyDown(sf::Keyboard::R)) {
			input_->setKeyUp(sf::Keyboard::R);
			player_.EndTurn();
			turn_ = !turn_;
		}
	}
	else {
		turn_ = !turn_;
		if (player_.ChangeHealth(enemy_manager_->EnemyTurn(dt))) {
			return false;
		}
		player_.ResetDefence();
	}
	return true;
}

void Level::Render()
{
	Begin_Draw();
	player_.Render(window_);
	enemy_manager_->RenderEnemy(window_);
	End_Draw();
}

void Level::Begin_Draw()
{
	window_->clear(sf::Color::Black);
}

void Level::End_Draw()
{
	window_->display();
}
