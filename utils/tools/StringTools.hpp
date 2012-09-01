/**
 *
 *
 *
 */

#pragma once
#define	__STRINGTOOLS_HPP__

#include <vector>
#include <sstream>
#include <algorithm>
#include "Define.h"

namespace utils {

	std::vector<std::string> & split(const std::string & str, char delim, std::vector<std::string> & strings);
	std::vector<std::string> split(const std::string & str, char delim);
	std::vector<std::string> & split(const std::string & str, char * delim, std::vector<std::string> & strings);
	std::vector<std::string> split(const std::string & str, char * delim);

	int to_upper(int c);
	void string_to_upper(std::string & str);

	template <typename T>
	std::string to_string(T value) {
		std::stringstream ss;
		ss << value;
		return ss.str();
	}

	template <typename T>
	T string_convert(const std::string & number) {
		std::stringstream ss(number);
		T n;
		ss >> n;
		return n;
	}

}
