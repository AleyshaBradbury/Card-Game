#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(float max_health, std::string name, sf::Texture* texture,
		sf::Vector2f size, sf::Vector2f position, float damage);
	~Enemy();

	float Turn(float dt);

private:
	float damage_ = 0.0f;
};
