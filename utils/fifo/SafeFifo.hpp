/**
 *
 *
 *
 */

#pragma once
#define	__SAFEFIFO_HPP__

#include "Fifo.hpp"
#include "threads/Mutex.h"
#include "threads/Locker.h"

namespace utils {

	template<typename T>
	class SafeFifo : public Fifo<T> {
	protected:
		Mutex mutex;

	public:

		SafeFifo() : Fifo<T>() {}

		virtual ~SafeFifo() {}

		virtual void put(typename Fifo<T>::Type & t) {
			Locker(&this->mutex);
			Fifo<T>::put(t);
		}

		virtual typename Fifo<T>::Type & get() {
			Locker(&this->mutex);
			return Fifo<T>::get();
		}

	};
}
