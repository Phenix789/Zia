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
#include "library/LibraryHandle.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION(ZiaLibraryException, ZiaServiceException);

	class LibraryService : public Service {
	public:
		LibraryService(ZiaCore & core);
		virtual ~LibraryService();

		utils::LibraryHandle & loadLibrary(const std::string & library) __throw __throw1(ZAN::ZiaLibraryException);

	};

}
