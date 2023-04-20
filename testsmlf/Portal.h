#pragma once
#include "Entity.h"

class Portal : public Entity
{
public:
	Portal(std::string EntityTag,
		float aScale,
		int aPointCountEntity,
		int astartingPosX,
		int astartingPosY,
		int portalIndex,
		int teleportingToPortal);
	~Portal();

	void update();

	void onCollisionEnter(Entity* collider);
private:
	int teleportingTo;
};
