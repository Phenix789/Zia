/**
 *
 *
 *
 */

#pragma once
#define __TABLE_H__

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
		OutOfBoundsException(int position, int max);
		virtual ~OutOfBoundsException();

		int getPosition() const;
		int getMax() const;

		virtual const char * what();

	};

	template <typename T>
	class Array {
	protected:
		T * table;
		int tableSize;
		int currentUsedSize;
		bool deleteAtDestroy;

	public:
		Array(bool deleteAtDestroy = true);
		Array(const T * data, int size, bool deleteAtDestroy = true);
		Array(T * data, int size, bool deleteAtDestroy = true);
		Array(int size, bool deleteAtDestroy = true);
		~Array();

		T & operator [](int position) __throw __throw1(utils::OutOfBoundsException);
		const T & operator [](int position) const __throw __throw1(utils::OutOfBoundsException);
		Array<T> & operator =(const Array<T> & oth);
		Array<T> & operator +(const T & oth);
		Array<T> operator +(const Array<T> & oth) const;
		Array<T> & operator +=(const T & oth);
		Array<T> & operator +=(const Array<T> & oth);

		Array<T> duplicate() const;
		void clear();
		void allocate(int size);
		Array<T> & add(const Array<char> & oth, int n);
		void refactor(int startIndex, int endIndex);
		T * getAddress(int position) const __throw __throw1(utils::OutOfBoundsException);
		int size() const;
		int usedSize() const;
		T * getData() const;
		void setData(T * data, int size);
		void setDeleteAtDestroy(bool deleteAtDestroy);
		void setUsedSize(int usedSize) __throw __throw1(utils::OutOfBoundsException);

	};

	typedef Array<char> CharArray;
	typedef Array<int> IntArray;

}

/*Template implementation*/

utils::OutOfBoundsException::OutOfBoundsException(int position, int max)
: position(position), max(max) {

}

utils::OutOfBoundsException::~OutOfBoundsException() {

}

int utils::OutOfBoundsException::getPosition() const {
	return position;
}

int utils::OutOfBoundsException::getMax() const {
	return max;
}

const char * utils::OutOfBoundsException::what() {
	std::stringstream ss;
	ss << "Out of bounds : " << position << " (" << max << ")";
	return ss.str().data();
}

template<typename T>
utils::Array::Array(bool deleteAtDestroy = true)
: table(0), tableSize(0), currentUsedSize(0), deleteAtDestroy(deleteAtDestroy) {

}

template<typename T>
utils::Array::Array(const T * data, int size, bool deleteAtDestroy = true)
: table(NULL), deleteAtDestroy(deleteAtDestroy) {
	allocate(size);
	std::memcpy(reinterpret_cast<void *> (table), reinterpret_cast<const void *> (data), size);
	tableSize = size;
	currentUsedSize = size;
}

template<typename T>
utils::Array::Array(T * data, int size, bool deleteAtDestroy = true)
: table(data), tableSize(size), currentUsedSize(size), deleteAtDestroy(deleteAtDestroy) {

}

template<typename T>
utils::Array::Array(int size, bool deleteAtDestroy = true)
: table(0), deleteAtDestroy(deleteAtDestroy) {
	allocate(size);
}

template<typename T>
utils::Array::~Array() {
	if (deleteAtDestroy) {
		delete [] table;
	}
}

template<typename T>
T & utils::Array::operator [](int position) {
	if (position >= tableSize || position < 0) {
		throw OutOfBoundsException(position, tableSize);
	}
	return table[position];
}

template<typename T>
const T & utils::Array::operator [](int position) const {
	if (position >= tableSize || position < 0) {
		throw OutOfBoundsException(position, tableSize);
	}
	return table[position];
}

template<typename T>
utils::Array<T> & utils::Array::operator =(const Array<T> & oth) {
	if (this != &oth) {
		delete [] table;
		tableSize = oth.size();
		currentUsedSize = oth.usedSize();
		table = new T[tableSize]();
		std::memcpy(table, oth.getData(), tableSize);
	}
	return *this;
}

template<typename T>
utils::Array<T> & utils::Array::operator +(const T & oth) {
	Array<T> converted(1);
	converted[0] = oth;

	return add(converted, 1);
}

template<typename T>
utils::Array<T> utils::Array::operator +(const Array<T> & oth) const {
	Array<T> newTable(oth.size() + size());

	std::memcpy(reinterpret_cast<void *> (newTable.getData()), reinterpret_cast<void *> (getData()), size());
	std::memcpy(reinterpret_cast<void *> (newTable.getAddress(size())), reinterpret_cast<void *> (oth.getData()), oth.size());
	newTable.setUsedSize(usedSize() + oth.usedSize());
	return newTable;
}

template<typename T>
utils::Array<T> & utils::Array::operator +=(const T & oth) {
	return operator+(oth);
}

template<typename T>
utils::Array<T> & utils::Array::operator +=(const Array<T> & oth) {
	return add(oth, oth.size());
}

template<typename T>
utils::Array<T> utils::Array::duplicate() const {
	Array<T> newTable(tableSize);
	std::memcpy(newTable->getData(), table, tableSize);
	return newTable;
}

template<typename T>
void utils::Array::clear() {
	allocate(0);
}

template<typename T>
void utils::Array::allocate(int size) {
	delete [] table;
	table = NULL;
	if (size > 0) {
		table = new T[size]();
		std::memset(table, 0, size * sizeof (T));
	}
	tableSize = size;
	currentUsedSize = 0;
}

template<typename T>
utils::Array<T> & utils::Array::add(const Array<char> & oth, int n) {
	T * newTable = new T[size() + n];

	std::memcpy(reinterpret_cast<void *> (newTable), reinterpret_cast<void *> (getData()), size());
	std::memcpy(reinterpret_cast<void *> (&newTable[size()]), reinterpret_cast<void *> (oth.getData()), n);

	delete [] table;
	table = newTable;
	tableSize += n;
	return *this;
}

template<typename T>
void utils::Array::refactor(int startIndex, int endIndex) {
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

template<typename T>
T * utils::Array::getAddress(int position) const {
	if (position >= tableSize || position < 0) {
		throw OutOfBoundsException(position, tableSize);
	}
	return &table[position];
}

template<typename T>
int utils::Array::size() const {
	return tableSize;
}

template<typename T>
int utils::Array::usedSize() const {
	return currentUsedSize;
}

template<typename T>
T * utils::Array::getData() const {
	return table;
}

template<typename T>
void utils::Array::setData(T * data, int size) {
	this->table = data;
	this->tableSize = size;
	this->currentUsedSize = size;
}

template<typename T>
void utils::Array::setDeleteAtDestroy(bool deleteAtDestroy) {
	this->deleteAtDestroy = deleteAtDestroy;
}

template<typename T>
void utils::Array::setUsedSize(int usedSize) {
	if (usedSize > tableSize || usedSize < 0) {
		throw OutOfBoundsException(usedSize, tableSize);
	}
	this->currentUsedSize = usedSize;
}
