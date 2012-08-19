/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include "network/Listener.h"

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "ServiceManager.h"
#include "Module.h"
#include "Chain.h"
#include "Loader.h"

#include "services/NetworkService.h"
#include "services/ConfigFileService.h"
#include "services/HTTP.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION(ZiaCoreException, ZiaFatalException);

        class ZiaCore : public Service, public utils::Listener {
	protected:
		LoaderModule loaderModule;
		LoaderService loaderService;
		Chain chain;

		ConfigFileService & config;
		NetworkService & network;
		HTTPDecode & decoder;
		HTTPEncode & encoder;

        public:
                ZiaCore();
                virtual ~ZiaCore();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException, ZAN::ZiaCoreException);

		virtual void onReceive(const utils::CharArray & request);

        };

}
