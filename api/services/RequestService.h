/**
 *
 *
 *
 */

#pragma once
#define	__REQUESTSERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"
#include "Request.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	class RequestService : public Service {
	public:
		RequestService(ZiaCore & core);
		virtual ~RequestService();

		Request __delegate * createRequest();
		void deleteRequest(Request __delegate * request);

	};

}
