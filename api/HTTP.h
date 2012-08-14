/**
 *
 *
 *
 */

#pragma once
#define	__HTTPENCODE_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"
#include "Request.h"
#include "Response.h"
#include "ZiaCore.h"

namespace ZIA_API_NAMESPACE {

	class HTTPDecode : public Service {
	public:
		HTTPDecode(ZiaCore & core);
		virtual ~HTTPEncode();

		void decode(Request & request, Buffer & buffer);

	};

	class HTTPEncode : public Service {
	public:
		HTTPEncode(ZiaCore & core);
		virtual ~HTTPDecode();

		void encode(Response & response, Buffer & buffer);

	};

}
