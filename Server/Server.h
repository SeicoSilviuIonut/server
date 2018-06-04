#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <iostream>
#include "GetSocketData.h"
#include "SetSocketData.h"
#include "Enums.h"


class Server : public GetSocketData, public SetSocketData
{
public:
	Server();
	Server(int PORT);
	bool ListenForNewConnection();
	
	~Server();

private:
	static void ClientHandlerThread(int ID);
	
	int totalConnections_ = 0;
	
	bool ProcessPacket(int ID, Packet _packettype);

	SOCKET connections_[100];
	SOCKADDR_IN adr_; //Address that we will bind our listening socket to
	int adrLen_ = sizeof(adr_);
	SOCKET sListen_;
};

static Server * serverPtr_;