#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::update(float deltaTime)
{
}

sf::CircleShape& Entity::getShape()
{
	return shape;
}

std::string Entity::getEntityTag()
{
	return entityTag;
}
void Entity::setEntityTag(std::string aTag)
{
	entityTag = aTag;
}

float Entity::getEntityScale()
{
	return scale;
}

int Entity::getPointCountEntity()
{
	return pointCountEntity;
}
	
void Entity::setHealth(int anHealth)
{
	health = anHealth;
}
int Entity::getHealth()
{
	return health;
}

void Entity::takeDamage(int damageAmount)
{
	health -= damageAmount;
}

void Entity::die()
{
	if(getHealth() < 0)
	{
		setEntityTag("dead");
	}
}

void Entity::setCanTakeDamage(bool doTakeDamage)
{
	canTakeDamage = doTakeDamage;
}
bool Entity::getCanTakeDamage()
{
	return canTakeDamage;
}

void Entity::setEntitySpeed(float anEntitySpeed)
{
	entitySpeed = anEntitySpeed;
}
float Entity::getEntitySpeed()
{
	return entitySpeed;
}
float Entity::getEntitySpeedMultiplier()
{
	return speedMultiplier;
}

int Entity::getStartingPosX()
{
	return startingPosX;
}
int Entity::getStartingPosY()
{
	return startingPosY;
}

void Entity::onCollisionEnter(Entity* collider)
{
}