/**
 *
 *
 *
 */

#include "Mutex.h"

using namespace utils;

#if defined WINDOWS

Mutex::Mutex() {
	mutex = CreateMutex(NULL, false, NULL);
	if (!mutex) {
		throw MutexException("Error to create mutex");
	}
}

Mutex::~Mutex() {
	CloseHandle(mutex);
}

bool Mutex::isLock() const {
	return locked;
}

void Mutex::lock() {
	if (WaitForSingleObject(mutex, INFINITE) != WAIT_OBJECT_0) {
		throw MutexException("Error to lock mutex");
	}
	locked = true;
}

void Mutex::unlock() {
	if (!ReleaseMutex(mutex)) {
		throw MutexException("Error to unlock mutex");
	}
	locked = false;
}

bool Mutex::trylock() {
	DWORD ret = WaitForSingleObject(mutex, 1);
	if (ret == WAIT_OBJECT_0) {
		locked = true;
		return true;
	}
	else if (ret == WAIT_TIMEOUT) {
		return false;
	}
	else {
		throw MutexException("Error to trylock mutex");
	}
}

#elif defined LINUX

Mutex::Mutex() {
	pthread_mutex_init(&mutex, NULL);
	locked = false;
}

Mutex::~Mutex() {
	pthread_mutex_destroy(&mutex);
}

bool Mutex::isLock() const {
	return locked;
}

void Mutex::lock() {
	pthread_mutex_lock(&mutex);
	locked = true;
}

void Mutex::unlock() {
	pthread_mutex_unlock(&mutex);
	locked = false;
}

bool Mutex::trylock() {
	if (pthread_mutex_trylock(&mutex) == 0) {
		locked = true;
		return true;
	}
	return false;
}

#endif
