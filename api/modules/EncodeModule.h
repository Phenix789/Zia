/**
 *
 *
 *
 */

#pragma once
#define	__ENCODEMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class EncodeModule : public Module {
	public:
		EncodeModule();
		virtual ~EncodeModule();

                virtual const std::string & getName() const;

                virtual bool isEnable() const;
		virtual void setEnable(bool enable);

                virtual bool initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaModuleException);
                virtual bool check(const Request & request);
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException);

	};

}
