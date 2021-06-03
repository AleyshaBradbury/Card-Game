#pragma once
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void AttackEnemy(float damage);
	float EnemyTurn(float dt);
	void CreateNewEnemy();

	void RenderEnemy(sf::RenderWindow* window);

private:
	Enemy* current_enemy_ = nullptr;
	const sf::Vector2f enemy_position_ = sf::Vector2f(400.0f, 300.0f);
	sf::Texture enemy_texture_;
};

