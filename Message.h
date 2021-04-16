# pragma once//使头文件不能包含多次
#include "pbft.h"
#include <cstddef>
#include <string>

struct Message
{
	enum msg_type_t
	{
		REQUEST,
		PRE_PREPARE,
		PREPARE,
		COMMIT,
		REPLY
	}msg_type;

	std::string o;
	std::string r;
	time_t t = 0;
	size_t v = 0;
	size_t d = 0;
	size_t n = 0;
	network_address_t c = 0;//在pbft.cpp中typedef int

	Message(msg_type_t _type);
	size_t diggest();
	std::string str() const;
};
