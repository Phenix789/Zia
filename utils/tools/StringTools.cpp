/**
 *
 *
 *
 */

#include <iosfwd>
#include <string>
#include <vector>
#include <cstring>

#include "StringTools.hpp"

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

std::vector<std::string> & utils::split(const std::string & str, char * delim, std::vector<std::string> & strings) {
	std::stringstream ss(str);
	int old = 0;
	int pos = 0;
	int size = std::strlen(delim);
	while (old != std::string::npos) {
		pos = str.find(delim, old);
		if (pos == std::string::npos) {
			return strings;
		}
		strings.push_back(str.substr(old, pos - old));
		old = pos + size;
	}
	return strings;
}

std::vector<std::string> utils::split(const std::string & str, char * delim) {
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
