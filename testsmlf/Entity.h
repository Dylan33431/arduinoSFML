#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <string>
#include <iostream>


class Entity abstract
{
public:
	Entity();
	virtual ~Entity();

	virtual void update(float deltaTime);

	sf::CircleShape& getShape();

	void setEntityTag(std::string aTag);
	std::string getEntityTag();

	float getEntityScale();

	int getPointCountEntity();

	void setHealth(int anHealth);
	int getHealth();

	void takeDamage(int damageAmount);

	void die();

	void setCanTakeDamage(bool doTakeDamage);
	bool getCanTakeDamage();

	void setEntitySpeed(float anEntitySpeed);
	float getEntitySpeed();
	float getEntitySpeedMultiplier();

	int getStartingPosX();
	int getStartingPosY();

	virtual void onCollisionEnter(Entity* collider);

	std::string entityTag;
	sf::CircleShape shape;

	int pointCountEntity;
	int health;
	int startingPosX;
	int startingPosY;

	bool canTakeDamage;

	float scale;
	float entitySpeed;
	float speedMultiplier;
};
