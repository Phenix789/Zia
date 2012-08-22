/**
 *
 *
 *
 *
 */

#pragma once
#define __RESPONSE_H__

#include "buffer/Array.hpp"
#include "ZiaDefine.h"
#include "ZiaObject.h"

namespace ZIA_API_NAMESPACE {

        class Response {
	protected:
		ResponseCode code;
		utils::CharArray buffer;

	public:
		Response(ZiaCore & core);
		virtual ~Response();

		/*GETTER*/
		virtual ResponseCode getResponseCode() const;
		virtual bool hasMetadata(const std::string & metadata) const;
		virtual const std::string & getMetadata(const std::string & metadata, const std::string & defaultValue = "") const __throw;
		virtual const MetadataCollection & getMetadatas() const;
		virtual MetadataCollection & getMetadatas();

		/*SETTER*/
		virtual Request & setResponseCode(ResponseCode code);
		virtual Request & setMetadata(const std::string & name, const std::string & value);
		virtual Request & removeMetadata(const std::string & name) __throw;
		virtual Request & cleanMetadatas();

        };

}