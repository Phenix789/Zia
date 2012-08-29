/**
 *
 *
 *
 *
 */

#pragma once
#define __MODULE_H__

#include "tools/NonCopyable.hpp"
#include "ZiaDefine.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        interface Module : public utils::NonCopyable {
        public:
                Module() {}
                virtual ~Module() {}

                virtual const std::string & getName() const = 0;

                virtual bool initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaModuleException) = 0;
                virtual bool check(const Request & request) = 0;
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException) = 0;

        };

}
