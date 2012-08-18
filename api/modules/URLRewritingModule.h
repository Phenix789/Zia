/**
 *
 *
 *
 */

#pragma once
#define	__URLREWRITINGMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class URLRewritingModule : public Module {
	public:
		URLRewritingModule(ZiaCore & core);
		~URLRewritingModule();

		virtual bool check(const Request & request);
		virtual void execute(Request & request, Response & response);

	};

}
