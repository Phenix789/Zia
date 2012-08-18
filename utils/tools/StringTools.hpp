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

	inline std::vector<std::string> & split(const std::string & str, char delim, std::vector<std::string> & strings);
	inline std::vector<std::string> split(const std::string & str, char delim);

	inline int to_upper(int c);
	inline void string_to_upper(std::string & str);

	template <typename T>
	inline std::string to_string(T value);

	template <typename T>
	inline T string_convert(const std::string & number);

}

/*Template & Inline implementation*/

std::vector<std::string> & utils::split(const std::string & str, char delim, std::vector<std::string> & strings) {
	std::stringstream ss(str);
	std::string item;
	while (std::getline(ss, item, delim)) {
		strings.push_back(item);
	}
	return strings;
}

std::vector<std::string> utils::split(const std::string & str, char delim) {
	std::vector<std::string> elems;
	return split(str, delim, elems);
}

int utils::to_upper(int c) {
#if defined WINDOWS
	return std::toupper(c);
#elif defined LINUX
	return toupper(c);
#endif
}

void utils::string_to_upper(std::string & str) {
	std::transform(str.begin(), str.end(), str.begin(), &utils::to_upper);
}

template<typename T>
std::string utils::to_string(T value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}

template<typename T>
T utils::string_convert(const std::string & number) {
	std::stringstream ss(number);
	T n;
	ss >> n;
	return n;
}
