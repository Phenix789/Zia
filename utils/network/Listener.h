/**
 *
 *
 *
 */

#pragma once
#define	__LISTENER_H__

#include "Define.h"
#include "Receiver.h"

namespace utils {

	typedef unsigned int Ip;
	typedef unsigned int Port;

	interface Listener {
	public:
		Listener() {}
		virtual ~Listener() {}

		virtual utils::Receiver * onAccept(Ip ip, Port port);

	};

}
