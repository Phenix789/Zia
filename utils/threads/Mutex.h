
#ifndef __MUTEX_H__
#define	__MUTEX_H__

#include <string>
#include "Define.h"
#include "tools/NonCopyable.hpp"
#include "tools/Exception.h"

#if defined WINDOWS
	#include <Windows.h>
	typedef HANDLE basic_mutex;
#elif defined LINUX
	#include <pthread.h>
	typedef pthread_mutex_t basic_mutex;
#endif

namespace utils {

	class MutexException : public Exception {
	public:
		MutexException(const std::string & error = "");
		virtual ~MutexException();

	};

	class Mutex : private NonCopyable {
	private:
		basic_mutex mutex;
		bool locked;

	public:
		Mutex();
		virtual ~Mutex();

		bool isLock() const;

		void lock();
		void unlock();
		bool trylock();

	};

}

#endif
