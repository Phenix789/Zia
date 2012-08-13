/**
 *
 *
 *
 */

#pragma once
#define __RUNNABLE_H__

namespace utils {

	class IRunnable {
	public:
		IRunnable() {}
		virtual ~IRunnable() {}

		virtual void run() = 0;

	};

}

#endif
