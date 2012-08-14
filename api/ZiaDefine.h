/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIADEFINE_H__

#include <string>
#include <list>
#include <map>
#include "Define.h"

#define ZIA_API_NAMESPACE ZiaAPI
#define ZAN ZIA_API_NAMESPACE

#define ZIA_CORE class ZiaCore;

namespace ZIA_API_NAMESPACE {

	typedef int MetadataCollection;
	typedef int Buffer;
	typedef std::map<std::string, std::string> ParameterMap;

        enum ProtocolVersion {
                HTTP_1_0,
                HTTP_1_1,
                HTTP_2_0 //Developpement futur
        };

        enum RequestMethod {
                OPTIONS,
                GET,
                PUT,
                POST,
                DELETE,
                HEAD,
                TRACE,
                CONNECT
        };

        enum ResponseCode {
                RC_100,
                RC_101,
                RC_102, //RFC 2518
                RC_200,
                RC_201,
                RC_202,
                RC_203,
                RC_204,
                RC_205,
                RC_206,
                RC_207, //RFC 4918
                RC_208, //RFC 5842
                RC_226, //RFC 3229
                RC_300,
                RC_301,
                RC_302,
                RC_303,
                RC_304,
                RC_305,
                RC_306,
                RC_307,
                RC_308, //RFC reschke-http-status-308-07
                RC_400,
                RC_401,
                RC_402,
                RC_403,
                RC_404,
                RC_405,
                RC_406,
                RC_407,
                RC_408,
                RC_409,
                RC_410,
                RC_411,
                RC_412,
                RC_413,
                RC_414,
                RC_415,
                RC_416,
                RC_417,
                RC_418, //RFC 2324
                RC_422, //RFC 4918
                RC_423, //RFC 4918
                RC_424, //RFC 4918
                RC_425, //RFC 2817
                RC_426, //RFC 2817
                RC_428, //RFC 6585
                RC_429, //RFC 6585
                RC_431, //RFC 6585
                RC_500,
                RC_501,
                RC_502,
                RC_503,
                RC_504,
                RC_505,
                RC_506, //RFC 2295
                RC_507, //RFC 4918
                RC_508, //RFC 5842
                RC_510, //RFC 2774
                RC_511, //RFC 6585
        };

	const std::string & get_protocol_version_string(ProtocolVersion version);
	const std::string & get_request_method_string(RequestMethod method);
        const std::string & get_response_code_string(ResponseCode code);

}
