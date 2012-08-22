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

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

	};

}
