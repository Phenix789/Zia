/**
 *
 *
 *
 */

#pragma once
#define	__LOGGERSERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"

#define ZIA_SERVICE_LOGGER "logger"

namespace ZIA_API_NAMESPACE {

	class Logger;

	interface LoggerService : public Service {
	public:
		LoggerService(ZiaCore & core) : Service(core) {}
		virtual ~LoggerService() {}

		virtual Logger message() = 0;
		virtual Logger warning() = 0;
		virtual Logger error() = 0;
		virtual Logger debug() = 0;

	};

}
