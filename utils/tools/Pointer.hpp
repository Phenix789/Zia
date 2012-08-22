
#pragma once
#define	__POINTER_HPP__

#include <string>
#include "Exception.hpp"

namespace utils {

	EXCEPTION_DECLARATION(PointerNullException, Exception);
	EXCEPTION_IMPLEMENTATION_ERROR(PointerNullException, Exception)

	template<typename T>
	class Pointer {
	private:
		T * data;
		int *count;

	protected:

		inline void clean() {
			if (data) {
				(*count)--;
				if (*count == 0) {
					delete data;
					delete count;
				}
			}
		}

		inline void set(T * data, int * count) {
			this->data = data;
			this->count = count;
		}

	public:

		inline Pointer() {
			set(NULL, new int)
				*count = 0;
		}

		inline Pointer(T * data) {
			set(data, new int);
			*count = 1;
		}

		inline Pointer(const Pointer<T> & src) {
			clean();
			set(src.data, src.count);
			(*count)++;
		}

		inline virtual ~Pointer() {
			clean();
		}

		inline Pointer<T> & operator =(const Pointer<T> & src) {
			clean();
			set(src.data, src.count);
			(*count)++;
			return *this;
		}

		inline Pointer<T> & operator =(T * data) {
			clean();
			set(data, new int);
			*count = 1;
			return *this;
		}

		inline T * operator ->() const {
			if (isNull()) {
				throw PointerNullException();
			}
			return data;
		}

		inline T & operator *() const {
			if (isNull()) {
				throw PointerNullException();
			}
			return *data;
		}

		inline operator T *() const {
			return data;
		}

		inline bool operator ==(const Pointer<T> & pointer) const {
			return data == pointer.data;
		}

		inline bool operator !=(const Pointer<T> & pointer) const {
			return data != pointer.data;
		}

		inline T * getData() const {
			return data;
		}

		inline bool isNull() const {
			return !getData();
		}

	};

}
