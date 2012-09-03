/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include "../network/Communicator.h"
#include "ZiaDefine.h"
#include "ZiaException.h"
#include "ZiaService.h"
#include "ZiaModule.h"

#define ZIA_SERVICE_ZIA_CORE "zia_core"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaCoreException, ZiaFatalException);

        class ZiaCore : public ZiaService {
        public:
                ZiaCore() {}
                virtual ~ZiaCore() {}

		virtual void initialize() __throw = 0;
		virtual void run() = 0;

		virtual void onReceive(network::Communicator & receiver, utils::Buffer & buffer) = 0;

		virtual ZiaService * getService(const std::string & name) = 0;

        };

}
