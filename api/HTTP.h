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

	ZIA_CORE

	class ZiaDecodeException : public ZiaException {
	public:
		ZiaDecodeException(const std::string & error = "") throw ();
		virtual ~ZiaDecodeException() throw ();

	};

	class ZiaEncodeException : public ZiaException {
	public:
		ZiaEncodeException(const std::string & error = "") throw ();
		virtual ~ZiaEncodeException() throw ();

	};

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
