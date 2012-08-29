/**
 *
 *
 *
 */

#pragma once
#define	__FILTER_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Module.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	enum Position {
		Begin,
		End,
		Before,
		After
	};

	EXCEPTION_DECLARATION_INLINE(ZiaUnknowModuleException, ZiaException, "Unknow module " + error);

	class Filter {
	protected:
		typedef std::list<Module *> ListModule;
		const std::string name;
		ListModule modules;
		bool init;

	public:
		Filter(const std::string & name);
		virtual ~Filter();

		const std::string & getName() const;

                bool hasModule(const std::string & moduleName) const;
                Module & getModule(const std::string & moduleName) const __throw __throw1(ZAN::ZiaUnknowModuleException);

                Filter & addModule(Module __delegate * module, Position pos = End, const std::string & moduleName = "") __throw __throw1(ZAN::ZiaUnknowModuleException);
                Filter & removeModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);
		Filter & setEnableModule(const std::string & moduleName, bool enable) __throw __throw1(ZAN::ZiaUnknowModuleException);

		bool initialize(ZiaCore * core) __throw;

		void execute(Request & request, Response & response) __throw;

	};

}
