/**
 *
 *
 *
 *
 */

#pragma once
#define __RESPONSE_H__

#include "collection/Collection.hpp"
#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	class Response {
	protected:
		ResponseCode code;
		utils::Collection headers;
		Buffer buffer;

	public:
		Response();
		virtual ~Response();

		/*GETTER*/
		ResponseCode getResponseCode() const;
		const Buffer & getBuffer() const;
		Buffer & getBuffer();

		bool hasHeader(const std::string & key) const;
		const utils::Variant & getHeader(const std::string & key) const __throw;
		const utils::Variant & getHeader(const std::string & key, const utils::Variant & defaultValue) const;
		const utils::Collection & getHeaders() const;
		utils::Collection & getHeaders();

		/*SETTER*/
		Response & setResponseCode(ResponseCode code);

		Response & addHeader(const std::string & name, const std::string & value);
		Response & addHeader(const std::string & name, const utils::Variant & value);
		Response & removeHeader(const std::string & name) __throw;
		Response & clearHeaders();

	};

}
