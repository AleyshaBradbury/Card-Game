#include "Cards.h"

Cards::Cards()
{
	setSize(sf::Vector2f(150, 200));
	setPosition(400, 500);
	cardTexture.loadFromFile("gfx/card.png");
	setTexture(&cardTexture);

	hitbox_.left = getPosition().x;
	hitbox_.top = getPosition().y;
	hitbox_.width = getSize().x;
	hitbox_.height = getSize().y;

	card_anims_[0].addFrame(sf::IntRect(0, 0, 150, 200));
	card_anims_[1].addFrame(sf::IntRect(150, 0, 150, 200));
	card_anims_[2].addFrame(sf::IntRect(0, 200, 150, 200));
}


Cards::~Cards()
{
}

void Cards::ChangeAnimation(int i)
{
	//Sets the texture of the card.
	setTextureRect(card_anims_[i].getCurrentFrame());
	card_type_ = i;
}

bool Cards::Collision(sf::Vector2f mouse_position)
{
	if (hitbox_.contains(mouse_position)) {
		return true;
	}
	return false;
}

void Cards::MoveCard(sf::Vector2f card_position)
{
	setPosition(card_position);
	hitbox_.left = card_position.x;
	hitbox_.top = card_position.y;
}

uint32_t Cards::GetCardType()
{
	return card_type_;
}
