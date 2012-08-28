/**
 *
 *
 *
 */

#pragma once
#define	__COMMUNICATOR_H__

#include "Network.h"
#include "buffer/Array.hpp"

namespace network {

	interface Communicator {
	public:
		static const unsigned int ALL = static_cast<unsigned int>(-1);

	public:
		Communicator() {}
		virtual ~Communicator() {}

		virtual Ip getIp() const = 0;
		virtual Port getPort() const = 0;

		virtual Ip getPeerIp() const = 0;
		virtual Port getPeerPort() const = 0;

		virtual int send(const utils::CharArray & buffer, unsigned int length = Communicator::ALL, unsigned int offset = 0) = 0;

	};

}
