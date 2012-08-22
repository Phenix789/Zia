/**
 *
 *
 *
 */

#pragma once
#define	__NETSERVICE_H__

#include "Network.h"
#include "Listener.h"

namespace network {

	EXCEPTION_DECLARATION(NetworkException, utils::Exception);

	class NetService {
	public:
		static const unsigned int ALL = static_cast<unsigned int>(-1);

	public:
		NetService();
		virtual ~NetService();

		void listen(Listener * listener, int port) __throw __throw1(network::NetworkException);
		Communicator & connect(Ip & port, Port & port) __throw __throw1(network::NetworkException);
		void close(Receiver & listener);

		void flushEvent(unsigned int nb = NetService::ALL);

		void start();
		void stop();

	};

}
