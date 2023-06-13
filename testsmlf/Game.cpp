#include "Game.h"

Game::Game(std::string aGameName)
{
	gameName = aGameName;
	init();
}

Game::~Game()
{
}

void Game::gameUpdate(float deltaTime)
{
	for (Entity* e : *GetObjects())
	{
		e->update(deltaTime);
	}
}

std::string Game::getGameName()
{
	return gameName;
}

std::list<Entity*>* Game::GetObjects()
{
	return &objects;
}

void Game::init()
{
	//PLAYER: tag, speed, health, scale, vertex, posX, posY
	Player* player = new Player("player", 10, 4, true, 15, 3, 20, 23);
	objects.push_back(player);

	//OBSTACLE tag, speed, scale, vertex, posX, posY, isReturning, isMovingNorth, isMovingEast, isMovingSouth, isMovingWest, theTimeOfMovement
	objects.push_back(new Obstacle("obstacle", 1, 10, 4, 500, 500, true, true, false, false, true, 100));
	objects.push_back(new Obstacle("obstacle", 2, 15, 4, 300, 300, true, true, false, false, false, 200));
	objects.push_back(new Obstacle("obstacle", 1, 10, 4, 500, 500, false, false, false, true, false, 150));
	objects.push_back(new Obstacle("obstacle", 3, 10, 4, 600, 500, true, false, true, false, true, 150));

	//PORTAL tag, scale, vertex, posX, posY, portalIndex, telportingToPortal
	objects.push_back(new Portal("portal", 25, 30, 200, 200, 1, 2));
	objects.push_back(new Portal("portal", 25, 30, 800, 800, 2, 1));

	//ENEMY tag, speed, health , scale , vertex, posX, posY
	Enemy* enemy = new Enemy("enemy", 7, 20, true, 20, 5, 400, 600);
	enemy->setTarget(player);
	objects.push_back(enemy);
}

Entity* Game::GetSpecificEntity(std::string aSpecificName)
{

	for (Entity* e : *GetObjects())
	{
		if (e->getEntityTag() == aSpecificName)
		{
			return e;
		}
	}
	return nullptr;
}