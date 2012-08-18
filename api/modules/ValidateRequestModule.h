/**
 *
 *
 *
 */

#pragma once
#define	__VALIDATEREQUESTMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class ValidateRequestModule : public Module {
	public:
		ValidateRequestModule(ZiaCore & core);
		virtual ~ValidateRequestModule();

	};

}
