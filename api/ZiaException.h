/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIAEXCEPTION_H__

#include "../utils/Exception.h"
#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	/**
	 * @brief Exception fatal, provoquera un arret du server
	 */
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaFatalException, utils::Exception);

	/**
	 * @brief Exception pour stopper le traitement de la requete
	 */
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaStopException, utils::Exception);

	/**
	 * @brief Class d'exception du Zia
	 */
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaException, utils::Exception);

	/**
	 * @brief Exception issu d'un module du server
	 */
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaModuleException, ZiaException);

	/**
	 * @brief Exception issu d'un service du server
	 */
	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaServiceException, ZiaException);

}
