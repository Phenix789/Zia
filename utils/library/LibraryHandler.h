/**
 *
 *
 *
 */

#pragma once
#define	__LIBRARYHANDLER_H__

#include <string>
#include "Define.h"
#include "tools/Exception.hpp"

#if defined WINDOWS
#include <windows.h>
typedef HMODULE basic_handle;
#elif defined LINUX
#include <dlfcn.h>
typedef void * basic_handle;
#endif

namespace utils {

	EXCEPTION_DECLARATION_INLINE_ERROR(LibraryHandlerException, utils::Exception);

	class LibraryHandler {
	protected:
		basic_handle dlhandle;

	public:
		inline LibraryHandler();
		inline virtual ~LibraryHandler();

		inline void loadLib(const std::string & fileName) __throw __throw1(utils::LibraryHandlerException);
		inline void closeLib();

		template<typename T>
		inline T getFunction(const std::string & funcName) const __throw __throw1(utils::LibraryHandlerException);

	};

}
