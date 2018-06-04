#pragma once
class ServerState
{
protected:
	enum class State { OFF, ON, IDLE, FAILED_INITIALIZATION } state_;

public:
	ServerState();
	virtual ~ServerState();
	State getState();
};

