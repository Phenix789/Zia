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

	ZIA_CORE

	class LoggerService : public Service {
	public:
		LoggerService(ZiaCore & core);
		virtual ~LoggerService();

	};

}
