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

	time++;
	std::cout << time << std::endl;

	if (arduino.isConnected())
	{
		if (time >= 250 && time <= 300)
		{
			sendMessage("1");
		}
		if (time == 500 && time <= 550)
		{
			sendMessage("2");
		}
		if (time == 750 && time <= 800)
		{
			sendMessage("3");
		}
		if (time >= 1000)
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