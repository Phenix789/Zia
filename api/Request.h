/**
 *
 *
 *
 *
 */

#pragma once
#define __REQUEST_H__

#include "../network/Communicator.h"
#include "ZiaDefine.h"
#include "ZiaException.h"

namespace ZIA_API_NAMESPACE {

	class Request {
	public:
		Request() {}
		virtual ~Request() {}

		/*GETTER*/
		virtual const std::string & getRessource() const = 0;
		virtual const std::string & getFilename() const = 0;
		virtual const std::string & getQuery() const = 0;
		virtual RequestMethod getMethod() const = 0;
		virtual const std::string & getStringMethod() const = 0;
		virtual ProtocolVersion getProtocolVersion() const = 0;
		virtual const std::string & getStringProtocolVersion() const = 0;
		virtual const utils::Buffer & getDataBuffer() const = 0;
		virtual utils::Buffer & getDataBuffer() = 0;

		virtual bool hasHeader(const std::string & key) const = 0;
		virtual const std::string & getHeader(const std::string & key, const std::string & defaultValue = "") const = 0;
		virtual const HeaderMap & getHeaders() const = 0;
		virtual HeaderMap & getHeaders() = 0;

		/*SETTER*/
		virtual Request & setRessource(const std::string & ressource) = 0;
		virtual Request & setFilename(const std::string & ressource) = 0;
		virtual Request & setQuery(const std::string & ressource) = 0;
		virtual Request & setMethod(RequestMethod method) = 0;
		virtual Request & setProtocolVersion(ProtocolVersion version) = 0;

		virtual Request & addHeader(const std::string & key, const std::string & value) = 0;
		virtual Request & removeHeader(const std::string & key) __throw = 0;
		virtual Request & cleanHeaders() = 0;

		/*SERIALISE*/
		virtual bool serialise(utils::Buffer & buffer, int offset = 0) = 0;

	};
}
