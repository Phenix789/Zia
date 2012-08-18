
#pragma once
#define	__SINGLETON_H__

#include <cstdlib>
#include "threads/Mutex.h"

namespace utils {

	template<typename T>
	void __destroy_singleton();

	template<typename T>
	abstract class Singleton {
	private:
		//static Mutex mutex;
		static T * instance;

	protected:

		Singleton() {

		}

		virtual ~Singleton() {

		}

	public:

		static T * getInstance() {
			if (instance == 0) {
				//Locker(&Singleton::mutex);
				if (instance == 0) {
					instance = new T();
					atexit(&__destroy_singleton<T>);
				}
			}
			return instance;
		}

		static void destroy() {
			if (instance) {
				//Locker(&Singleton::mutex);
				if (instance) {
					delete instance;
					instance = 0;
				}
			}
		}

	};

	template<typename T>
	T * Singleton<T>::instance = 0;

	template<typename T>
	void __destroy_singleton() {
		Singleton<T>::destroy();
	}

}

#endif
