/**
 *
 *
 *
 */

#pragma once
#define	__COLLECTION_HPP__

#include <map>
#include "Define.h"
#include "tools/Exception.hpp"
#include "variant/Variant.hpp"

namespace utils {

	EXCEPTION_DECLARATION(UnknowKeyException, Exception);

	class Collection {
	public:
		typedef std::map<std::string, Variant> Map;

	protected:
		Map collection;

	public:
		inline Collection();
		inline virtual ~Collection();

		inline bool hasKey(const std::string & key) const;
		inline const Variant & getValue(const std::string & key) const __throw __throw1(UnknowKeyException);
		inline Variant getValue(const std::string & key) __throw __throw1(UnknowKeyException);
		inline Variant getValue(const std::string & key, Variant defaultValue);
		inline int count() const;
		inline const Map & getMap() const;

		inline void setValue(const std::string & key, const Variant & value);
		inline void setValue(const std::string & key, Variant value);

	};

}

/*Inline implementation*/

utils::Collection::Collection() {

}

utils::Collection::~Collection() {

}

bool utils::Collection::hasKey(const std::string & key) const {
	return collection.find(key) != collection.end();
}

const utils::Variant & utils::Collection::getValue(const std::string & key) const {
	Map::iterator it = collection.find(key);
	if (it != collection.end()) {
		return it->second;
	}
	throw UnknowKeyException(key);
}

utils::Variant utils::Collection::getValue(const std::string & key) {
	Map::iterator it = collection.find(key);
	if (it != collection.end()) {
		return it->second;
	}
	throw UnknowKeyException(key);
}

utils::Variant utils::Collection::getValue(const std::string & key, utils::Variant defaultValue) {
	Map::iterator it = collection.find(key);
	if (it != collection.end()) {
		return it->second;
	}
	return defaultValue;
}

int utils::Collection::count() const {
	return collection.size();
}

const utils::Collection::Map & utils::Collection::getMap() const {
	return collection;
}

void utils::Collection::setValue(const std::string & key, const Variant & value) {
	collection[key] = value;
}

void utils::Collection::setValue(const std::string& key, Variant value) {
	collection[key] = value;
}
