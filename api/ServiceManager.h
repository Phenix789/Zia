/**
 *
 *
 *
 */

#pragma once
#define __SERVICEMANAGER_H__

#include "ZiaDefine.h"
#include "Exception.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

	ZIA_EXCEPTION_DECLARATION(ZiaUnknowServiceException, ZiaServiceException);
	ZIA_EXCEPTION_DECLARATION(ZiaBadCastServiceException, ZiaServiceException);

        class ServiceManager : public Service {
        public:
                ServiceManager(ZiaCore & core);
                virtual ~ServiceManager();

                bool hasService(const std::string & serviceName) const;
                ServiceManager & addService(Service * __delegate service);
                ServiceManager & removeService(std::string & serviceName) __throw __throw1(ZAN::ZiaUnknowServiceException);

                template<typename T>
                bool hasService(const std::string & serviceName) const;

                template<>
                bool hasService<Service>(const std::string & serviceName) const;

                template<typename T>
                T & getService(const std::string & serviceName) __throw __throw2(ZAN::ZiaUnknowServiceException, ZAN::ZiaBadCastServiceException);

                template<>
                Service & getService<Service>(const std::string & serviceName) __throw __throw2(ZAN::ZiaUnknowServiceException, ZAN::ZiaBadCastServiceException);

                void initialise() __throw __throw1(ZAN::ZiaServiceException);

        };

}
