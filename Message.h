# pragma once//使头文件不能包含多次
#include "Pbft.h"
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

	std::string o;//具体操作
	std::string r;
	time_t t = 0;//客户端请求交易的时间戳
	size_t v = 0;//视图编号
	size_t d = 0;//消息摘要
	size_t n = 0;
	network_address_t c = 0;//int

	Message(msg_type_t _type);
	std::string diggest();
	std::string str() const;
};
