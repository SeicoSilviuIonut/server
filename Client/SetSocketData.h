#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include "Enums.h"

class SetSocketData
{
public:
	SetSocketData();
	~SetSocketData();
	bool SendString(SOCKET* source, std::string & _string);
protected:
	bool SendInt(SOCKET& source, int _int);
	bool SendPacketType(SOCKET& source, Packet _packettype);
	
};

