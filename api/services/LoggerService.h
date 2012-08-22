/**
 *
 *
 *
 */

#pragma once
#define	__LOGGERSERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

	class LoggerService : public Service {
	public:
		LoggerService(ZiaCore & core);
		virtual ~LoggerService();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

	};

}
