/**
 *
 *
 *
 */

#pragma once
#define	__SERIALIZABLE_H__

#include "Define.h"
#include "tools/Exception.hpp"
#include "buffer/Array.hpp"

namespace utils {

	interface Serializable {
	public:
		Serializable() {}
		virtual ~Serializable() {}

		virtual int serialize(CharArray & buffer, int offset = 0) const = 0;
		virtual int unserialize(CharArray & buffer, int offset = 0) = 0;
		virtual int getSerializeSize() const = 0;

	};

}

inline std::ostream & operator <<(std::ostream & os, utils::Serializable & serializable) {
	utils::CharArray array(serializable.getSerializeSize() + 1);
	serializable.serialize(array);
	array[array.size() - 1] = 0;
	os << array.getData();
	return os;
}

inline std::istream & operator >>(std::istream & is, utils::Serializable & serializable) {
	throw utils::Exception("Try to unserialise serializable object with stream");
}
