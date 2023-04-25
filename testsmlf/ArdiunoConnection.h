#pragma once
#include <iostream>
#include "LightLevel.h"
#include "SerialPort.h"



class LightLevel;

class ArdiunoConnection
{
public:
	ArdiunoConnection();
	~ArdiunoConnection();

	void Update();

	std::string getMessage();
	void sendMessage(std::string aMessage);

private:
	SerialPort arduino;
	LightLevel lightlevel;
	char output[SerialPort::MAX_DATA_SIZE];
	char incoming[SerialPort::MAX_DATA_SIZE];
	bool isStarted;
	char port[SerialPort::MAX_DATA_SIZE];


	bool sendData;
};