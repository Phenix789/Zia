/**
 *
 *
 *
 *
 */

#pragma once
#define __SERVICE_H__

#include "ZiaDefine.h"
#include "tools/NonCopyable.hpp"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        class Service : public utils::NonCopyable {
        public:
                Service(ZiaCore & core);
                virtual ~Service();

		virtual const std::string & getName() const;

		virtual void initialise(ParameterMap & parameters);

        };

}
