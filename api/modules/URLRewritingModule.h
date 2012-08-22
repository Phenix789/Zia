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

                virtual const std::string & getName() const;

                virtual bool isEnable() const;
		virtual void setEnable(bool enable);

                virtual bool initialize() __throw __throw1(ZAN::ZiaModuleException);
                virtual bool check(const Request & request);
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException);

	};

}
