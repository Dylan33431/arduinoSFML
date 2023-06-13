#include "Enemy.h"

Enemy::Enemy(std::string aEntityTag,
			 float anEntitySpeed,
			 int aHealth,
			 bool takeDamage,
			 float aScale,
			 int aPointCountEntity,
			 int aStartingPosX,
			 int aStartingPosY)
{
	entityTag = aEntityTag;
	setEntitySpeed(anEntitySpeed);
	setHealth(aHealth);
	scale = aScale;
	pointCountEntity = aPointCountEntity;

	startingPosX = aStartingPosX;
	startingPosY = aStartingPosY;

	speedMultiplier = entitySpeed * 10;
	shape = sf::CircleShape(getEntityScale(), getPointCountEntity());
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	moveTowardsTarget(deltaTime);
}

void Enemy::setTarget(Entity* aTarget)
{
	target = aTarget;
}

float Enemy::getMagnitude(sf::Vector2f vector)
{
	float vm = (vector.x * vector.x) + (vector.y * vector.y);
	return sqrt(vm);
}

sf::Vector2f Enemy::getNormalize(sf::Vector2f vector, float magnitude)
{
	float n = 1 / magnitude;
	sf::Vector2f b = n * vector;
	return b;
}

void Enemy::moveTowardsTarget(float deltaTime)
{
	if (target)
	{
		sf::Vector2f difference = (target->getShape().getPosition() - getShape().getPosition());
		float lenght = getMagnitude(difference);
		sf::Vector2f normalizedLenght = getNormalize(difference, lenght);
		getShape().move((normalizedLenght * speedMultiplier) * deltaTime);
	}
}

void Enemy::onCollisionEnter(Entity* collider)
{
	if (collider->getCanTakeDamage() == true)
	{
		collider->takeDamage(1);
		collider->getShape().setPosition(100, 100);
	}
}