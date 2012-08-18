/**
 *
 *
 *
 */

#pragma once
#define	__LIBRARYSERVICE_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"
#include "library/LibraryHandle.h"

namespace ZIA_API_NAMESPACE {

	class ZiaLibraryException : public ZiaServiceException {
	public:
		ZiaLibraryException(const std::string & libraryName);
		virtual ~ZiaLibraryException();

	};

	class LibraryService : public Service {
	public:
		LibraryService(ZiaCore & core);
		virtual ~LibraryService();

		utils::LibraryHandle & loadLibrary(const std::string & library) __throw __throw1(ZAN::ZiaLibraryException);

	};

}
