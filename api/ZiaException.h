/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIAEXCEPTION_H__

#include "ZiaDefine.h"
#include "tools/Exception.hpp"

namespace ZIA_API_NAMESPACE {

	/**
	 * @brief Exception fatal, provoquera un arret du server
	 */
	EXCEPTION_DECLARATION(ZiaFatalException, utils::Exception);

	/**
	 * @brief Exception pour stopper le traitement de la requete
	 */
	EXCEPTION_DECLARATION(ZiaStopException, utils::Exception);

	/**
	 * @brief Class d'exception du Zia
	 */
	EXCEPTION_DECLARATION(ZiaException, utils::Exception);

	/**
	 * @brief Exception issu d'un module du server
	 */
	EXCEPTION_DECLARATION(ZiaModuleException, ZiaException);

	/**
	 *
	 */
	EXCEPTION_DECLARATION(ZiaServiceException, ZiaException);

}
