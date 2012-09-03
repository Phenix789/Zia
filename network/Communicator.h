/**
 *
 *
 *
 */

#pragma once
#define	__COMMUNICATOR_H__

#include "../utils/Buffer.h"
#include "Network.h"

namespace network {

	class Communicator {
	public:
		static const unsigned int ALL = static_cast<unsigned int>(-1);

	public:
		Communicator() {}
		virtual ~Communicator() {}

		virtual Ip getIp() const = 0;
		virtual Port getPort() const = 0;

		virtual Ip getPeerIp() const = 0;
		virtual Port getPeerPort() const = 0;

		virtual void onReceive(utils::Buffer & buffer);
		virtual int send(const utils::Buffer & buffer, unsigned int length = Communicator::ALL, unsigned int offset = 0) = 0;
		virtual void onDisconnect(NetworkDisconnect reason) = 0;

	};

}
