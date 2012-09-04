/**
 *
 *
 *
 *
 */

#pragma once
#define __RESPONSE_H__

#include "../utils/Buffer.h"
#include "ZiaDefine.h"
#include "ZiaException.h"

namespace ZIA_API_NAMESPACE {

	class Response {
	public:
		virtual ~Response(){}

		/*GETTER*/
		ResponseCode getResponseCode() const;
		const utils::Buffer & getBuffer() const;
		utils::Buffer & getBuffer();

		const utils::Buffer & getBufferHeader() const;
		utils::Buffer & getBufferHeader();

		bool hasHeader(const std::string & key) const;
		const std::string & getHeader(const std::string & key) const __throw;
		const std::string & getHeader(const std::string & key, const std::string & defaultValue) const;
		const HeaderMap & getHeaders() const;
		HeaderMap & getHeaders();

		/*SETTER*/
		Response & setResponseCode(ResponseCode code);

		Response & addHeader(const std::string & name, const std::string & value);
		Response & removeHeader(const std::string & name) __throw;
		Response & clearHeaders();

	};

}
