/**
 *
 *
 *
 *
 */

#pragma once
#define __SERVICE_H__

#include <string>
#include "Define.h"
#include "tools/NonCopyable.hpp"

namespace ZIA_API_NAMESPACE {

        class Service : public utils::NonCopyable {
        public:
                Service();
                virtual ~Service();

		virtual const std::string & getName() const;

        };

}
