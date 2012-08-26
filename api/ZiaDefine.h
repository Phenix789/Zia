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
#include <vector>
#include <map>
#include "Define.h"
#include "buffer/Array.hpp"

#define ZIA_API_NAMESPACE ZiaAPI
#define ZAN ZIA_API_NAMESPACE

#define ZIA_API_VERSION_MAJOR 0
#define ZIA_API_VERSION_MINOR 1
#define ZIA_API_VERSION 0.1

#define ZIA_SERVICE_ZIA_CORE "zia_core"
#define ZIA_SERVICE_SERVICE_MANAGER "service_manager"

namespace ZIA_API_NAMESPACE {

	typedef utils::CharArray Buffer;
	typedef std::map<std::string, std::string> ParameterMap;

        enum ProtocolVersion {
                HTTP_1_0,
                HTTP_1_1,
                HTTP_2_0, //Developpement futur
		HTTP_ERROR = -1
        };

        enum RequestMethod {
                OPTIONS,
                GET,
                PUT,
                POST,
                DELETE,
                HEAD,
                TRACE,
                CONNECT,
		ERROR = -1
        };

        enum ResponseCode {
                RC_100 = 100,
                RC_101 = 101,
                RC_102 = 102, //RFC 2518
                RC_200 = 200,
                RC_201 = 201,
                RC_202 = 202,
                RC_203 = 203,
                RC_204 = 204,
                RC_205 = 205,
                RC_206 = 206,
                RC_207 = 207, //RFC 4918
                RC_208 = 208, //RFC 5842
                RC_226 = 226, //RFC 3229
                RC_300 = 300,
                RC_301 = 301,
                RC_302 = 302,
                RC_303 = 303,
                RC_304 = 304,
                RC_305 = 305,
                RC_306 = 306,
                RC_307 = 307,
                RC_308 = 308, //RFC reschke-http-status-308-07
                RC_400 = 400,
                RC_401 = 401,
                RC_402 = 402,
                RC_403 = 403,
                RC_404 = 404,
                RC_405 = 405,
                RC_406 = 406,
                RC_407 = 407,
                RC_408 = 408,
                RC_409 = 409,
                RC_410 = 410,
                RC_411 = 411,
                RC_412 = 412,
                RC_413 = 413,
                RC_414 = 414,
                RC_415 = 415,
                RC_416 = 416,
                RC_417 = 417,
                RC_418 = 418, //RFC 2324
                RC_422 = 422, //RFC 4918
                RC_423 = 423, //RFC 4918
                RC_424 = 424, //RFC 4918
                RC_425 = 425, //RFC 2817
                RC_426 = 426, //RFC 2817
                RC_428 = 428, //RFC 6585
                RC_429 = 429, //RFC 6585
                RC_431 = 431, //RFC 6585
                RC_500 = 500,
                RC_501 = 501,
                RC_502 = 502,
                RC_503 = 503,
                RC_504 = 504,
                RC_505 = 505,
                RC_506 = 506, //RFC 2295
                RC_507 = 507, //RFC 4918
                RC_508 = 508, //RFC 5842
                RC_510 = 510, //RFC 2774
                RC_511 = 511, //RFC 6585
        };

	const std::string & get_protocol_version_string(ProtocolVersion version);
	const std::string & get_request_method_string(RequestMethod method);
        const std::string & get_response_code_string(ResponseCode code);

	ProtocolVersion get_protocol_version(const std::string & version);
	RequestMethod get_request_method(const std::string & method);
	ResponseCode get_response_code(const std::string & code);

}
