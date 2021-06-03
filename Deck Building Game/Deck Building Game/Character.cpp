#include "Character.h"
#include "GeneralVariables.h"

Character::Character(float starting_health_, std::string name, sf::Texture* texture)
{
	max_health_ = starting_health_;
	ResetHealth();
	ResetDefence();

	setTexture(texture);

	health_text_.setFont(GeneralVariables::font_);
	defence_text_.setFont(GeneralVariables::font_);
}

float Character::GetHealth()
{
	return health_;
}

void Character::ResetHealth()
{
	health_ = max_health_;
	ResetHealthText();
}

bool Character::ChangeHealth(float num)
{
	float result = num; 
	if (result < 0) {
		result = fminf(result + defence_, 0.0f);
		defence_ -= result;
	}
	health_ += result;
	ResetHealthText();
	if (health_ <= 0) {
		return true;
	}
	return false;
}

void Character::ResetHealthText()
{
	health_text_.setString("Health: " + std::to_string(health_) + "/" + 
		std::to_string(max_health_));
}

void Character::RenderHealthText(sf::RenderWindow* window)
{
	window->draw(health_text_);
}

float Character::GetDefence()
{
	return defence_;
}

void Character::AddDefence(float num)
{
	defence_ += num;
	ResetDefenceText();
}

void Character::ResetDefence()
{
	defence_ = 0.0f;
	ResetDefenceText();
}

void Character::ResetDefenceText()
{
	defence_text_.setString("Defence: " + std::to_string(defence_));
}

void Character::RenderDefenceText(sf::RenderWindow* window)
{
	window->draw(defence_text_);
}
