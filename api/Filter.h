/**
 *
 *
 *
 */

#pragma once
#define	__FILTER_H__

#include "ZiaDefine.h"
#include "ZiaObject.h"
#include "ZiaException.h"
#include "Module.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	enum Position {
		Begin,
		End,
		Before,
		After
	};

	EXCEPTION_DECLARATION(ZiaUnknowModuleException, ZiaException);

	class Filter : public ZiaObject {
	protected:
		typedef std::list<Module *> ListModule;
		std::string name;
		ListModule modules;
		bool enable;
		bool init;

	public:
		Filter(ZiaCore & core, const std::string & name, bool enable = true);
		virtual ~Filter();

		const std::string & getName() const;

		bool isEnable() const;
		void setEnable(bool enable);

                bool hasModule(const std::string & moduleName) const;
                Module & getModule(const std::string & moduleName) const __throw __throw1(ZAN::ZiaUnknowModuleException);

                Filter & addModule(Module __delegate * module, Position pos = End, const std::string & moduleName = "") __throw __throw1(ZAN::ZiaUnknowModuleException);
                Filter & removeModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);
		Filter & setEnableModule(const std::string & moduleName, bool enable) __throw __throw1(ZAN::ZiaUnknowModuleException);

		bool initialize() __throw;
		bool isInitialized() const;

		void execute(Request & request, Response & response) __throw;

	};

}
