#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <WinSock2.h> //For win sockets
#include <string> //For std::string
#include <iostream> //For std::cout, std::endl, std::cin.getline
#include "Enums.h"
#include "GetSocketData.h"
#include "SetSocketData.h"

class Client : public SetSocketData, public GetSocketData
{
public:
	Client(std::string IP, int PORT);
	bool Connect();
	bool CloseConnection();
	SOCKET* getSocket();
	
	Client();
	~Client();
private:
	bool ProcessPacket(SOCKET& source, Packet _packettype);
	static void ClientThread();
	SOCKET Connection;//This client's connection to the server
	SOCKADDR_IN addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
};

static Client * clientptr;

