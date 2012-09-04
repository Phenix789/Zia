/**
 *
 *
 *
 */

#pragma once
#define	__BUFFER_H__

#include "Define.h"

namespace utils {

	class Buffer {
	public:
		Buffer() {}
		virtual ~Buffer() {}

		virtual const char * getData() const = 0;
		virtual char * getData() = 0;
		virtual char * getAddress(unsigned int offset) = 0;

		virtual void setData(char *data, int size, bool toDelete = true) = 0;

		virtual unsigned int getSize() const = 0;

	};

}
