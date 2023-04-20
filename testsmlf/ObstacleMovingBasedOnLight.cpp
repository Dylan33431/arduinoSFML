#include "ObstacleMovingBasedOnLight.h"

ObstacleMovingBasedOnLight::ObstacleMovingBasedOnLight(std::string aEntityTag,
													   float anEntitySpeed,
													   float aScale,
													   int aPointCountEntity,
													   int astartingPosX,
													   int astartingPosY,
													   bool movingRight,
													   bool movingLeft,
													   bool movingUp,
													   bool movingDown,
													   int aLightLevel)
{
	entityTag = aEntityTag;
	entitySpeed = anEntitySpeed;
	scale = aScale;
	pointCountEntity = aPointCountEntity;

	startingPosX = astartingPosX;
	startingPosY = astartingPosY;

	isMovingRight = movingRight;
	isMovingLeft = movingLeft;
	isMovingUp = movingUp;
	isMovingDown = movingDown;

	actionOnLightLevel = aLightLevel;

	speedMultiplier = entitySpeed * 1000;
	shape = sf::CircleShape(getEntityScale(), getPointCountEntity());
	//deltatime = (clock.restart().asSeconds());
}

void ObstacleMovingBasedOnLight::update()
{
	obstacleMovement();
}

ObstacleMovingBasedOnLight::~ObstacleMovingBasedOnLight()
{

}

int ObstacleMovingBasedOnLight::getActionOnLightLevel()
{
	return actionOnLightLevel;
}

void ObstacleMovingBasedOnLight::setMovingRight(bool movingRight)
{
	isMovingRight = movingRight;
}
bool ObstacleMovingBasedOnLight::getMovingRight()
{
	return isMovingRight;
}
void ObstacleMovingBasedOnLight::setMovingLeft(bool movingLeft)
{
	isMovingLeft = movingLeft;
}
bool ObstacleMovingBasedOnLight::getMovingLeft()
{
	return isMovingLeft;
}
void ObstacleMovingBasedOnLight::setMovingUp(bool movingUp)
{
	isMovingUp = movingUp;
}
bool ObstacleMovingBasedOnLight::getMovingUp()
{
	return isMovingUp;
}
void ObstacleMovingBasedOnLight::setMovingDown(bool movingDown)
{
	isMovingDown = movingDown;
}
bool ObstacleMovingBasedOnLight::getMovingDown()
{
	return isMovingDown;
}

void ObstacleMovingBasedOnLight::obstacleMovement()
{
	/*
	if (getMovingRight() == true)
	{
		shape.move(getEntitySpeedMultiplier() * deltatime, 0.f);
	}
	if (getMovingLeft() == true)
	{
		shape.move(-getEntitySpeedMultiplier() * deltatime, 0.f);
	}
	if (getMovingUp() == true)
	{
		shape.move(0.f, -getEntitySpeedMultiplier() * deltatime);
	}
	if (getMovingDown() == true)
	{
		shape.move(0.f, getEntitySpeedMultiplier() * deltatime);
	}
	*/
}