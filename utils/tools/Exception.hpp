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
		inline Exception(const std::string & error = "") : error(error) {}
		inline virtual ~Exception() {}

		inline virtual const char * what() const { return error.data(); }
		inline virtual const std::string & getError() const { return error; }

	protected:
		inline std::string & getError() { return error; }
		inline void setError(const std::string & error) { this->error = error; }

	};

}

#endif
