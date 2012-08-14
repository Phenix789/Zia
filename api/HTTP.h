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

	class ZiaDecodeException : public ZiaException {
	public:
		ZiaDecodeException(const std::string & error = "");
		virtual ~ZiaDecodeException();

	};

	class ZiaEncodeException : public ZiaException {
	public:
		ZiaEncodeException(const std::string & error = "");
		virtual ~ZiaEncodeException();

	};

	class HTTPDecode : public Service {
	public:
		HTTPDecode(ZiaCore & core);
		virtual ~HTTPEncode();

		void decode(Request & request, Buffer & buffer) __throw __throw1(ZiaDecodeException);

	};

	class HTTPEncode : public Service {
	public:
		HTTPEncode(ZiaCore & core);
		virtual ~HTTPDecode();

		void encode(Response & response, Buffer & buffer) __throw __throw1(ZiaEncodeException);

	};

}
