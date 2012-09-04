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
		virtual ResponseCode getResponseCode() const = 0;
		virtual const utils::Buffer & getBuffer() const = 0;
		virtual utils::Buffer & getBuffer() = 0;

		virtual const utils::Buffer & getBufferHeader() const = 0;
		virtual utils::Buffer & getBufferHeader() = 0;

		virtual bool hasHeader(const std::string & key) const = 0;
		virtual const std::string & getHeader(const std::string & key) const __throw = 0;
		virtual const std::string & getHeader(const std::string & key, const std::string & defaultValue) const = 0;
		virtual const HeaderMap & getHeaders() const = 0;
		virtual HeaderMap & getHeaders() = 0;

		/*SETTER*/
		virtual Response & setResponseCode(ResponseCode code) = 0;

		virtual Response & addHeader(const std::string & name, const std::string & value) = 0;
		virtual Response & removeHeader(const std::string & name) __throw = 0;
		virtual Response & clearHeaders() = 0;

	};

}
