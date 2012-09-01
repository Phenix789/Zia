/**
 *
 *
 *
 */

#pragma once
#define	__FILEMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

#define ZIA_MODULE_FILE "file"

namespace ZIA_API_NAMESPACE {

	interface FileModule : public Module {
	public:
		FileModule() {}
		virtual ~FileModule() {}

	};

}
