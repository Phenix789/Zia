/**
 *
 *
 *
 */

#pragma once
#define __SERVICEMANAGER_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION(ZiaUnknowServiceException, ZiaServiceException);
	EXCEPTION_DECLARATION(ZiaBadCastServiceException, ZiaServiceException);

	class ServiceManager : public Service {
	protected:
		typedef std::map<std::string, Service *> ServiceMap;
		ServiceMap services;

	public:
		ServiceManager(ZiaCore & core);
		virtual ~ServiceManager();

		ServiceManager & addService(Service * __delegate service);
		ServiceManager & removeService(std::string & serviceName) __throw __throw1(ZAN::ZiaUnknowServiceException);

		virtual const std::string & getName() const;
		virtual void initialise() __throw __throw1(ZAN::ZiaServiceException);

		template<typename T>
		bool hasService(const std::string & serviceName) const;

		template<typename T>
		T & getService(const std::string & serviceName) __throw __throw2(ZAN::ZiaUnknowServiceException, ZAN::ZiaBadCastServiceException);

	};

}
