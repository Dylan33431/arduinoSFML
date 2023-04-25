#include "ArdiunoConnection.h"

ArdiunoConnection::ArdiunoConnection()
{
	
}

ArdiunoConnection::~ArdiunoConnection()
{

}

void ArdiunoConnection::Update()
{
	char* buffer = new char[SerialPort::MAX_DATA_SIZE];
	buffer[0] = '0';
	if (arduino.isConnected())
	{

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			sendMessage("1");
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			sendMessage("2");
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			sendMessage("3");
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			sendMessage("4");
		}
		arduino.readSerialPort(output, SerialPort::MAX_DATA_SIZE);

		std::cout << output << "\r";
	}


}

std::string ArdiunoConnection::getMessage() {
	return std::string();
}
void ArdiunoConnection::sendMessage(std::string aMessage) {
	std::string string = aMessage;
	char* buffer = string.data();
	arduino.writeSerialPort(buffer, sizeof(buffer));
} 