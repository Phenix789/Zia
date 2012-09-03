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
		Request(network::Communicator & user, utils::Buffer & buffer);
		virtual ~Request();

		/*GETTER*/
		const std::string & getRessource() const;
		const std::string & getFilename() const;
		const std::string & getQuery() const;
		RequestMethod getMethod() const;
		const std::string & getStringMethod() const;
		ProtocolVersion getProtocolVersion() const;
		const std::string & getStringProtocolVersion() const;
		const network::Communicator & getCommunicator() const;
		network::Communicator & getCommunicator();
		const utils::Buffer & getBuffer() const;
		utils::Buffer & getBuffer();

		bool hasHeader(const std::string & key) const;
		const std::string & getHeader(const std::string & key) const __throw;
		const std::string & getHeader(const std::string & key, const std::string & defaultValue) const;
		const HeaderMap & getHeaders() const;
		HeaderMap & getHeaders();

		/*SETTER*/
		Request & setRessource(const std::string & ressource);
		Request & setFilename(const std::string & ressource);
		Request & setQuery(const std::string & ressource);
		Request & setMethod(RequestMethod method);
		Request & setProtocolVersion(ProtocolVersion version);
		Request & setBuffer(utils::Buffer & buffer);

		Request & addHeader(const std::string & key, const std::string & value);
		Request & removeHeader(const std::string & key) __throw;
		Request & cleanHeaders();

	};
}
