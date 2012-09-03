/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIAMODULE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        class ZiaModule {
        public:
                ZiaModule() {}
                virtual ~ZiaModule() {}

                virtual const std::string & getName() const = 0;

                virtual bool initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaModuleException) = 0;
		virtual void stop() = 0;

                virtual bool check(const Request & request) = 0;
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException) = 0;

        };

}
