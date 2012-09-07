/**
 *
 *
 *
 */

#pragma once
#define	__BUFFER_H__

#include <cstring>
#include <iostream>
#include "Exception.h"

namespace utils {

	EXCEPTION_DECLARATION_INLINE_ERROR(OutOfRangeException, Exception);

	class Buffer {
	protected:
		const static unsigned int BLOC_SIZE = 1024;
		char * _data;
		unsigned int _size;
		unsigned int _used;
		bool _toDelete;

	public:
		inline Buffer()
		: _data(NULL), _size(0), _used(0), _toDelete(false) {

		}

		explicit inline Buffer(unsigned int size)
		: _data(NULL), _size(0), _used(0), _toDelete(false) {
			alloc(size);
		}

		inline Buffer(char * str)
		: _data(NULL), _size(0), _used(0), _toDelete(false) {
			add(str, std::strlen(str));
		}

		inline Buffer(char * data, unsigned int size, unsigned int used = 0, bool toDelete = true, bool copy = false)
		: _data(NULL), _size(0), _used(0), _toDelete(false) {
			if (copy) {
				alloc(size);
				add(data, used);
			}
			else {
				_data = data;
				_size = size;
				_used = used;
				_toDelete = toDelete;
			}
		}

		inline Buffer(const Buffer & copy) {
			alloc(copy._size);
			add(copy._data, copy._used);
		}

		inline virtual ~Buffer() {
			if (_toDelete && _data) {
				delete[] _data;
			}
		}

		inline unsigned int preAlloc(unsigned int size) {
			realloc(_size + size);
			return _size;
		}

		inline void add(const char * buffer, unsigned int size) {
			if (size) {
				if (_size - _used < size || !_data) {
					realloc(_used + size);
				}
				std::memcpy(&_data[_used], buffer, size);
				_used += size;
			}
		}

		inline void add(const Buffer & buffer) {
			add(buffer._data, buffer._used);
		}

		inline void add(Buffer * buffer) {
			std::cout << "Pointer : " << buffer << std::endl;
			add(buffer->_data, buffer->_used);
		}

		inline unsigned int getUsed() const {
			return _used;
		}

		inline unsigned int getSize() const {
			return _used;
		}

		inline unsigned int getMaxSize() const {
			return _size;
		}

		inline unsigned int getRemaining() const {
			return _size - _used;
		}

		inline const char * getData() const {
			return _data;
		}

		inline char * getData() {
			return _data;
		}

		inline char * getEnd() {
			return &_data[_used];
		}

		inline char & getAt(unsigned int index) {
			if (index > _used || !_data) {
				throw OutOfRangeException();
			}
			return _data[index];
		}

		inline char * getAddress(unsigned int index) const {
			if (index > _size || !_data) {
				throw OutOfRangeException();
			}
			return &_data[index];
		}

		inline void setData(char * data, unsigned int size, unsigned int used = 0, bool toDelete = true, bool copy = false) {
			clear();
			if (copy) {
				add(data, used);
			}
			else {
				if (_toDelete && _data) {
					delete[] _data;
				}
				_data = data;
				_size = size;
				_used = used;
				_toDelete = toDelete;
			}
		}

		inline void addUsed(unsigned int used) {
			if (used + _used > _size) {
				throw OutOfRangeException();
			}
			_used += used;
		}

		inline void setUsed(unsigned int used) {
			if (used > _size) {
				throw OutOfRangeException();
			}
			_used = used;
		}

		inline void setToDelete(bool toDelete) {
			_toDelete = toDelete;
		}

		inline void clear() {
			_used = 0;
		}

		inline const char & operator [](unsigned int index) const {
			if (index >= _used || !_data) {
				throw OutOfRangeException();
			}
			return _data[index];
		}

		inline char & operator [](unsigned int index) {
			if (index >= _used || !_data) {
				throw OutOfRangeException();
			}
			return _data[index];
		}

		inline Buffer & operator +=(const char c) {
			add(&c, 1);
			return *this;
		}

		inline Buffer & operator +=(const char * str) {
			add(str, std::strlen(str));
			return *this;
		}

		inline Buffer & operator +=(const Buffer & buffer) {
			add(buffer._data, buffer._used);
			return *this;
		}

		inline Buffer & operator =(const char * str) {
			_used = 0;
			add(str, std::strlen(str));
			return *this;
		}

		inline Buffer & operator =(const Buffer & buffer) {
			_used = 0;
			add(buffer._data, buffer._used);
			return *this;
		}

		void dump() const {
			std::cout << "Size : " << _used << "/" << _size << std::endl;
			std::cout << "Content : '''";
			std::cout.write(_data, _used) << "'''" << std::endl;
		}

	protected:
		void alloc(unsigned int size) {
			if (size == 0) {
				_data = 0;
				_used = 0;
				_size = 0;
				_toDelete = false;
			}
			else {
				unsigned int size_alloc = ((size / BLOC_SIZE) + 1) * BLOC_SIZE;
				_data = new char[size_alloc];
				_size = size_alloc;
				_used = 0;
				_toDelete = true;
			}
		}

		void realloc(unsigned int size) {
			if (size > _size) {
				char * data = _data;
				unsigned int used = _used;
				bool toDelete = _toDelete;
				alloc(size);
				add(data, used);
				if (toDelete) {
					delete[] data;
				}
			}
		}

	};

}
