#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SerialPort.h"

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
	char output[SerialPort::MAX_DATA_SIZE];
	char incoming[SerialPort::MAX_DATA_SIZE];
	bool isStarted;
	char port[SerialPort::MAX_DATA_SIZE];

	bool sendData;
	
	int time;
};