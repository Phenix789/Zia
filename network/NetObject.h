#pragma once

namespace network
{

class NetObject
{
public:
	virtual void onDisconnect() = 0;
};

}