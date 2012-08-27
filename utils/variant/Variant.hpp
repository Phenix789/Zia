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
		Variant();
		virtual ~Variant();

		const std::string & getValue() const;

		/*Cast*/
		std::string toString() const;
		int toInt() const;
		float toFloat() const;

		/*Template*/
		template<typename T>
		Variant(const T & value)
		: value(utils::to_string<T>(value)) {

		}

		template<typename T>
		Variant & operator =(const T & value) {
			this->value = utils::to_string(value);
			return *this;
		}

		template<typename T>
		operator T() const {
			return utils::string_convert<T > (value);
		}

	};

}
