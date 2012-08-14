/**
 *
 *
 *
 *
 */

#pragma once
#define __CHAIN_H__

#include <list>
#include "ZiaDefine.h"
#include "Exception.h"
#include "Module.h"
#include "Service.h"
#include "Filter.h"
#include "Request.h"
#include "Response.h"

namespace ZIA_API_NAMESPACE {

	ZIA_CORE

        class ZiaUnknowFilterException : public ZiaException {
        public:
                ZiaUnknowFilterException(const std::string & filterName) throw ();
                virtual ~ZiaUnknowFilterException() throw ();

        };

        class ZiaUnknowModuleException : public ZiaException {
        public:
                ZiaUnknowModuleException(const std::string & moduleName) throw ();
                virtual ~ZiaUnknowModuleException() throw ();

        };

        class Chain : public Service {
        public:
                enum Position {
                        Before,
                        After
                };

	protected:
		typedef std::list<Filter *> ListFilter;
		ZiaCore & core;
		ListFilter filters;

        public:
                Chain();
                virtual ~Chain();

                /*Filter*/
		bool hasFilter(const std::string & filterName) const;
		Filter & getFilter(const std::string & filterName) const __throw __throw1(ZAN::ZiaUnknowFilterException);

		Chain & addFilter(Filter __delegate * filter, const std::string & filter, Position pos = After) __throw __throw1(ZAN::ZiaUnknowModuleException);
		Chain & removeFilter(const std::string & filterName) __throw __throw1(ZAN::ZiaUnknowFilterException);

		Chain & enableFilter(const std::string & filterName) __throw __throw1(ZAN::ZiaUnknowFilterException);
		Chain & disableFilter(const std::string & filterName) __throw __throw1(ZAN::ZiaUnknowFilterException);


                /*Module*/
                bool hasModule(const std::string & moduleName) const;
                Module & getModule(const std::string & moduleName) const __throw __throw1(ZAN::ZiaUnknowModuleException);

                Chain & addModule(Module __delegate * module, const std::string & filter, Position pos = After) __throw __throw1(ZAN::ZiaUnknowModuleException);
                Chain & removeModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);

                Chain & enableModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);
                Chain & disableModule(const std::string & moduleName) __throw __throw1(ZAN::ZiaUnknowModuleException);

                /*Execution*/
                bool initialize() __throw;
                void execute(Request & request, Response & response) __throw;

        };

}
