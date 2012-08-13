/**
 *
 *
 *
 */

#pragma once
#define	__LOCKER_H__

#include "Mutex.h"
#include "tools/NonCopyable.hpp"

namespace utils {

	class Locker : private NonCopyable {
	protected:
		Mutex * mutex;

	public:
		Locker(Mutex * mutex);
		virtual ~Locker();

		void unlock();
		void relock();

		Mutex * getMutex() const;

	};

}

#endif
