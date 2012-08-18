/**
 *
 *
 *
 *
 */

#pragma once
#define __EXCEPTION_H__

#include "ZiaDefine.h"
#include "tools/Exception.hpp"

#define ZIA_EXCEPTION_DECLARATION(name, extend)					\
class name : public extend {							\
public:										\
	name(const std::string & error = "") throw ();				\
	virtual ~name() throw ();						\
}										\

#define ZIA_EXCEPTION_IMPLEMENTATION(name, extend, message)			\
name::name(const std::string & error)  throw ()					\
: extend(message) {								\
										\
}										\
										\
name::~name() throw () {							\
										\
}										\

#define ZIA_EXCEPTION_IMPLEMENTATION_ERROR(name, extend) ZIA_EXCEPTION_IMPLEMENTATION(name, extend, error)

namespace ZIA_API_NAMESPACE {

	/**
	 * @brief Exception fatal, provoquera un arret du server
	 */
	ZIA_EXCEPTION_DECLARATION(ZiaFatalException, utils::Exception);

	/**
	 * @brief Exception pour stopper le traitement de la requete
	 */
	ZIA_EXCEPTION_DECLARATION(ZiaStopException, utils::Exception);

	/**
	 * @brief Class d'exception du Zia
	 */
	ZIA_EXCEPTION_DECLARATION(ZiaException, utils::Exception);

	/**
	 * @brief Exception issu d'un module du server
	 */
	ZIA_EXCEPTION_DECLARATION(ZiaModuleException, ZiaException);

	/**
	 *
	 */
	ZIA_EXCEPTION_DECLARATION(ZiaServiceException, ZiaException);

}
