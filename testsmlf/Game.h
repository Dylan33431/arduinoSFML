#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <list>
#include "Engine.h"

class Game
{
public:
	Game(std::string aGameName);
	~Game();

	void gameUpdate(float deltaTime);

	std::string getGameName();

	std::list<Entity*>* GetObjects();

	Entity* GetSpecificEntity(std::string aSpecificName);
private:

	std::string gameName;
	void init();

	std::list<Entity*> objects;
};