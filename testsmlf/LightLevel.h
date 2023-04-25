#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Engine;

class LightLevel
{
public:
	LightLevel();
	~LightLevel();

	void update();
	//std::string
private:
	int getLightLevel();
	void setLightLevel(int lightLevel);
	int currentLightLevel;
	std::string string;
};