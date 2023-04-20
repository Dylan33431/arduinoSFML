#include "ArdiunoConnection.h"

ArdiunoConnection::ArdiunoConnection()
	//:port(" ////.//COM6"), arduino(SerialPort(port))
{
}

ArdiunoConnection::~ArdiunoConnection()
{

}

void ArdiunoConnection::Update()
{
	char* buffer = new char[MAX_DATA_LENGTH];
	buffer[0] = '0';
	/*if (arduino.isConnected())
	{
		std::cout << "connected" << std::endl;
	}
	else
	{
		std::cout << "didnt connect" << std::endl;
	}
	if (arduino.isConnected())
	{
		SendMessage("0");
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		std::cout << output << std::endl;
	}*/


}

std::string ArdiunoConnection::GetMessage() {
	return std::string();
}

void ArdiunoConnection::SendMessage(std::string aMessage) {
	const char* buffer = new char[MAX_DATA_LENGTH];
	buffer = aMessage.c_str();
	//arduino.writeSerialPort(buffer, sizeof(buffer));
} 