/**
 *
 *
 *
 */

#pragma once
#define	__CONFIGFILESERVICE_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

	class ConfigFileService : public Service {
	protected:

	public:
		ConfigFileService(ZiaCore & core);
		virtual ~ConfigFileService();


	};

}
