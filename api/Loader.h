/**
 *
 *
 *
 */

#pragma once
#define	__LOADER_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "ZiaService.h"
#include "ZiaModule.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaLoadException, ZiaException);

	template<typename T>
	class Handler {
	public:
		typedef T Base;

		Handler() {}
		virtual ~Handler() {}

		virtual inline T __delegate * load() = 0;

	};

	template<typename T>
	class Loader {
	protected:
		typedef std::map<std::string, Handler<T> * > HandlerMap;
		HandlerMap handlers;

	public:
		Loader() {}
		virtual ~Loader() {
			typename HandlerMap::iterator it = handlers.begin();
			while (it != handlers.end()) {
				delete it->second;
				it++;
			}
			handlers.clear();
		}

		void save(const std::string & name, Handler<T> __delegate * handler) {
			typename HandlerMap::iterator it = handlers.find(name);
			if (it != handlers.end()) {
				delete it->second;
			}
			handlers[name] = handler;
		}

		T __delegate * load(const std::string & name) __throw __throw1(ZAN::ZiaLoadException) {
			typename HandlerMap::iterator it = handlers.find(name);
			if (it != handlers.end()) {
				return it->second->load();
			}
			throw ZiaLoadException(name);
		}

	};

	typedef Handler<ZiaModule> HandlerModule;
	typedef Handler<ZiaService> HandlerService;

	typedef Loader<ZiaModule> LoaderModule;
	typedef Loader<ZiaService> LoaderService;

}

#define HANDLER_CLASS(base, real) real##base

#define HANDLER_DECLARATION(base, real)						\
class HANDLER_CLASS(base, real) : public ZAN::base {				\
public:										\
	virtual inline typename ZAN::base::Base __delegate * load() {	\
		return new real();						\
	}									\
}										\

#define HANDLER_MODULE_CLASS(real) HANDLER_CLASS(HandlerModule, real)
#define HANDLER_SERVICE_CLASS(real) HANDLER_CLASS(HandlerService, real)

#define HMC(real) HANDLER_MODULE_CLASS(real)
#define HSC(real) HANDLER_SERVICE_CLASS(real)

#define HANDLER_MODULE_DECLARATION(real) HANDLER_DECLARATION(HandlerModule, real)
#define HANDLER_SERVICE_DECLARATION(real) HANDLER_DECLARATION(HandlerService, real)
