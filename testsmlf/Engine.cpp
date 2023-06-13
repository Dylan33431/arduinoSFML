#include "Engine.h"

Engine::Engine()
{
	setWindowInformation("tha game", 1000, 1000);
	Init();
	isRunning = true;
	isGameStarted = true;
	activeGameIndex = 0;
}

Engine::~Engine()
{

}

void Engine::update()
{
	previousTime = clock.restart();
	dt = previousTime - clock.getElapsedTime();
	if (getGameIsStarted() == true)
	{
		objectStaringPos();
		setGameIsStarted(false);
	}
	games.at(activeGameIndex)->gameUpdate(getDeltaTime());
	ardiunoConnection.Update();
	windowRenderer();
	windowCollision();
	entityCollsion();
	playerLights();
}

float Engine::getDeltaTime()
{
	return dt.asSeconds();
}

bool Engine::getIsRunning()
{
	return isRunning;
}

void Engine::setGameIsStarted(bool gameRunning)
{
	isGameStarted = gameRunning;
}
bool Engine::getGameIsStarted()
{
	return isGameStarted;
}

void Engine::addGame(Game* game, bool isActiveGame)
{
	games.push_back(game);
	if (isActiveGame)
	{
		activeGameIndex = games.size() - 1;
	}
}

void Engine::setActiveGameIndex(int anActiveGameIndex)
{
	activeGameIndex = anActiveGameIndex;
}
int Engine::getActiveGameIndex()
{
	return activeGameIndex;
}

void Engine::setWindowInformation(std::string anWindowName, int aWindowWidth, int aWindowheight)
{
	windowName = anWindowName;
	windowWidth = aWindowWidth;
	windowHeight = aWindowheight;
}

void Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(getWindowWidth(), getWindowHeight()), getWindowName());
}

void Engine::windowRenderer()
{
	window->setFramerateLimit(60);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	window->clear(sf::Color(124, 176, 62));
	drawShapes();
	colorShapes();
	window->display();
}

std::string Engine::getWindowName()
{
	return windowName;
}
int Engine::getWindowWidth()
{
	return windowWidth;
}
int Engine::getWindowHeight()
{
	return windowHeight;
}

void Engine::windowCollision()
{
	for (Entity* e : *games.at(getActiveGameIndex())->GetObjects())
	{
		//north border
		if (e->getShape().getPosition().y < 0)
		{
			e->getShape().setPosition(e->getShape().getPosition().x, 0);
		}
		//east border
		if (e->getShape().getPosition().x + e->getShape().getGlobalBounds().width > getWindowWidth())
		{
			e->getShape().setPosition(getWindowWidth() - e->getShape().getGlobalBounds().width, e->getShape().getPosition().y);
		}
		//south border
		if (e->getShape().getPosition().y + e->getShape().getGlobalBounds().height > getWindowHeight())
		{
			e->getShape().setPosition(e->getShape().getPosition().x, getWindowHeight() - e->getShape().getGlobalBounds().height);
		}
		//west border
		if (e->getShape().getPosition().x < 0)
		{
			e->getShape().setPosition(0, e->getShape().getPosition().y);
		}
	}
}
void Engine::entityCollsion()
{
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator it2;
	bool isColliding = false;

	for (it = games.at(activeGameIndex)->GetObjects()->begin(); it != games.at(activeGameIndex)->GetObjects()->end(); ++it)
	{
		for (it2 = std::next(it, 1); it2 != games.at(activeGameIndex)->GetObjects()->end(); ++it2)
		{
			if ((*it)->getShape().getGlobalBounds().intersects((*it2)->getShape().getGlobalBounds()))
			{
				(*it)->onCollisionEnter(*it2);
				(*it2)->onCollisionEnter(*it);
			}
		}
	}
}

void Engine::drawShapes()
{
	for (Entity* e : *games.at(getActiveGameIndex())->GetObjects())
	{
		window->draw(e->getShape());
	}
}
void Engine::colorShapes()
{
	for (Entity* e : *games.at(getActiveGameIndex())->GetObjects())
	{
		if (e->getEntityTag() == "obstacle")
		{
			e->getShape().setFillColor(sf::Color(182, 182, 182));
		}
		if (e->getEntityTag() == "portal")
		{
			e->getShape().setFillColor(sf::Color(82, 138, 183, 170));
		}
		if (e->getEntityTag() == "player")
		{
			e->getShape().setFillColor(sf::Color(165, 72, 181));
		}
		if (e->getEntityTag() == "enemy")
		{
			e->getShape().setFillColor(sf::Color().Red);
		}
	}
}
void Engine::objectStaringPos()
{
	for (Entity* e : *games.at(getActiveGameIndex())->GetObjects())
	{
		e->getShape().setPosition(e->getStartingPosX() - e->scale, e->getStartingPosY() - e->scale);
	}
}

void Engine::playerLights()
{
	for (Entity* e : *games.at(getActiveGameIndex())->GetObjects())
	{
		if(e->getEntityTag() == "player")
		{
			playerhp = e->getHealth();
		}
	}
	if (playerhp == 4 && q == true)
	{
		ardiunoConnection.sendMessage("5");
		q = false;
	}
	if (playerhp == 3 && w == true)
	{
		ardiunoConnection.sendMessage("6");
		w = false;
	}
	if (playerhp == 2 && e == true)
	{
		ardiunoConnection.sendMessage("7");
		e = false;
	}
	if (playerhp == 1 && r == true)
	{
		ardiunoConnection.sendMessage("8");
		r = false;
	}
	if (playerhp == 0 && t == true)
	{
		ardiunoConnection.sendMessage("9");
		t = false;
	}
}




