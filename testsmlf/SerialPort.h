#pragma once

#include <windows.h>
#include <iostream>
#include <string>

class SerialPort
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;

public:
    static const int ARDUINO_WAIT_TIME = 2000;
    static const int MAX_DATA_SIZE = 255;
    SerialPort();
    ~SerialPort();

    int readSerialPort(char* buffer, unsigned int buf_size);
    bool writeSerialPort(char* buffer, unsigned int buf_size);
    bool isConnected();
};
