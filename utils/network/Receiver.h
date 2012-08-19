/**
 *
 *
 *
 */

#pragma once
#define	__RECEIVER_H__

#include "Define.h"
#include "buffer/Array.hpp"

namespace utils {

	class Socket;

	interface Receiver {
	public:
		Receiver(Socket & socket) {}
		virtual ~Receiver() {}

		virtual void onReceive(const utils::CharArray & buffer) = 0;
		virtual void deconnect() = 0;
	};

}
