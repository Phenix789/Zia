/**
 *
 *
 *
 */

#pragma once
#define	__NETWORK_H__

#include "../utils/Define.h"
#include "../utils/Exception.h"

namespace network {

	typedef int Ip;
	typedef int Port;

	enum NetworkDisconnect {
		ND_USER_REQUEST,
		ND_PEER_DISCONNECTED,
		ND_UNKNOW
	};

	EXCEPTION_DECLARATION_INLINE_ERROR(NetworkException, utils::Exception);

}
