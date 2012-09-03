/**
 *
 *
 *
 */

#pragma once
#define __ZIASERVICE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        class ZiaService {
        public:
                ZiaService() {}
                virtual ~ZiaService() {}

		virtual const std::string & getName() const = 0;

		virtual bool initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaServiceException) __throw __throw1(ZAN::ZiaServiceException) = 0;
		virtual void stop() = 0;

        };

}
