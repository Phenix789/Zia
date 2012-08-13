/**
 *
 *
 *
 */

#include "Thread.h"

using namespace utils;

void * utils::__thread_start(void * data) {
	Thread * thread = static_cast<Thread *> (data);
	thread->running = true;
	thread->run();
	thread->running = false;
	return NULL;
}

Thread::Thread(IRunnable * runnable)
: running(false), runnable(runnable) {

}

Thread::~Thread() {
	try {
		stop();
	}
	catch (const ThreadException & e) {
		(void) e;
	}
}

void Thread::run() {
	if (runnable) {
		runnable->run();
	}
	else {
		throw ThreadException("Try to run thread without runnable.");
	}
}

bool Thread::isRunning() const {
	return running;
}

#if defined WINDOWS

void Thread::start() {
	if (!running) {
		thread = CreateThread(NULL, 0, reinterpret_cast<basic_start> (&__thread_start), this, 0, NULL);
		if (!thread) {
			throw ThreadException();
		}
	}
	else {
		throw ThreadException();
	}
}

void Thread::stop() {
	if (running) {
		if (thread == GetCurrentThread()) {
			running = false;
			ExitThread(0);
		}
		else if (!TerminateThread(thread, 0)) {
			throw ThreadException();
		}
		running = false;
	}
	else {
		throw ThreadException();
	}
}

void Thread::sleep(unsigned int msec) {
	Sleep(msec);
}

#elif defined LINUX

void Thread::start() {
	if (!running) {
		if (pthread_create(&thread, NULL, __thread_start, this) != 0) {
			throw BasicThreadException("Error to create thread.");
		}
	}
	else {
		throw ThreadException("Thread already running.");
	}
}

void Thread::stop() {
	if (running) {
		if (pthread_equal(pthread_self(), thread)) {
			running = false;
			pthread_exit(NULL);
		}
		else if (pthread_cancel(thread) != 0) {
			throw ThreadException();
		}
		pthread_detach(this->thread);
		running = false;
	}
	else {
		throw ThreadException("Thread is not running.");
	}
}

void Thread::join() {
	if (pthread_equal(pthread_self(), thread)) {
		throw ThreadException("Try to join itself.");
	}
	pthread_join(thread, NULL);
}

bool Thread::wait(unsigned int msec) {
	if (pthread_equal(pthread_self(), thread)) {
		throw ThreadException("Try to wait itself.");
	}
	int usec = msec * 100;
	int i = 0;
	while (i < 10) {
		if (pthread_tryjoin_np(thread, NULL) == 0) {
			return true;
		}
		usleep(usec);
		i++;
	}
	return false;
}

void Thread::sleep(unsigned int msec) {
	usleep(msec * 1000);
}

#endif
