/**
 *
 *
 *
 */

#pragma once
#define	__CONFIGFILESERVICE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"

#define ZIA_SERVICE_CONFIG_FILE "config_file"

namespace ZIA_API_NAMESPACE {

	interface ConfigFileService : public Service {
	protected:

	public:
		ConfigFileService(ZiaCore & core) : Service(core) {}
		virtual ~ConfigFileService() {}

		virtual ZiaConfigFile & getConfigFile() = 0;

	};

}
