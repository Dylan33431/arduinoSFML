#include "Obstacle.h"

Obstacle::Obstacle(std::string aEntityTag,
				   float anEntitySpeed, 
				   float aScale,
				   int aPointCountEntity,
				   int astartingPosX,
				   int astartingPosY,
				   bool returning,
				   bool movingRight,
				   bool movingLeft,
				   bool movingUp,
				   bool movingDown,
				   int theTimeOfMovement)
{
	entityTag = aEntityTag;
	entitySpeed = anEntitySpeed;
	scale = aScale;
	pointCountEntity = aPointCountEntity;

	startingPosX = astartingPosX;
	startingPosY = astartingPosY;

	isReturning = returning;

	isMovingRight = movingRight;
	isMovingLeft = movingLeft;
	isMovingUp = movingUp;
	isMovingDown = movingDown;

	TimeOfMovement = theTimeOfMovement;
	movingV = 0;
	movingH = 0;

	speedMultiplier = entitySpeed * 10;
	shape = sf::CircleShape(getEntityScale(), getPointCountEntity());
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(float deltaTime)
{
	obstacleMovement(deltaTime);
}

int Obstacle::getTimeOfMovement() 
{
	return TimeOfMovement;
}

bool Obstacle::getReturning()
{
	return isReturning;
}
void Obstacle::returningV()
{
	movingV++;
	if (movingV >= getTimeOfMovement())
	{
		if (getMovingRight() == true or getMovingLeft() == true)
		{
			if (getMovingRight() == true)
			{
				setMovingRight(false);
				setMovingLeft(true);
			}
			else
			{
				setMovingRight(true);
				setMovingLeft(false);
			}
			movingV = 0;
		}
	}
}
void Obstacle::returningH()
{
	movingH++;
	if (movingH >= getTimeOfMovement())
	{
		if (getMovingUp() == true or getMovingDown() == true)
		{
			if (getMovingUp() == true)
			{
				setMovingUp(false);
				setMovingDown(true);
			}
			else
			{
				setMovingUp(true);
				setMovingDown(false);
			}
			movingH = 0;
		}
	}
}

void Obstacle::setMovingRight(bool movingRight)
{
	isMovingRight = movingRight;
}
bool Obstacle::getMovingRight()
{
	return isMovingRight;
}
void Obstacle::setMovingLeft(bool movingLeft)
{
	isMovingLeft = movingLeft;
}
bool Obstacle::getMovingLeft()
{
	return isMovingLeft;
}
void Obstacle::setMovingUp(bool movingUp)
{
	isMovingUp = movingUp;
}
bool Obstacle::getMovingUp()
{
	return isMovingUp;
}
void Obstacle::setMovingDown(bool movingDown)
{
	isMovingDown = movingDown;
}
bool Obstacle::getMovingDown()
{
	return isMovingDown;
}

void Obstacle::obstacleMovement(float deltaTime)
{
	if (getReturning() == true)
	{
	returningH();
	returningV();
	}

	if (getMovingRight() == true) 
	{
		shape.move(getEntitySpeedMultiplier() * deltaTime, 0.f);
	}
	if (getMovingLeft() == true) 
	{
		shape.move(-getEntitySpeedMultiplier() * deltaTime, 0.f);
	}
	if (getMovingUp() == true) 
	{
		shape.move(0.f,-getEntitySpeedMultiplier() * deltaTime);
	}
	if (getMovingDown() == true) 
	{
		shape.move(0.f,getEntitySpeedMultiplier() * deltaTime);
	}
}