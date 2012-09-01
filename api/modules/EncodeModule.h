/**
 *
 *
 *
 */

#pragma once
#define	__ENCODEMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

#define	ZIA_MODULE_HTTP_ENCODE "http_encode"

namespace ZIA_API_NAMESPACE {

	class EncodeModule : public Module {
	public:
		EncodeModule() {}
		virtual ~EncodeModule() {}
		
	};

}
