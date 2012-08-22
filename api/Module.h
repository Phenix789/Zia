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
#include "ZiaObject.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

        interface Module : public ZiaObject, public utils::NonCopyable {
        public:
                Module(ZiaCore & core) : ZiaObject(core) {}
                virtual ~Module() {}

                virtual const std::string & getName() const = 0;

                virtual bool isEnable() const = 0;
		virtual void setEnable(bool enable) = 0;

                virtual bool initialize() __throw __throw1(ZAN::ZiaModuleException) = 0;
                virtual bool check(const Request & request) = 0;
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException) = 0;

        };

}
