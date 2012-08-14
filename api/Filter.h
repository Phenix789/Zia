/**
 *
 *
 *
 */

#pragma once
#define	__FILTER_H__

#include <list>
#include "ZiaDefine.h"
#include "Module.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	class Filter {
	protected:
		typedef std::list<Module *> ListModule;
		ZiaCore & core;
		std::string name;
		ListModule modules;
		bool enable;

	public:
		Filter(ZiaCore & core, const std::string & name);
		virtual ~Filter();

		const std::string & getName() const;

		bool isEnable();
		Filter & setEnable(bool enable);

		bool initialise() __throw;
		void execute(Request & request, Response & response) __throw;

	};

}
