#pragma once
#include <SFML/Graphics.hpp>

class Character : public sf::RectangleShape
{
public:
	Character(float starting_health_, std::string name, sf::Texture* texture);
	float GetHealth();
	void ResetHealth();
	bool ChangeHealth(float num);
	void ResetHealthText();
	void RenderHealthText(sf::RenderWindow* window);

	float GetDefence();
	void AddDefence(float num);
	void ResetDefence();
	void ResetDefenceText();
	void RenderDefenceText(sf::RenderWindow* window);

protected:
	float max_health_ = 20.0f;
	float health_ = 0.0f;
	float defence_ = 0.0f;
	sf::Text health_text_;
	sf::Text defence_text_;
};

