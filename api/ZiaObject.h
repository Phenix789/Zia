/**
 *
 *
 *
 */

#pragma once
#define	__ZIAOBJECT_H__

#include "ZiaDefine.h"

namespace ZIA_API_NAMESPACE {

	class ZiaCore;

	abstract class ZiaObject {
	protected:
		ZiaCore & core;

	public:
		ZiaObject(ZiaCore & core);
		virtual ~ZiaObject();
	};

}
