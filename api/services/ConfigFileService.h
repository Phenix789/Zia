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

namespace ZIA_API_NAMESPACE {

	class ConfigFileService : public Service {
	protected:

	public:
		ConfigFileService(ZiaCore & core);
		virtual ~ConfigFileService();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

	};

}
