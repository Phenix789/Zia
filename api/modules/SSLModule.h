/**
 *
 *
 *
 */

#pragma once
#define	__SSLMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class SSLModule : public Module {
	public:
		SSLModule(ZiaCore & core);
		~SSLModule();

		virtual bool check(const Request & request);
		virtual void execute(Request & request, Response & response);

	};

}
