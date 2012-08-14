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

namespace ZIA_API_NAMESPACE {

	/**
	 * @brief Exception fatal, provoquera un arret du server
	 *
	 */
	class ZiaFatalException : public utils::Exception {
	public:
		ZiaFatalException(const std::string & error = "") throw ();
		virtual ~ZiaFatalException() throw ();

	};

	/**
	 * @brief Exception pour stopper le traitement de la requete
	 *
	 */
	class ZiaStopException : public utils::Exception {
	public:
		ZiaStopException(const std::string & error = "") throw ();
		virtual ~ZiaStopException() throw ();

	};

	/**
	 * @brief Class d'exception du Zia
	 *
	 */
	class ZiaException : public ZiaFatalException {
	public:
		ZiaException(const std::string & error = "") throw ();
		virtual ~ZiaException() throw ();

	};

	/**
	 * @brief Exception issu d'un module du server
	 *
	 */
	class ZiaModuleException : public ZiaException {
	public:
		ZiaModuleException(const std::string & error = "") throw ();
		virtual ~ZiaModuleException() throw ();

	};

	/**
	 *
	 *
	 */
	class ZiaServiceException : public ZiaException {
	public:
		ZiaServiceException(const std::string & error = "") throw ();
		virtual ~ZiaServiceException() throw ();

	};

}
