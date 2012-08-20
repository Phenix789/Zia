/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include <vector>

#include "network/Listener.h"

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "ServiceManager.h"
#include "Module.h"
#include "Chain.h"
#include "Loader.h"
#include "ZiaWorkerUnit.h"

#include "services/NetworkService.h"
#include "services/ConfigFileService.h"
#include "services/HTTP.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION(ZiaCoreException, ZiaFatalException);

        class ZiaCore : public Service, public utils::Listener {
	protected:
		typedef std::vector<ZiaWorkerUnit> ExecuteUnits;
		LoaderModule loaderModule;
		LoaderService loaderService;
		Chain chain;
		ExecuteUnits units;

        public:
                ZiaCore();
                virtual ~ZiaCore();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException, ZAN::ZiaCoreException);

		virtual void onReceive(const utils::CharArray & request);
		virtual void onWorkerFinish(ZiaWorkerUnit * unit);

        };

}
