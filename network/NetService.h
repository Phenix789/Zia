/**
 *
 *
 *
 */

#pragma once
#define	__NETSERVICE_H__

#include "Network.h"
#include "Listener.h"
#include "Api.h"

namespace network {

	class NetService : public ZAN::ZiaService{
	public:
		static const unsigned int ALL = static_cast<unsigned int>(-1);

	public:
		NetService() {}
		virtual ~NetService() {}

		virtual const std::string &getName() const = 0;
		virtual bool initialize(ZAN::ZiaCore *core) = 0;
		virtual void listen(Listener * listener, int port) __throw __throw1(network::NetworkException) = 0;
		virtual void close(Communicator & com) = 0;

		virtual void flushEvent(unsigned int nb = NetService::ALL) = 0;

		virtual void start() = 0;
		virtual void stop() = 0;

	};

}
