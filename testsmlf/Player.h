#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(std::string aEntityTag,
		   float anEntitySpeed,
		   int aHealth,
		   bool takeDamage,
		   float aScale,
		   int aPointCountEntity,
		   int aStartingPosX,
		   int aStartingPosY);
	~Player();
	void update(float deltaTime);
	void onCollisionEnter(Entity* collider);
private:
	void playerMovement(float deltaTime);
};
