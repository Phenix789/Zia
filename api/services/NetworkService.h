/**
 *
 *
 *
 */

#pragma once
#define	__NETWORKSERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"
#include "NetService.h"

#define ZIA_SERVICE_NETWORK "network"

namespace ZIA_API_NAMESPACE {

	interface NetworkService : public Service {
	public:
		NetworkService() {}
		virtual ~NetworkService() {}

		virtual network::NetService & getCoreNetService() = 0;
		virtual network::NetService __delegate * getNewNetService() = 0;

	};

}
