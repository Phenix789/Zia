/**
 *
 *
 *
 */

#pragma once
#define	__HTTPENCODE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "Request.h"
#include "Response.h"

#define ZIA_SERVICE_HTTP_DECODE "http_decode"
#define ZIA_SERVICE_HTTP_ENCODE "http_encode"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaDecodeException, ZiaException);
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaEncodeException, ZiaException);

	interface HTTPDecode : public Service {
	public:
		HTTPDecode() {}
		virtual ~HTTPDecode() {}

		virtual void decode(Request & request, Buffer & buffer) __throw __throw1(ZAN::ZiaDecodeException) = 0;

	};

	interface HTTPEncode : public Service {
	public:
		HTTPEncode() {}
		virtual ~HTTPEncode() {}

		virtual void encode(ZAN::Request & request, ZAN::Response& reponse) __throw __throw1(ZAN::ZiaEncodeException) = 0;

	};

}
