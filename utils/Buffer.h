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

		virtual unsigned int getSize() const = 0;

	};

}
