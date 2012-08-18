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
