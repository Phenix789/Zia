/**
 *
 *
 *
 */

#include "Locker.h"

using namespace utils;

Locker::Locker(Mutex * mutex)
: mutex(mutex) {
	if (!mutex) {
		throw MutexException("Locker need a valide mutex pointer");
	}
	mutex->lock();
}

Locker::~Locker() {
	mutex->unlock();
}

void Locker::unlock() {
	if (mutex->isLock()) {
		mutex->unlock();
	}
}

void Locker::relock() {
	if (!mutex->isLock()) {
		mutex->lock();
	}
}

Mutex * Locker::getMutex() const {
	return mutex;
}
