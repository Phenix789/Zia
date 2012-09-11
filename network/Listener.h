/**
 *
 *
 *
 */

#pragma once
#define	__LISTENER_H__

#include "Network.h"
#include "Communicator.h"
#include "NetObject.h"

namespace network{

	class Listener  : public NetObject{
	public:
		Listener() {}
		virtual ~Listener() {}

		virtual Communicator * onAccept() = 0;

	};

}
