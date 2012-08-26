/**
 *
 *
 *
 */

#pragma once
#define	__VARIANT_HPP__

#include <sstream>
#include "Define.h"
#include "tools/StringTools.hpp"

namespace utils {

	class Variant {
	protected:
		std::string value;

	public:
		inline Variant();
		inline virtual ~Variant();

		inline const std::string & getValue() const;

		/*Cast*/
		inline std::string toString() const;
		inline int toInt() const;
		inline float toFloat() const;

		/*Template*/
		template<typename T>
		inline Variant(const T & value);

		template<typename T>
		inline Variant & operator =(const T & value);

		template<typename T>
		inline operator T() const;

	};

}

/*Template & Inline implementation*/

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

template<typename T>
utils::Variant::Variant(const T & value)
: value(utils::to_string<T>(value)) {

}

template<typename T>
utils::Variant & utils::Variant::operator =(const T & value) {
	this->value = utils::to_string(value);
	return *this;
}

template<typename T>
utils::Variant::operator T() const {
	return utils::string_convert<T>(value);
}

/*String specialization template*/

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