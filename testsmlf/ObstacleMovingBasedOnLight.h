#pragma once
#include "Entity.h"

class ObstacleMovingBasedOnLight : public Entity
{
public:
	ObstacleMovingBasedOnLight(std::string aEntityTag,
							   float anEntitySpeed,
							   float aScale,
							   int aPointCountEntity,
							   int aStartingPosX,
							   int aStartingPosY,
							   bool movingRight,
							   bool movingLeft,
							   bool movingUp,
							   bool movingDown,
							   int lightLevel);
	~ObstacleMovingBasedOnLight();
	void update();
private:
	int getActionOnLightLevel();

	void setMovingRight(bool movingRight);
	bool getMovingRight();
	void setMovingLeft(bool movingLeft);
	bool getMovingLeft();
	void setMovingUp(bool movingUp);
	bool getMovingUp();
	void setMovingDown(bool movingDown);
	bool getMovingDown();

	void obstacleMovement();

	int actionOnLightLevel;

	bool isMovingUp;
	bool isMovingRight;
	bool isMovingDown;
	bool isMovingLeft;
};