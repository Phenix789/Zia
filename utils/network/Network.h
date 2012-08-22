/**
 *
 *
 *
 */

#pragma once
#define	__NETWORK_H__

#include "Define.h"
#include "tools/Exception.hpp"

namespace network {

	typedef int Ip;
	typedef int Port;

	enum NetworkDisconnect {
		ND_USER_REQUEST,
		ND_PEER_DISCONNECTED,
		ND_UNKNOW
	};

}
