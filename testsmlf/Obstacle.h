#pragma once
#include "Entity.h"

class Obstacle : public Entity
{
public:
	Obstacle(std::string aEntityTag,
			 float anEntitySpeed,
			 float aScale,
			 int aPointCountEntity,
			 int aStartingPosX,
			 int aStartingPosY,
			 bool returning,
			 bool movingRight,
			 bool movingLeft,
			 bool movingUp,
			 bool movingDown,
			 int theTimeOfMovement);
	~Obstacle();

	void update(float deltaTime);
private:
	int getTimeOfMovement();

	bool getReturning();
	void returningV();
	void returningH();

	void setMovingRight(bool movingRight);
	bool getMovingRight();
	void setMovingLeft(bool movingLeft);
	bool getMovingLeft();
	void setMovingUp(bool movingUp);
	bool getMovingUp();
	void setMovingDown(bool movingDown);
	bool getMovingDown();

	void obstacleMovement(float deltaTime);

	int TimeOfMovement;
	int movingV;
	int movingH;

	bool isReturning;
	bool isMovingUp;
	bool isMovingRight;
	bool isMovingDown;
	bool isMovingLeft;
};
