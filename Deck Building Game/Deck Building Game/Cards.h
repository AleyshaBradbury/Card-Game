#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Cards : public sf::RectangleShape
{
public:
	Cards();
	~Cards();
	void ChangeAnimation(int i);
	bool Collision(sf::Vector2f mouse_position);
	void MoveCard(sf::Vector2f card_position);
	uint32_t GetCardType();

private:
	sf::Texture cardTexture;
	sf::FloatRect hitbox_;
	uint32_t card_type_ = 0;
	static const unsigned int NUM_CARD_TYPES_ = 3;
	Animation card_anims_[NUM_CARD_TYPES_];
};

