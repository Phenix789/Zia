/**
 *
 *
 *
 */

#pragma once
#define	__LISTENER_H__

#include "Network.h"
#include "Communicator.h"
#include "Receiver.h"

namespace network {

	interface Listener {
	public:
		Listener() {}
		virtual ~Listener() {}

		virtual Receiver * onAccept(Communicator * com);

	};

}
