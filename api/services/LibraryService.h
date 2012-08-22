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

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaLibraryException, ZiaServiceException);

	class LibraryService : public Service {
	public:
		LibraryService(ZiaCore & core);
		virtual ~LibraryService();

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

		utils::LibraryHandler & loadLibrary(const std::string & library) __throw __throw1(ZAN::ZiaLibraryException);

	};

}
