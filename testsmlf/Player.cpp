#include "Player.h"

Player::Player(std::string aEntityTag,
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
	canTakeDamage = true;
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	playerMovement(deltaTime);
	die();
}
void Player::onCollisionEnter(Entity* collider)
{
	//North collsion
	if (getShape().getGlobalBounds().top + getShape().getGlobalBounds().height < collider->getShape().getGlobalBounds().top + 2)
	{
		getShape().setPosition(getShape().getPosition().x, collider->getShape().getGlobalBounds().top - 1 - getShape().getGlobalBounds().height);
	}
	//East collsion
	if (getShape().getGlobalBounds().left > collider->getShape().getGlobalBounds().left + collider->getShape().getGlobalBounds().width - 2)
	{
		getShape().setPosition(collider->getShape().getGlobalBounds().left + 1 + collider->getShape().getGlobalBounds().width, getShape().getPosition().y);
	}
	//South collsion
	if (getShape().getGlobalBounds().top > collider->getShape().getGlobalBounds().top + collider->getShape().getGlobalBounds().height - 2)
	{
		getShape().setPosition(getShape().getPosition().x, collider->getShape().getGlobalBounds().top + 1 + collider->getShape().getGlobalBounds().height);
	}
	//West collsion
	if (getShape().getGlobalBounds().left + getShape().getGlobalBounds().width < collider->getShape().getGlobalBounds().left + 2)
	{
		getShape().setPosition(collider->getShape().getGlobalBounds().left - 1 - getShape().getGlobalBounds().width, getShape().getPosition().y);
	}
}

void Player::playerMovement(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shape.move(0.f, -getEntitySpeedMultiplier() * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shape.move(0.f, getEntitySpeedMultiplier() * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape.move(-getEntitySpeedMultiplier() * deltaTime, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shape.move(getEntitySpeedMultiplier() * deltaTime, 0.f);
	}
}

