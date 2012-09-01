/**
 *
 *
 *
 */

#pragma once
#define	__RECEIVER_H__

#include "Define.h"
#include "buffer/Array.hpp"
#include "Network.h"
#include "Communicator.h"

namespace network {

	interface Receiver {
	public:
		Receiver() {}
		virtual ~Receiver() {}

		virtual void onReceive(utils::CharArray & buffer) = 0;
		virtual void onDisconnect(NetworkDisconnect reason) = 0;

		virtual void setCommunicator(Communicator * com) = 0;
		virtual Communicator * getCommunicator() = 0;

	};

}
