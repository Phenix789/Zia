/**
 *
 *
 *
 */

#pragma once
#define	__LOADER_H__

#include "ZiaDefine.h"
#include "ZiaObject.h"
#include "ZiaException.h"
#include "Service.h"
#include "Module.h"

namespace ZIA_API_NAMESPACE {

	class ZiaCore;

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaLoadException, ZiaException);

	template<typename T>
	interface Handler {
	public:
		typedef T Type;
		Handler();
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
ZAN::Handler<T>::Handler() {

}

template<typename T>
ZAN::Handler<T>::~Handler() {

}

template<typename T>
ZAN::Loader<T>::Loader() {

}

template<typename T>
ZAN::Loader<T>::~Loader() {
	typename HandlerMap::iterator it = handlers.begin();
	while (it != handlers.end()) {
		delete it->second;
		it++;
	}
	handlers.clear();
}

template<typename T>
void ZAN::Loader<T>::save(const std::string & name, Handler<T> * handler) {
	typename HandlerMap::iterator it = handlers.find(name);
	if (it != handlers.end()) {
		delete it->second;
	}
	handlers[name] = handler;
}

template<typename T>
T * ZAN::Loader<T>::load(const std::string & name) {
	typename HandlerMap::iterator it = handlers.find(name);
	if (it != handlers.end()) {
		return it->second->load();
	}
	throw ZiaLoadException(name);
}
