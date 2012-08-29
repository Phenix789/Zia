/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIACORE_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "Service.h"
#include "ServiceManager.h"
#include "Module.h"
#include "Chain.h"
#include "Loader.h"
#include "Listener.h"
#include "Receiver.h"

#define ZIA_SERVICE_ZIA_CORE "zia_core"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaCoreException, ZiaFatalException);

        interface ZiaCore : public Service, public network::Listener {
        public:
                ZiaCore() : Service(*this) {}
                virtual ~ZiaCore() {}

		virtual const std::string & getName() const = 0;

		virtual void initialise() = 0;
		virtual void run() = 0;

		virtual void listen(int port) __throw;
		virtual network::Receiver * onAccept(network::Communicator * com) = 0;
		virtual void onReceive(network::Receiver & receiver, Buffer & buffer) = 0;

		virtual Chain & getChain() = 0;
		virtual ServiceManager & getServiceManager() = 0;

        };

}
