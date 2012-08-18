/**
 *
 *
 *
 */

#pragma once
#define	__NETWORKSERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

	class NetworkService : public Service {
	public:
		NetworkService(ZiaCore & core);
		virtual ~NetworkService();

	};

}
