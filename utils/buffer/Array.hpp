/**
 *
 *
 *
 */

#pragma once
#define __ARRAY_HPP__

#include <cstring>
#include <sstream>
#include "Define.h"
#include "tools/Exception.hpp"

namespace utils {

	class OutOfBoundsException : public Exception {
	protected:
		int position;
		int max;

	public:
		OutOfBoundsException(int position, int max) throw ();
		virtual ~OutOfBoundsException() throw ();

		int getPosition() const throw ();
		int getMax() const throw ();

		virtual const char * what() throw ();

	};

	template <typename T>
	class Array {
	protected:
		T * table;
		int tableSize;
		int currentUsedSize;
		bool deleteAtDestroy;

	public:
		Array(bool deleteAtDestroy = true)
		: table(0), tableSize(0), currentUsedSize(0), deleteAtDestroy(deleteAtDestroy) {

		}

		Array(const T * data, int size, bool deleteAtDestroy = true)
		: table(NULL), deleteAtDestroy(deleteAtDestroy) {
			allocate(size);
			std::memcpy(reinterpret_cast<void *> (table), reinterpret_cast<const void *> (data), size);
			tableSize = size;
			currentUsedSize = size;
		}

		Array(T * data, int size, bool deleteAtDestroy = true)
		: table(data), tableSize(size), currentUsedSize(size), deleteAtDestroy(deleteAtDestroy) {

		}

		Array(int size, bool deleteAtDestroy = true)
		: table(0), deleteAtDestroy(deleteAtDestroy) {
			allocate(size);
		}

		~Array() {
			if (deleteAtDestroy) {
				delete [] table;
			}
		}

		T & operator [](int position) __throw __throw1(utils::OutOfBoundsException) {
			if (position >= tableSize || position < 0) {
				throw OutOfBoundsException(position, tableSize);
			}
			return table[position];
		}

		const T & operator [](int position) const __throw __throw1(utils::OutOfBoundsException) {
			if (position >= tableSize || position < 0) {
				throw OutOfBoundsException(position, tableSize);
			}
			return table[position];
		}

		Array<T> & operator =(const Array<T> & oth) {
			if (this != &oth) {
				delete [] table;
				tableSize = oth.size();
				currentUsedSize = oth.usedSize();
				table = new T[tableSize]();
				std::memcpy(table, oth.getData(), tableSize);
			}
			return *this;
		}

		Array<T> & operator +(const T & oth) {
			Array<T> converted(1);
			converted[0] = oth;

			return add(converted, 1);
		}

		Array<T> operator +(const Array<T> & oth) const {
			Array<T> newTable(oth.size() + size());

			std::memcpy(reinterpret_cast<void *> (newTable.getData()), reinterpret_cast<void *> (getData()), size());
			std::memcpy(reinterpret_cast<void *> (newTable.getAddress(size())), reinterpret_cast<void *> (oth.getData()), oth.size());
			newTable.setUsedSize(usedSize() + oth.usedSize());
			return newTable;
		}

		Array<T> & operator +=(const T & oth) {
			return operator+(oth);
		}

		Array<T> & operator +=(const Array<T> & oth) {
			return add(oth, oth.size());
		}

		Array<T> duplicate() const {
			Array<T> newTable(tableSize);
			std::memcpy(newTable->getData(), table, tableSize);
			return newTable;
		}

		inline void clear() {
			allocate(0);
		}

		void allocate(int size) {
			delete [] table;
			table = NULL;
			if (size > 0) {
				table = new T[size]();
				std::memset(table, 0, size * sizeof (T));
			}
			tableSize = size;
			currentUsedSize = 0;
		}

		Array<T> & add(const Array<char> & oth, int n) {
			T * newTable = new T[size() + n];

			std::memcpy(reinterpret_cast<void *> (newTable), reinterpret_cast<void *> (getData()), size());
			std::memcpy(reinterpret_cast<void *> (&newTable[size()]), reinterpret_cast<void *> (oth.getData()), n);

			delete [] table;
			table = newTable;
			tableSize += n;
			return *this;
		}

		void refactor(int startIndex, int endIndex) {
			if (startIndex < 0) {
				startIndex = 0;
			}
			if (endIndex > size()) {
				endIndex = size();
			}
			if (endIndex < startIndex) {
				endIndex = startIndex;
			}
			int newSize = endIndex - startIndex;
			T * newTable = NULL;
			if (newSize > 0) {
				newTable = new T[newSize]();
				std::memcpy(reinterpret_cast<void *> (newTable), reinterpret_cast<void *> (&(getData()[startIndex])), newSize);
			}

			delete [] table;
			table = newTable;
			tableSize = newSize;
			currentUsedSize -= startIndex;
		}

		T * getAddress(int position) const __throw __throw1(utils::OutOfBoundsException) {
			if (position >= tableSize || position < 0) {
				throw OutOfBoundsException(position, tableSize);
			}
			return &table[position];
		}

		inline int size() const {
			return tableSize;
		}

		inline int usedSize() const {
			return currentUsedSize;
		}

		inline T * getData() const {
			return table;
		}

		void setData(T * data, int size, bool deleteAtDestroy = true) {
			if (deleteAtDestroy && this->table) {
				delete this->table;
			}
			this->table = data;
			this->tableSize = size;
			this->currentUsedSize = size;
			this->deleteAtDestroy = deleteAtDestroy;
		}

		void setDeleteAtDestroy(bool deleteAtDestroy) {
			this->deleteAtDestroy = deleteAtDestroy;
		}

		void setUsedSize(int usedSize) __throw __throw1(utils::OutOfBoundsException) {
			if (usedSize > tableSize || usedSize < 0) {
				throw OutOfBoundsException(usedSize, tableSize);
			}
			this->currentUsedSize = usedSize;
		}

	};

	typedef Array<char> CharArray;
	typedef Array<int> IntArray;

}
