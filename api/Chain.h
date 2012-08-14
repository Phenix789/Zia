/**
 *
 *
 *
 *
 */

#pragma once
#define __CHAIN_H__

#include <string>
#include "Define.h"
#include "Module.h"
#include "Service.h"
#include "Request.h"
#include "Response.h"
#include "Exception.h"

namespace ZIA_API_NAMESPACE {

        class ZiaUnknowModuleException : public ZiaException {
        public:
                ZiaUnknowModuleException(const std::string & moduleName);
                virtual ~ZiaUnknowModuleException();

        };

        class Chain : public Service {
        public:

                enum Position {
                        Before,
                        After
                };

        public:
                Chain();
                virtual ~Chain();

                /*Chain*/


                /*Module*/
                bool hasModule(const std::string & moduleName) const;
                Module & getModule(const std::string & moduleName) const __throw __throw1(ZiaUnknowModuleException);

                Chain & addModule(Module __delegate * module, const std::string & link, Position pos = After) __throw __throw1(ZiaUnknowModuleException);
                Chain & removeModule(const std::string & moduleName) __throw __throw1(ZiaUnknowModuleException);

                Chain & enableModule(const std::string & moduleName) __throw __throw1(ZiaUnknowModuleException);
                Chain & disableModule(const std::string & moduleName) __throw __throw1(ZiaUnknowModuleException);

                /*Execution*/
                bool initialize() __throw;
                void execute(Request & request, Response & response) __throw;

        };

}
