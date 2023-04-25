#include "LightLevel.h"

LightLevel::LightLevel()
{
}

LightLevel::~LightLevel()
{

}

void LightLevel::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		setLightLevel(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		setLightLevel(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		setLightLevel(3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		setLightLevel(4);
	}
	string = std::to_string(getLightLevel());
}

void LightLevel::setLightLevel(int lightLevel)
{
	currentLightLevel = lightLevel;
}

int LightLevel::getLightLevel()
{
	return currentLightLevel;
}