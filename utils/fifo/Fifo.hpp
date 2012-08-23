/**
 *
 *
 *
 */

#pragma once
#define	__FIFO_HPP__

#include <queue>

namespace utils {

	template<typename T>
	class Fifo : private std::queue<T> {
	public:
		typedef T Type;

		Fifo() : std::queue<Type>() {}
		virtual ~Fifo() {}

		virtual void put(Type & t) {
			push(t);
		}

		virtual Type & get() {
			Type & t = this->front();
			this->pop();
			return t;
		}

		int size() {
			return std::queue<Type>::size();
		}

		bool empty() {
			return std::queue<Type>::empty();
		}

	};

}
