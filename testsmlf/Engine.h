#pragma once
#include "Entity.h"
#include "Game.h"
#include "LightLevel.h"
#include "ArdiunoConnection.h"
#include "Player.h"
#include "Obstacle.h"
#include "Portal.h"
#include "Enemy.h"
#include <string>
#include <iostream>

class LightLevel;

class ArdiunoConnection;

class Game;

class Engine
{
public:
	Engine();
	~Engine();

	void update();

	float getDeltaTime();

	bool getIsRunning();

	void setGameIsStarted(bool running);
	bool getGameIsStarted();

	void addGame(Game* game, bool isActiveGame = false);

	void setActiveGameIndex(int anActiveGameIndex);
	int getActiveGameIndex();
	
	void setWindowInformation(std::string anWindowName, int aWindowWidth, int aWindowheight);
private:

	void Init();
	void windowRenderer();
	std::string getWindowName();
	int getWindowWidth();
	int getWindowHeight();

	void windowCollision();
	void entityCollsion();

	void drawShapes();
	void colorShapes();
	void objectStaringPos();

	sf::RenderWindow* window;
	sf::Event event;

	sf::Time previousTime;
	sf::Time dt;
	sf::Clock clock;

	std::vector<Game*> games;
	std::string windowName;

	Game* activeGame;
	LightLevel lightLevel;
	ArdiunoConnection ardiunoConnection;

	int windowWidth;
	int windowHeight;
	int activeGameIndex = 0;

	bool isRunning;
	bool isGameStarted;
};