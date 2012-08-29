/**
 *
 *
 *
 */

#pragma once
#define __SERVICE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "tools/NonCopyable.hpp"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        interface Service : public utils::NonCopyable {
        public:
                Service() {}
                virtual ~Service() {}

		virtual const std::string & getName() const = 0;

		virtual void initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaServiceException) = 0;

        };

}
