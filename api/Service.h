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

	class ZiaCore;

        class Service : public utils::NonCopyable {
        public:
                Service(ZiaCore & core);
                virtual ~Service();

		virtual const std::string & getName() const;

        };

}
