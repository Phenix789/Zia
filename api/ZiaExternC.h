/**
 *
 *
 *
 */

#pragma once
#define	__ZIAEXTERNC_H__

#include "ZiaDefine.h"
#include "Loader.h"

#define ZIA_REGISTER "zia_register"
typedef void (*zia_register_t)(ZAN::LoaderModule &, ZAN::LoaderService &);

extern "C" {

	void zia_register(ZAN::LoaderModule & modules, ZAN::LoaderService & services);

}
