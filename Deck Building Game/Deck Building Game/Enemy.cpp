#include "Enemy.h"

Enemy::Enemy(float max_health, std::string name, sf::Texture* texture,
	sf::Vector2f size, sf::Vector2f position, float damage) :
	Character(max_health, name, texture)
{
	setSize(size);
	setOrigin(size / 2.0f);
	setPosition(position);

	health_text_.setPosition(10.0f, 10.0f);
	damage_ = damage;
}

Enemy::~Enemy()
{
}

float Enemy::Turn(float dt)
{
	return -damage_;
}
