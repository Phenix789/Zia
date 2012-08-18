
#pragma once
#define	__NONCOPYABLE_HPP__

#include "Define.h"

namespace utils {

	abstract class NonCopyable {
	private:
		NonCopyable(const NonCopyable & other);
		NonCopyable & operator =(const NonCopyable & other);

	protected:
		inline NonCopyable() {}
		inline virtual ~NonCopyable() {}

	};

}

#endif
