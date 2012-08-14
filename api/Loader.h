/**
 *
 *
 *
 */

#pragma once
#define	__LOADER_H__

#include "ZiaDefine.h"
#include "Service.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	template<typename T>
	class Handler {
	public:
		Handler();
		virtual ~Handler();

		T __delegate * load();

	};

	template<typename T>
	class Loader {
	public:
		Loader();
		virtual ~Loader();

		void save(const std::string & name, Handler<T> handler);
		T __delegate * load(const std::string & name);

	};

	typedef Loader<Module> LoaderModule;
	typedef Loader<Service> LoaderService;

}
