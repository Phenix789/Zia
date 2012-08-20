/**
 *
 *
 *
 */

#pragma once
#define	__FILEMODULE_H__

#include "ZiaDefine.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class FileModule : public Module {
	public:
		FileModule(ZiaCore & core);
		virtual ~FileModule();

                virtual const std::string & getName() const;

                virtual bool isEnable() const;
		virtual void setEnable(bool enable);

                virtual bool initialize() __throw __throw1(ZAN::ZiaModuleException);
                virtual bool check(const Request & request);
                virtual void execute(Request & request, Response & response) __throw __throw1(ZAN::ZiaModuleException);

	};

}