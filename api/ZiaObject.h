/**
 *
 *
 *
 */

#pragma once
#define	__ZIAOBJECT_H__
#warning "Include deprecated ZiaObject"

#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	class ZiaCore;

	abstract class ZiaObject {
	protected:
		ZiaCore & core;

	public:
		inline ZiaObject(ZiaCore & core) : core(core) {}
		virtual ~ZiaObject() {}
	};

}
