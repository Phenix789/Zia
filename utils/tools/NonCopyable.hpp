
#pragma once
#define	__NONCOPYABLE_HPP__

namespace utils {

	class NonCopyable {
	private:
		NonCopyable(const NonCopyable & other);
		NonCopyable & operator =(const NonCopyable & other);

	protected:
		inline NonCopyable() {}
		inline virtual ~NonCopyable() {}

	};

}

#endif
