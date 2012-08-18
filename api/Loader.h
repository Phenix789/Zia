/**
 *
 *
 *
 */

#pragma once
#define	__LOADER_H__

#include "ZiaDefine.h"
#include "ZiaObject.h"
#include "Exception.h"
#include "Service.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class ZiaCore;

	ZIA_EXCEPTION_DECLARATION(ZiaLoadException, ZiaException);

	template<typename T>
	interface Handler : public ZiaObject {
	public:
		typedef T Type;
		Handler(ZiaCore & core);
		virtual ~Handler();

		virtual T __delegate * load() = 0;

	};

	template<typename T>
	class Loader {
	protected:
		typedef std::map<std::string, Handler<T> * > HandlerMap;
		HandlerMap handlers;

	public:
		typedef T Type;
		Loader();
		virtual ~Loader();

		void save(const std::string & name, Handler<T> __delegate * handler);
		T __delegate * load(const std::string & name) __throw __throw1(ZAN::ZiaLoadException);

	};

	typedef Handler<Module> HandlerModule;
	typedef Handler<Service> HandlerService;

	typedef Loader<Module> LoaderModule;
	typedef Loader<Service> LoaderService;

}

/*Template implementation*/

template<typename T>
ZAN::Handler::Handler(ZiaCore & core)
: ZiaObject(core) {

}

template<typename T>
ZAN::Handler::~Handler() {

}

template<typename T>
ZAN::Loader::Loader() {

}

template<typename T>
ZAN::Loader::~Loader() {
	HandlerMap::iterator it = handlers.begin();
	while (it != handlers.end()) {
		delete it->second;
		it++;
	}
	handlers.clear();
}

template<typename T>
void ZAN::Loader::save(const std::string & name, Handler<T> * handler) {
	HandlerMap::iterator it = handlers.find(name);
	if (it != handlers.end()) {
		delete *it;
	}
	handlers[name] = handler;
}

template<typename T>
T * ZAN::Loader::load(const std::string & name) {
	HandlerMap::iterator it = handlers.find(name);
	if (it != handlers.end()) {
		return it->second->load();
	}
	throw ZiaLoadException(name);
}
