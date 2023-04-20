#pragma once
#include "entity.h"
#include "Game.h"

class Game;

class Enemy : public Entity
{
public:
	Enemy(std::string aEntityTag,
		  float anEntitySpeed,
		  int health,
		  bool canTakeDamage,
		  float aScale,
		  int aPointCountEntity,
		  int aStartingPosX,
		  int aStartingPosY);
	~Enemy();

	void update(float deltaTime);
	void setTarget(Entity* aTarget);
	void onCollisionEnter(Entity* collider);
private:
	float getMagnitude(sf::Vector2f vector);
	sf::Vector2f getNormalize(sf::Vector2f vector, float magnitude);

	void moveTowardsTarget(float deltaTime);
	Entity* target;
	Game* game;
};
