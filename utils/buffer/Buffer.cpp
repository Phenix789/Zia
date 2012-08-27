/**
 *
 *
 *
 */

#include "Array.hpp"
#include "CBuffer.hpp"

utils::OutOfBoundsException::OutOfBoundsException(int position, int max) throw()
: position(position), max(max) {

}

utils::OutOfBoundsException::~OutOfBoundsException() throw () {

}

int utils::OutOfBoundsException::getPosition() const throw () {
	return position;
}

int utils::OutOfBoundsException::getMax() const throw () {
	return max;
}

const char * utils::OutOfBoundsException::what() throw () {
	std::stringstream ss;
	ss << "Out of bounds : " << position << " (" << max << ")";
	return ss.str().data();
}
