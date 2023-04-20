#pragma once
#include <iostream>
#include "SerialPort.h"
#include "LightLevel.h"



class LightLevel;

class ArdiunoConnection
{
public:
	ArdiunoConnection();
	~ArdiunoConnection();

	void Update();

	std::string GetMessage();
	void SendMessage(std::string aMessage);
private:
	LightLevel lightlevel;
	char output[MAX_DATA_LENGTH];
	char incoming[MAX_DATA_LENGTH];
	bool isStarted;
	char port[MAX_DATA_LENGTH];
	//SerialPort arduino;
};