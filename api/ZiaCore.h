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

        class ZiaCoreException : public ZiaFatalException {
        public:
                ZiaCoreException(const std::string & error = "");
                virtual ~ZiaCoreException();

        };

        class ZiaCore : public Service {
        public:
                ZiaCore();
                virtual ~ZiaCore();

        };

}
