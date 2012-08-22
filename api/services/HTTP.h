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

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaDecodeException, ZiaException);
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaEncodeException, ZiaException);

	class HTTPDecode : public Service {
	public:
		HTTPDecode(ZiaCore & core);
		virtual ~HTTPDecode();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

		void decode(Request & request, Buffer & buffer) __throw __throw1(ZAN::ZiaDecodeException);

	};

	class HTTPEncode : public Service {
	public:
		HTTPEncode(ZiaCore & core);
		virtual ~HTTPEncode();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

		void encode(Response & response, Buffer & buffer) __throw __throw1(ZAN::ZiaEncodeException);

	};

}
