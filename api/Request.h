/**
 *
 *
 *
 *
 */

#pragma once
#define __REQUEST_H__

#include <string>
#include "Define.h"

namespace ZIA_API_NAMESPACE {

	class Request {
	public:
		typedef int MetadataCollection;

	public:

		Request() {}
		virtual ~Request() {}

		/*GETTER*/
		virtual RequestMethod getMethod() const = 0;
		virtual const std::string & getStringMethod() const = 0;
		virtual const std::string & getRessource() const = 0;
		virtual ProtocolVersion getProtocolVersion() const = 0;
		virtual bool hasMetadata(const std::string & metadata) const = 0;
		virtual const std::string & getMetadata(const std::string & metadata, const std::string & defaultValue = "") const __throw = 0;
		virtual const MetadataCollection & getMetadatas() const = 0;
		virtual MetadataCollection & getMetadatas() = 0;

		/*SETTER*/
		virtual Request & setMethod(RequestMethod method) = 0;
		virtual Request & setStringMethod(const std::string & method) = 0;
		virtual Request & setProtocolVersion() = 0;
		virtual Request & setMetadata(const std::string & name, const std::string & value) = 0;

	};
}
