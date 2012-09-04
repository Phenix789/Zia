/**
 *
 *
 *
 */

#pragma once
#define	__LISTENER_H__

#include "Network.h"
#include "Communicator.h"

namespace network {

	class Listener {
	public:
		Listener() {}
		virtual ~Listener() {}

		virtual Communicator * onAccept() = 0;

	};

}
