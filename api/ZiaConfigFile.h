/**
 *
 *
 *
 */

#pragma once
#define	__ZIACONFIGFILE_H__

#include "ZiaDefine.h"
#include "variant/Variant.hpp"
#include "collection/Collection.hpp"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

	/**
	 * @class CFLibrary
	 */
	interface CFLibrary {
	public:
		CFLibrary();
		virtual ~CFLibrary();

		virtual const std::string & getName() const = 0;
		virtual const std::string & getPath() const = 0;

	};

	/**
	 * @class CFFilter
	 */
	interface CFFilter {
	public:
		CFFilter();
		virtual ~CFFilter();

		virtual const std::string & getName() const = 0;
		virtual bool isEnable() const = 0;

	};

	/**
	 * @class CFModule
	 */
	interface CFModule {
	public:
		CFModule();
		virtual ~CFModule();

		virtual const std::string & getName() const = 0;
		virtual const std::string & getFilter() const = 0;
		virtual bool isEnable() const = 0;

		virtual bool hasArgument(const std::string & name) const = 0;
		virtual const utils::Variant & getArgument(const std::string & name) const __throw = 0;
		virtual utils::Variant getArgument(const std::string & name) = 0;

	};

	/**
	 * @class CFService
	 */
	interface CFService {
	public:
		CFService();
		virtual ~CFService();

		virtual const std::string & getName() const = 0;
		virtual bool isEnable() const = 0;

		virtual bool hasArgument(const std::string & name) const = 0;
		virtual const utils::Variant & getArgument(const std::string & name) const __throw = 0;
		virtual utils::Variant getArgument(const std::string & name) = 0;

	};

	/**
	 * @class ZiaConfigFile
         */
	interface ZiaConfigFile {
	public:
		ZiaConfigFile();
		virtual ~ZiaConfigFile();

		virtual void load(const std::string & filename) __throw = 0;

		virtual const std::list<CFLibrary> & getLibraries() const = 0;
		virtual const std::list<CFFilter> & getFilters() const = 0;
		virtual const std::list<CFModule> & getModules() const = 0;
		virtual const std::list<CFService> & getServices() const = 0;

		virtual const CFFilter & getFilter(const std::string & name) const = 0;
		virtual const CFModule & getModule(const std::string & name) const = 0;
		virtual const CFService & getService(const std::string & name) const = 0;

	};

}
