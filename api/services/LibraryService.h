/**
 *
 *
 *
 */

#pragma once
#define	__LIBRARYSERVICE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "library/LibraryHandler.h"

#define ZIA_SERVICE_LIBRARY "library"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaLibraryException, ZiaServiceException);

	interface LibraryService : public Service {
	public:
		LibraryService(ZiaCore & core) : Service(core) {}
		virtual ~LibraryService() {}

		utils::LibraryHandler & loadLibrary(const std::string & library) __throw __throw1(ZAN::ZiaLibraryException) = 0;

	};

}
