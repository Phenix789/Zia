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

	EXCEPTION_DECLARATION_INLINE(UnknowKeyException, Exception, "Unknow key : " + error);

	class Collection {
	public:
		typedef std::map<std::string, Variant> Map;

	protected:
		Map collection;

	public:

		inline Collection() {

		}

		inline virtual ~Collection() {

		}

		inline bool hasKey(const std::string & key) const {
			return collection.find(key) != collection.end();
		}

		const Variant & getValue(const std::string & key) const __throw __throw1(utils::UnknowKeyException) {
			Map::const_iterator it = collection.find(key);
			if (it != collection.end()) {
				return it->second;
			}
			throw UnknowKeyException(key);
		}

		Variant getValue(const std::string & key) __throw __throw1(utils::UnknowKeyException) {
			Map::iterator it = collection.find(key);
			if (it != collection.end()) {
				return it->second;
			}
			throw UnknowKeyException(key);
		}

		Variant getValue(const std::string & key, Variant defaultValue) {
			Map::iterator it = collection.find(key);
			if (it != collection.end()) {
				return it->second;
			}
			return defaultValue;
		}

		inline int count() const {
			return collection.size();
		}

		inline const Map & getMap() const {
			return collection;
		}

		void setValue(const std::string & key, const Variant & value) {
			collection[key] = value;
		}

//		void setValue(const std::string & key, Variant value) {
//			collection[key] = value;
//		}

		void removeValue(const std::string & key) {
			Map::iterator it = collection.find(key);
			if (it != collection.end()) {
				collection.erase(it);
			}
		}

		inline void clear() {
			collection.clear();
		}

		const Variant & operator [](const std::string & key) const __throw __throw1(utils::UnknowKeyException) {
			Map::const_iterator it = collection.find(key);
			if (it != collection.end()) {
				return it->second;
			}
			throw UnknowKeyException(key);
		}

		Variant & operator [](const std::string & key) {
			return collection[key];
		}

	};

}
