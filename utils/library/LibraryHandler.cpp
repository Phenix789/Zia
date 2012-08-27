/**
 *
 *
 *
 */

#include "LibraryHandler.h"

utils::LibraryHandler::LibraryHandler()
: dlhandle(NULL) {

}

utils::LibraryHandler::~LibraryHandler() {
	closeLib();
}

#if defined WINDOWS

void utils::LibraryHandler::loadLib(const std::string & fileName) {
	closeLib();
	wchar_t * wideFileName = new wchar_t[fileName.size() + 1];
	for (unsigned int i = 0; i < fileName.size(); i++) {
		wideFileName[i] = fileName[i];
	}
	wideFileName[fileName.size()] = 0;
	dlhandle = LoadLibrary(wideFileName);
	delete [] wideFileName;
	if (!dlhandle) {
		throw LibraryHandlerException("Cannot load library " + fileName);
	}
}

void utils::LibraryHandler::closeLib() {
	if (dlhandle) {
		FreeLibrary(dlhandle);
		dlhandle = NULL;
	}
}

template<typename T>
T utils::LibraryHandler::getFunction(const std::string & funcName) const {
	if (dlhandle) {
		T func = NULL;
		func = reinterpret_cast<T> (GetProcAddress(dlhandle, funcName.c_str()));
		if (!func) {
			throw LibraryHandlerException("Invalid symbol " + funcName);
		}
		return func;
	}
	throw LibraryHandlerException("Library not loaded");
}

#elif defined LINUX

void utils::LibraryHandler::loadLib(const std::string & fileName) {
	closeLib();
	dlhandle = dlopen(fileName.c_str(), RTLD_LAZY);
	if (!dlhandle) {
		throw LibraryHandlerException(dlerror());
	}
}

void utils::LibraryHandler::closeLib() {
	if (dlhandle) {
		(void) dlclose(dlhandle);
		dlhandle = NULL;
	}
}

template<typename T>
T utils::LibraryHandler::getFunction(const std::string & funcName) const {
	if (dlhandle) {
		T func = NULL;
		func = reinterpret_cast<T> (dlsym(dlhandle, funcName.c_str()));
		if (!func) {
			throw LibraryHandlerException("Invalid symbol " + funcName);
		}
		return func;
	}
	throw LibraryHandlerException("Library not loaded");
}

#endif
