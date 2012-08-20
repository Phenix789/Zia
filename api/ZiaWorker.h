/**
 *
 *
 *
 */

#pragma once
#define	__ZIAWORKER_H__

#include "threads/Thread.h"
#include "threads/Mutex.h"

#include "ZiaDefine.h"
#include "ZiaObject.h"
#include "ZiaException.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	class ZiaWorker : public ZiaObject, public utils::Thread {
	protected:
		utils::Mutex mutex;
		Request * request;
		Response * response;

	public:
		ZiaWorker(ZiaCore & core);
		virtual ~ZiaWorker();

		bool isBusy() const;
		void execute(Request & request, Response & response);

		Request & getRequest();
		Response & getResponse();

	protected:
		virtual void run();

	};

}
