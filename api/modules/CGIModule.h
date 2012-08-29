/**
 *
 *
 *
 */

#pragma once
#define	__CGIMODULES_H__

#include "ZiaDefine.h"
#include "Module.h"
#include "collection/Collection.hpp"

namespace ZIA_API_NAMESPACE {

	/**
	 * @class CGIModule
	 * @brief Abstract class for implement CGI module, RFC 3875
	 */
	abstract class CGIModule : public Module {
	public:
		/**
		 * @enum MetaVariable
		 * @brief Request meta-variables declared in RFC 3875
		 */
		enum MetaVariable {
			AUTH_TYPE,
			CONTENT_LENGTH,
			CONTENT_TYPE,
			GATEWAY_INTERFACE,
			PATH_INFO,
			PATH_TRANSLATED,
			QUERY_STRING,
			REMOTE_ADDR,
			REMOTE_HOST,
			REMOTE_IDENT,
			REMOTE_USER,
			REQUEST_METHOD,
			SCRIPT_NAME,
			SERVER_NAME,
			SERVER_PORT,
			SERVER_PROTOCOL,
			SERVER_SOFTWARE
		};

	protected:
		utils::Collection meta_vars;

	public:
		CGIModule();
		virtual ~CGIModule();

		virtual bool initialize() __throw __throw1(ZAN::ZiaModuleException);

		void setBasicMetaVariable(Request & request);
		void setMetaVariable(MetaVariable key, const utils::Variant & value);
		void setMetaVariable(MetaVariable key, utils::Variant value);
		void setMetaVariable(const std::string & key, const utils::Variant & value);
		void setMetaVariable(const std::string & key, utils::Variant value);

		void call(Request & request, Response & response, const std::string & executable);

		static const std::string & getMetaVariableString(MetaVariable key);
		static MetaVariable getMetaVariable(const std::string & key);

	};

}
