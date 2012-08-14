/**
 *
 *
 *
 */

#pragma once
#define	__ZIAEXTERNC_H__

#include "ZiaDefine.h"
#include "Service.h"
#include "Module.h"
#include "Loader.h"

extern "C" {

	void zia_register(ZAN::LoaderModule & modules, ZAN::LoaderService & services);

}
