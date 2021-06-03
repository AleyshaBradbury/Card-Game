#include "Player.h"
#include <iostream>

Player::Player() 
	: Character(20.0f, "Player", nullptr)
{
	health_text_.setPosition(20.0f, 550.0f);
	health_text_.setCharacterSize(25);
	defence_text_.setPosition(500.0f, 550.0f);
	defence_text_.setCharacterSize(25);

	//Sets it so the game will draw 5 cards.
	for (int i = 0; i < 5; i++) {
		Draw_Pile_.push_back(strike_);
		Draw_Pile_[0 + (i * 6)].ChangeAnimation(1);
		Draw_Pile_.push_back(defence_);
		Draw_Pile_[1 + (int)(i * 6)].ChangeAnimation(2);
		for (int j = 0; j < 4; j++) {
			Draw_Pile_.push_back(blank_);
			Draw_Pile_[j + 2 + (int)(i * 6)].ChangeAnimation(0);
		}
	}

	std::random_shuffle(Draw_Pile_.begin(), Draw_Pile_.end());
}


Player::~Player()
{
}

void Player::DrawCards()
{
	for (size_t i = 0; i < num_draw_cards_; i++) {
		if (Draw_Pile_.empty()) {
			Draw_Pile_ = Discard_Pile_;
			Discard_Pile_.clear();
			std::random_shuffle(Draw_Pile_.begin(), Draw_Pile_.end());
		}
		Hand_.push_back(Draw_Pile_[Draw_Pile_.size()-1]);
		Draw_Pile_.pop_back();
	}
	num_draw_cards_ = 0;
	SetPositionOfCards();
}

void Player::DrawHand()
{
	num_draw_cards_ = start_turn_draw_num_;
	DrawCards();
}

void Player::DiscardCardsFromBack(unsigned int num_discard_cards)
{
	for (size_t i = 0; i < num_discard_cards; i++) {
		if (!Hand_.empty()) {
			Discard_Pile_.push_back(Hand_[Hand_.size() - 1]);
			Hand_.pop_back();
		}
	}
	SetPositionOfCards();
}

void Player::DiscardHand()
{
	DiscardCardsFromBack(Hand_.size());
}

void Player::DiscardCard(int index)
{
	Discard_Pile_.push_back(Hand_[index]);
	Hand_.erase(Hand_.begin() + index);
}

float Player::Turn(float dt, Input* input, sf::RenderWindow* window)
{ 
	if (input->isMouseLeftDown()) {
		for (int i = Hand_.size() - 1; i >= 0; i--) {
			if (Hand_[i].Collision(window->mapPixelToCoords(input->getMouse()))) {
				input->setMouseLeftDown(false);
				switch (Hand_[i].GetCardType())
				{
				case 0:
					num_blank_played++;
					if (num_blank_played >= 10) {
						num_blank_played = 0;
						ChangeHealth(1.0f);
					}
					break;
				case 1:
					damage = -1;
					break;
				case 2:
					AddDefence(1.0f);
					break;
				}
				DiscardCard(i);
				return ResetAndReturnDamage();
			}
		}
	}
	return ResetAndReturnDamage();
}

void Player::EndTurn()
{
	DiscardHand();
	DrawHand();
}

void Player::Render(sf::RenderWindow * window)
{
	for (int i = 0; i < Hand_.size(); i++) {
		window->draw(Hand_[i]);
	}
	RenderHealthText(window);
	RenderDefenceText(window);
}

void Player::SetPositionOfCards()
{
	for (int i = 0; i < Hand_.size(); i++) {
		float x = 55.0f + (600.0f / Hand_.size()) * i;
		Hand_[i].MoveCard(sf::Vector2f(x, 600.f));
	}
}

float Player::ResetAndReturnDamage()
{
	float new_damage = damage;
	damage = 0;
	return new_damage;
}
