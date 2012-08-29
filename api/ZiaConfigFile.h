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

	/**
	 * @class CFLibrary
	 */
	interface CFLibrary {
	public:
		CFLibrary();
		virtual ~CFLibrary();

		const std::string & getName() const;
		const std::string & getPath() const;

	};

	/**
	 * @class CFFilter
	 */
	interface CFFilter {
	public:
		CFFilter();
		virtual ~CFFilter();

		const std::string & getName() const;
		bool isEnable() const;

	};

	/**
	 * @class CFModule
	 */
	interface CFModule {
	public:
		CFModule();
		virtual ~CFModule();

		const std::string & getName() const;
		const std::string & getFilter() const;
		bool isEnable() const;

		bool hasArgument(const std::string & name) const;
		const utils::Variant & getArgument(const std::string & name) const __throw;
		utils::Variant getArgument(const std::string & name);

	};

	/**
	 * @class CFService
	 */
	interface CFService {
	public:
		CFService();
		virtual ~CFService();

		const std::string & getName() const;
		bool isEnable() const;

		bool hasArgument(const std::string & name) const;
		const utils::Variant & getArgument(const std::string & name) const __throw;
		utils::Variant getArgument(const std::string & name);

	};

	/**
	 * @class ZiaConfigFile
         */
	interface ZiaConfigFile {
	public:
		ZiaConfigFile();
		virtual ~ZiaConfigFile();

		void load(const std::string & filename) __throw;

		const std::list<CFLibrary> & getLibraries() const;
		const std::list<CFFilter> & getFilters() const;
		const std::list<CFModule> & getModules() const;
		const std::list<CFService> & getServices() const;

		const CFFilter & getFilter(const std::string & name) const;
		const CFModule & getModule(const std::string & name) const;
		const CFService & getService(const std::string & name) const;

	};

}
