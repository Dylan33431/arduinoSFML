#include "Portal.h"

Portal::Portal(std::string aEntityTag,
			   float aScale,
			   int aPointCountEntity,
			   int astartingPosX,
			   int astartingPosY,
			   int portalIndex,
			   int teleportingToPortal)
{
	entityTag = aEntityTag;
	scale = aScale;
	pointCountEntity = aPointCountEntity;

	startingPosX = astartingPosX;
	startingPosY = astartingPosY;

	teleportingTo = teleportingToPortal;
	shape = sf::CircleShape(getEntityScale(), getPointCountEntity());
}

Portal::~Portal()
{

}

void Portal::update()
{
}

void Portal::onCollisionEnter(Entity* collider)
{
	//North collsion
	if (getShape().getGlobalBounds().top + getShape().getGlobalBounds().height < collider->getShape().getGlobalBounds().top + 2)
	{
		collider->getShape().setPosition(400, 400);
	}
	//East collsion
	if (getShape().getGlobalBounds().left > collider->getShape().getGlobalBounds().left + collider->getShape().getGlobalBounds().width - 2)
	{
		collider->getShape().setPosition(400, 400);
	}
	//South collsion
	if (getShape().getGlobalBounds().top > collider->getShape().getGlobalBounds().top + collider->getShape().getGlobalBounds().height - 2)
	{
		collider->getShape().setPosition(400, 400);
	}
	//West collider->
	if (getShape().getGlobalBounds().left + getShape().getGlobalBounds().width < collider->getShape().getGlobalBounds().left + 2)
	{
		collider->getShape().setPosition(400, 400);
	}
}