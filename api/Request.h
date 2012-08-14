/**
 *
 *
 *
 *
 */

#pragma once
#define __REQUEST_H__

#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	class Request {
	public:
		Request(ZiaCore & core) {}
		virtual ~Request() {}

		/*GETTER*/
		virtual RequestMethod getMethod() const;
		virtual const std::string & getStringMethod() const;
		virtual const std::string & getRessource() const;
		virtual ProtocolVersion getProtocolVersion() const;
		virtual bool hasMetadata(const std::string & metadata) const;
		virtual const std::string & getMetadata(const std::string & metadata, const std::string & defaultValue = "") const __throw;
		virtual const MetadataCollection & getMetadatas() const;
		virtual MetadataCollection & getMetadatas();

		/*SETTER*/
		virtual Request & setMethod(RequestMethod method);
		virtual Request & setProtocolVersion(ProtocolVersion version);
		virtual Request & setMetadata(const std::string & name, const std::string & value);
		virtual Request & removeMetadata(const std::string & name) __throw;
		virtual Request & cleanMetadatas();

	};
}
