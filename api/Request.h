/**
 *
 *
 *
 *
 */

#pragma once
#define __REQUEST_H__

#include "collection/Collection.hpp"
#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	class Request {
	protected:
		std::string ressource;
		RequestMethod method;
		ProtocolVersion version;
		utils::Collection headers;
		Buffer & buffer;

	public:
		Request(Buffer & buffer);
		virtual ~Request();

		/*GETTER*/
		const std::string & getRessource() const;
		RequestMethod getMethod() const;
		const std::string & getStringMethod() const;
		ProtocolVersion getProtocolVersion() const;
		const std::string & getStringProtocolVersion() const;
		const Buffer & getBuffer() const;

		bool hasHeader(const std::string & key) const;
		const utils::Variant & getHeader(const std::string & key) const __throw;
		const utils::Variant & getHeader(const std::string & key, const utils::Variant & defaultValue) const;
		const utils::Collection & getHeaders() const;
		utils::Collection & getHeaders();

		/*SETTER*/
		Request & setRessource(const std::string & ressource);
		Request & setMethod(RequestMethod method);
		Request & setProtocolVersion(ProtocolVersion version);
		Request & setBuffer(Buffer & buffer);

		Request & addHeader(const std::string & key, const std::string & value);
		Request & addHeader(const std::string & key, const utils::Variant & value);
		Request & removeHeader(const std::string & key) __throw;
		Request & cleanHeaders();

	};
}
