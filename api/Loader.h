/**
 *
 *
 *
 */

#pragma once
#define	__LOADER_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class ZiaLoadException : public ZiaException {
	public:
		ZiaLoadException(const std::string & error = "") throw ();
		virtual ~ZiaLoadException() throw ();

	};

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
		T __delegate * load(const std::string & name) __throw __throw1(ZAN::ZiaLoadException);

	};

	typedef Handler<Module> HandlerModule;
	typedef Handler<Service> HandlerService;
	
	typedef Loader<Module> LoaderModule;
	typedef Loader<Service> LoaderService;

}
