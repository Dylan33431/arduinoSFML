#pragma once
#include <SFML/Graphics.hpp>

class Engine;

class LightLevel
{
public:
	LightLevel();
	~LightLevel();

	void update();
	int getLightLevel();
private:
	void setLightLevel(int lightLevel);
	int currentLightLevel;
};