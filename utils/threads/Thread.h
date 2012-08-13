/**
 *
 *
 *
 */

#pragma once
#define	__THREAD_H__

#include <string>
#include "Define.h"
#include "IRunnable.h"
#include "tools/NonCopyable.hpp"

#if defined WINDOWS
	#include <Windows.h>
	typedef HANDLE basic_thread;
	typedef LPTHREAD_START_ROUTINE basic_start;
#elif defined LINUX
	#include <pthread.h>
	typedef pthread_t basic_thread;
	typedef void *(*basic_start)(void *);
#endif

namespace utils {

	class ThreadException : public Exception {
	public:
		ThreadException(const std::string & error = "");
		virtual ~ThreadException();

	};

	class BasicThreadException : public Exception {
	public:
		BasicThreadException(const std::string & error = "");
		virtual ~BasicThreadException();

	};

	class Thread : private NonCopyable {
	private:
		basic_thread thread;
		bool running;

	protected:
		IRunnable * runnable;

	protected:
		virtual void run();

	public:
		Thread(IRunnable * runnable = NULL);
		virtual ~Thread();

		void start();
		void stop();
		void join();
		bool wait(unsigned int msec);
		static void sleep(unsigned int msec = 1);

		bool isRunning() const;

		friend void * __thread_start(void * data);

	};

	void * __thread_start(void * data);

}

#endif
