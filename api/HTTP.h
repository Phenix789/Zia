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

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION(ZiaDecodeException, ZiaException);
	EXCEPTION_DECLARATION(ZiaEncodeException, ZiaException);

	class HTTPDecode : public Service {
	public:
		HTTPDecode(ZiaCore & core);
		virtual ~HTTPEncode();

		void decode(Request & request, Buffer & buffer) __throw __throw1(ZAN::ZiaDecodeException);

	};

	class HTTPEncode : public Service {
	public:
		HTTPEncode(ZiaCore & core);
		virtual ~HTTPDecode();

		void encode(Response & response, Buffer & buffer) __throw __throw1(ZAN::ZiaEncodeException);

	};

}
