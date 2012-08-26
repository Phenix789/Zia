/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "ServiceManager.h"
#include "Module.h"
#include "Chain.h"
#include "Loader.h"
#include "ZiaWorker.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaCoreException, ZiaFatalException);

        class ZiaCore : public Service {
	protected:
		LoaderModule loaderModule;
		LoaderService loaderService;
		ServiceManager services;
		Chain chain;

        public:
                ZiaCore();
                virtual ~ZiaCore();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw2(ZAN::ZiaServiceException, ZAN::ZiaCoreException);

		virtual const Chain & getChain() const;

		virtual void onReceive(const Buffer & request);

        };

}
