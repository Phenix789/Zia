/**
 *
 *
 *
 */

#pragma once
#define	__RESPONSESERVICE_H__

#include "ZiaDefine.h"
#include "Service.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	class ResponseService : public Service {
	public:
		ResponseService(ZiaCore & core);
		virtual ~ResponseService();

		Response __delegate * createResponse();
		void deleteResponse(Response __delegate * response);

	};

}
