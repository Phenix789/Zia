/**
 *
 *
 *
 */

#pragma once
#define __RUNNABLE_H__

#include "Define.h"

namespace utils {

	interface IRunnable {
	public:
		IRunnable() {}
		virtual ~IRunnable() {}

		virtual void run() = 0;

	};

}

#endif
