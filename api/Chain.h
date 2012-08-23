/**
 *
 *
 *
 *
 */

#pragma once
#define __CHAIN_H__

#include "ZiaDefine.h"
#include "ZiaException.h"
#include "ZiaObject.h"
#include "Module.h"
#include "Filter.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	EXCEPTION_DECLARATION_INLINE_ERROR(ZiaChainException, ZiaException);
	EXCEPTION_DECLARATION_INLINE(ZiaUnknowFilterException, ZiaException, "Unknow filter " + error);

        class Chain : public ZiaObject {
	protected:
		typedef std::list<Filter *> ListFilter;
		ListFilter filters;
		bool init;

        public:
                Chain(ZiaCore & core);
                virtual ~Chain();

                /*Filter*/
		bool hasFilter(const std::string & filterName) const;
		Filter & getFilter(const std::string & filterName) const __throw __throw1(ZAN::ZiaUnknowFilterException);

		Chain & addFilter(Filter __delegate * filter, Position pos = End, const std::string & filterName = "") __throw __throw1(ZAN::ZiaUnknowModuleException);
		Chain & removeFilter(const std::string & filterName) __throw __throw1(ZAN::ZiaUnknowFilterException);
		Chain & setEnableFilter(const std::string & filterName) __throw __throw1(ZAN::ZiaUnknowFilterException);

                /*Module*/
                bool hasModule(const std::string & moduleName) const;
                Module & getModule(const std::string & moduleName) const __throw __throw1(ZAN::ZiaUnknowModuleException);

                Chain & addModule(Module __delegate * module, const std::string & filterName, Position pos = End, const std::string & moduleName = "") __throw __throw1(ZAN::ZiaUnknowModuleException);
                Chain & removeModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);
		Chain & setEnableModule(const std::string & moduleName, bool enable) __throw __throw1(ZAN::ZiaUnknowModuleException);

                /*Execution*/
                bool initialize() __throw;
		bool isInitialized() const;

                void execute(Request & request, Response & response) __throw;

        };

}
