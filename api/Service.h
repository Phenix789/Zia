/**
 *
 *
 *
 *
 */

#pragma once
#define __SERVICE_H__

#include "ZiaDefine.h"
#include "ZiaObject.h"
#include "Exception.h"
#include "tools/NonCopyable.hpp"

namespace ZIA_API_NAMESPACE {

        interface Service : public ZiaObject, public utils::NonCopyable {
        public:
                Service(ZiaCore & core) : ZiaObject(core) {}
                virtual ~Service() {}

		virtual const std::string & getName() const = 0;

		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException) = 0;

        };

}
