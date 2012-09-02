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

#define ZIA_SERVICE_SERVICE_MANAGER "service_manager"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	EXCEPTION_DECLARATION(ZiaUnknowServiceException, ZiaServiceException);
	EXCEPTION_DECLARATION(ZiaBadCastServiceException, ZiaServiceException);

	class ServiceManager : public Service {
	protected:
		typedef std::map<std::string, Service *> ServiceMap;
		ServiceMap services;
		const std::string name;
		bool init;

	public:
		ServiceManager();
		virtual ~ServiceManager();

		ServiceManager & addService(Service * __delegate service);
		ServiceManager & removeService(std::string & serviceName) __throw __throw1(ZAN::ZiaUnknowServiceException);

		virtual const std::string & getName() const;
		virtual void initialize(ZiaCore * core) __throw __throw1(ZAN::ZiaServiceException);

		template<typename T>
		bool hasService(const std::string & serviceName) const;

		template<typename T>
		T * getService(const std::string & serviceName) __throw __throw2(ZAN::ZiaUnknowServiceException, ZAN::ZiaBadCastServiceException);

	};

}

/*Template implementation*/

template<typename T>
bool ZAN::ServiceManager::hasService(const std::string & serviceName) const {
	ServiceMap::iterator it = services.find(serviceName);
	if (it != services.end()) {
		T * t = dynamic_cast<T *>(it->second);
		if (t) {
			return true;
		}
		throw ZiaBadCastServiceException(serviceName);
	}
	throw ZiaUnknowServiceException(serviceName);
}

template<typename T>
T * ZAN::ServiceManager::getService(const std::string & serviceName) {
	ServiceMap::iterator it = services.find(serviceName);
	if (it != services.end()) {
		T * t = dynamic_cast<T *>(it->second);
		if (t) {
			return t;
		}
		throw ZiaBadCastServiceException(serviceName);
	}
	throw ZiaUnknowServiceException(serviceName);
}
