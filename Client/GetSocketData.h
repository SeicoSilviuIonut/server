#include <WinSock2.h>
#include <string>
#include "Enums.h"

class GetSocketData
{
public:
	GetSocketData();
	~GetSocketData();
protected:
	bool GetInt(SOCKET& source, int & _int);
	bool GetString(SOCKET& source, std::string & _string);
	bool GetPacketType(SOCKET* source, Packet & _packettype);
};

