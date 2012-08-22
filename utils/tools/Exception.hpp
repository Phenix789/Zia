/**
 *
 *
 *
 */

#pragma once
#define	__EXCEPTION_H__

#include <string>

namespace utils {

	class Exception : public std::exception {
	private:
		std::string error;

	public:
		inline Exception(const std::string & error = "") throw () : error(error) {}
		inline virtual ~Exception() throw () {}

		inline virtual const char * what() const throw () { return error.data(); }
		inline virtual const std::string & getError() const throw () { return error; }

	protected:
		inline std::string & getError() throw () { return error; }
		inline void setError(const std::string & error) throw () { this->error = error; }

	};

}

#define EXCEPTION_DECLARATION_INLINE(name, extend, message)			\
class name : public extend {							\
public:										\
	inline name(const std::string & error = "") throw ()			\
		: extend(message) {}						\
	inline virtual ~name() throw () {}					\
}										\

#define EXCEPTION_DECLARATION_INLINE_ERROR(name, extend) EXCEPTION_DECLARATION_INLINE(name, extend, error)

#define EXCEPTION_DECLARATION(name, extend)					\
class name : public extend {							\
public:										\
	name(const std::string & error = "") throw ();				\
	virtual ~name() throw ();						\
}										\

#define EXCEPTION_IMPLEMENTATION(name, extend, message)				\
name::name(const std::string & error)  throw ()					\
: extend(message) {								\
										\
}										\
										\
name::~name() throw () {							\
										\
}										\

#define EXCEPTION_IMPLEMENTATION_ERROR(name, extend) EXCEPTION_IMPLEMENTATION(name, extend, error)
