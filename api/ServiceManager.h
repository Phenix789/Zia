/**
 *
 *
 *
 */

#pragma once
#define __SERVICEMANAGER_H__

#include "Define.h"
#include "Exception.h"
#include "Service.h"

namespace ZIA_API_NAMESPACE {

        class ZiaUnknowServiceException : public ZiaServiceException {
        public:
                ZiaUnknowServiceException(const std::string & serviceName) throw ();
                virtual ~ZiaUnknowServiceException() throw ();

        };

        class ZiaBadCastServiceException : public ZiaServiceException {
        public:
                ZiaBadCastServiceException(const std::string & serviceName) throw ();
                virtual ~ZiaBadCastServiceException() throw ();

        };

        class ServiceManager : public Service {
        public:
                ServiceManager();
                virtual ~ServiceManager();

                bool hasService(const std::string & serviceName) const;
                ServiceManager & addService(Service * __delegate service);
                ServiceManager & removeService(std::string & serviceName) __throw __throw1(ZiaUnknowServiceException);

                template<typename T>
                bool hasService(const std::string & serviceName) const;

                template<>
                bool hasService<Service>(const std::string & serviceName) const;

                template<typename T>
                T & getService(const std::string & serviceName) __throw __throw2(ZiaUnknowServiceException, ZiaBadCastServiceException);

                template<>
                Service & getService<Service>(const std::string & serviceName) __throw __throw2(ZiaUnknowServiceException, ZiaBadCastServiceException);

                void initialise() __throw __throw1(ZiaServiceException);

        };

}
