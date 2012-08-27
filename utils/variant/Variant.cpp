/**
 *
 *
 *
 */

#include "Variant.hpp"

utils::Variant::Variant() {

}

utils::Variant::~Variant() {

}

const std::string & utils::Variant::getValue() const {
	return value;
}

std::string utils::Variant::toString() const {
	return value;
}

int utils::Variant::toInt() const {
	return int(*this);
}

float utils::Variant::toFloat() const {
	return float(*this);
}

namespace utils {

	template<>
	Variant::Variant(const std::string & value)
	: value(value) {

	}

	template<>
	Variant & utils::Variant::operator =(const std::string & value) {
		this->value = value;
		return *this;
	}

	template<>
	Variant::operator std::string() const {
		return value;
	}

}