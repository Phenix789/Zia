/**
 *
 *
 *
 *
 */

#pragma once
#define __ZIADEFINE_H__

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "../utils/Define.h"

#define ZIA_API_NAMESPACE ZiaAPI
#define ZAN ZIA_API_NAMESPACE

#define ZIA_API_VERSION_MAJOR 2
#define ZIA_API_VERSION_MINOR 0
#define ZIA_API_VERSION 2.0
#define ZIA_CORE class ZiaCore;

namespace ZIA_API_NAMESPACE {

	typedef std::map<std::string, std::string> HeaderMap;

        enum ProtocolVersion {
                PV_HTTP_1_0,
                PV_HTTP_1_1,
                PV_HTTP_2_0, //Developpement futur
		PV_HTTP_ERROR = -1
        };

        enum RequestMethod {
                RM_OPTIONS,
                RM_GET,
                RM_PUT,
                RM_POST,
                RM_DELETE,
                RM_HEAD,
                RM_TRACE,
                RM_CONNECT,
		RM_ERROR = -1
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

	enum HeaderRequest {
		HRq_Accept,
		HRq_Accept_Charset,
		HRq_Accept_Encoding,
		HRq_Accept_Language,
		HRq_Accept_Datetime,
		HRq_Authorization,
		HRq_Cache_Control,
		HRq_Connection,
		HRq_Cookie,
		HRq_Content_Length,
		HRq_Content_MD5,
		HRq_Content_Type,
		HRq_Date,
		HRq_Expect,
		HRq_From,
		HRq_Host,
		HRq_If_Match,
		HRq_If_Modified_Since,
		HRq_If_None_Match,
		HRq_If_Range,
		HRq_If_Unmodified_Since,
		HRq_Max_Forwards,
		HRq_Prama,
		HRq_Proxy_Authorization,
		HRq_Range,
		HRq_Referer,
		HRq_TE,
		HRq_Upgrade,
		HRq_User_Agent,
		HRq_Via,
		HRq_Warning,
		HRq_X_Requested_With, /*Common non-standard*/
		HRq_DNT, /*Common non-standard*/
		HRq_X_Forwarded_For, /*Common non-standard*/
		HRq_X_ATT_DeviceId, /*Common non-standard*/
		HRq_X_Wap_Profile, /*Common non-standard*/
		HRq_Proxy_Connection /*Common non-standard*/
	};

	enum HeaderResponse {
		HRp_Access_Control_Allow_Origin,
		HRp_Accept_Ranges,
		HRp_Age,
		HRp_Allow,
		HRp_Cache_Control,
		HRp_Connection,
		HRp_Content_Encoding,
		HRp_Content_Language,
		HRp_Content_Length,
		HRp_Content_Location,
		HRp_Content_MD5,
		HRp_Content_Disposition,
		HRp_Content_Range,
		HRp_Content_Type,
		HRp_Date,
		HRp_ETag,
		HRp_Expires,
		HRp_Last_Modified,
		HRp_Link,
		HRp_Location,
		HRp_P3P,
		HRp_Pragma,
		HRp_Proxy_Authenticate,
		HRp_Refresh,
		HRp_Retry_After,
		HRp_Server,
		HRp_Set_Cookie,
		HRp_Strict_Transport_Security,
		HRp_Trailer,
		HRp_Transfer_Encoding,
		HRp_Vary,
		HRp_Via,
		HRp_Warning,
		HRp_WWW_Authenticate,
		HRp_X_Frame_Options, /*Common non-standard*/
		HRp_X_XSS_Protection, /*Common non-standard*/
		HRp_X_Content_Type_Options, /*Common non-standard*/
		HRp_X_Forwarded_Proto, /*Common non-standard*/
		HRp_Front_End_Https, /*Common non-standard*/
		HRp_X_Powered_By, /*Common non-standard*/
		HRp_X_UA_Compatible /*Common non-standard*/
	};

	const std::string & get_protocol_version_string(ProtocolVersion version);
	const std::string & get_request_method_string(RequestMethod method);
        const std::string & get_response_code_string(ResponseCode code);
	const std::string & get_header_request_string(HeaderRequest header);
	const std::string & get_header_response_string(HeaderResponse header);

	ProtocolVersion get_protocol_version(const std::string & version);
	RequestMethod get_request_method(const std::string & method);
	ResponseCode get_response_code(const std::string & code);
	HeaderRequest get_header_request(const std::string & header);
	HeaderResponse get_header_response(const std::string & header);

}
