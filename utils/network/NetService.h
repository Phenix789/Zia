/**
 *
 *
 *
 */

#pragma once
#define	__NETSERVICE_H__

#include "Define.h"
#include "Listener.h"

namespace utils {

	class NetService {
	public:
		NetService();
		virtual ~NetService();

		void listen(Listener * listener, int port);
		void flushEvent();

		void start();

	};

}
