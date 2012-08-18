/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"
#include "ServiceManager.h"
#include "Module.h"
#include "Chain.h"

namespace ZIA_API_NAMESPACE {

	ZIA_EXCEPTION_DECLARATION(ZiaCoreException, ZiaFatalException);

        class ZiaCore : public Service {
        public:
                ZiaCore();
                virtual ~ZiaCore();

        };

}
