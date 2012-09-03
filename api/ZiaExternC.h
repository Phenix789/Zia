/**
 *
 *
 *
 */

#pragma once
#define	__ZIAEXTERNC_H__

#include "ZiaDefine.h"
#include "Loader.h"

extern "C" {

	void zia_register(ZAN::LoaderModule & modules, ZAN::LoaderService & services);

}
