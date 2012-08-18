/**
 *
 *
 *
 *
 */

#pragma once
#define __REQUEST_H__

#include "ZiaDefine.h"
#include "ZiaObject.h"

namespace ZIA_API_NAMESPACE {

	class Request {
	protected:
		std::string ressource;
		RequestMethod method;
		ProtocolVersion version;
		ParameterMap headers;

	public:
		Request(ZiaCore & core);
		virtual ~Request();

		/*GETTER*/
		RequestMethod getMethod() const;
		const std::string & getStringMethod() const;
		const std::string & getRessource() const;
		ProtocolVersion getProtocolVersion() const;
		bool hasMetadata(const std::string & metadata) const;
		const std::string & getMetadata(const std::string & metadata, const std::string & defaultValue = "") const;
		const ParameterMap & getMetadatas() const;
		ParameterMap & getMetadatas();

		/*SETTER*/
		Request & setMethod(RequestMethod method);
		Request & setProtocolVersion(ProtocolVersion version);
		Request & setMetadata(const std::string & name, const std::string & value);
		Request & removeMetadata(const std::string & name) __throw;
		Request & cleanMetadatas();

	};
}
