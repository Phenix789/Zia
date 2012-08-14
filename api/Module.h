/**
 *
 *
 *
 *
 */

#pragma once
#define __MODULE_H__

#include <string>
#include "ZiaDefine.h"
#include "tools/NonCopyable.hpp"

namespace ZIA_API_NAMESPACE {

        class Module : public utils::NonCopyable {
        public:
                Module();
                virtual ~Module();

                virtual const std::string & getName() const = 0;

                virtual bool isEnable() const = 0;
                virtual void disable() = 0;
                virtual void enable() = 0;

                virtual bool initialize() __throw __throw1(ZiaModuleException) = 0;
                virtual bool check(Request & request) = 0;
                virtual void execute(Request & request, Response & response) __throw __throw1(ZiaModuleException) = 0;

        };

}