/**
 *
 *
 *
 */

#pragma once
#define	__DECODEMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

#define	ZIA_MODULE_HTTP_DECODE "http_decode"

namespace ZIA_API_NAMESPACE {

	interface DecodeModule : public Module {
	public:
		DecodeModule() {}
		virtual ~DecodeModule() {}

	};

}
