/**
 *
 *
 *
 */

#pragma once
#define	__COMMUNICATOR_H__

#include "../utils/Buffer.h"
#include "Network.h"
#include "NetObject.h"

namespace network {

	class Communicator : public NetObject {
	public:
		static const unsigned int ALL = static_cast<unsigned int>(-1);

	public:
		Communicator() {}
		virtual ~Communicator() {}

		virtual void onReceive(utils::Buffer & buffer) = 0;

		virtual void disconnect() = 0;
		virtual int read(utils::Buffer & buffer, unsigned int length) = 0;
		virtual int send(const utils::Buffer & buffer, unsigned int length = Communicator::ALL, unsigned int offset = 0) = 0;

	};

}
