#pragma once
#include "Entity.h"
#include "Game.h"
#include "ArdiunoConnection.h"
#include "Player.h"
#include "Obstacle.h"
#include "Portal.h"
#include "Enemy.h"
#include <string>
#include <iostream>

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

	void playerLights();

	sf::RenderWindow* window;
	sf::Event event;

	sf::Time previousTime;
	sf::Time dt;
	sf::Clock clock;

	std::vector<Game*> games;
	std::string windowName;

	Game* activeGame;
	ArdiunoConnection ardiunoConnection;

	int windowWidth;
	int windowHeight;
	int activeGameIndex = 0;

	bool isRunning;
	bool isGameStarted;
	
	int playerhp;
	bool q = true;
	bool w = true;
	bool e = true;
	bool r = true;
	bool t = true;
};