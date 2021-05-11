# pragma once//使头文件不能包含多次
#include "Pbft.h"
#include <cstddef>
#include <string>

class Message
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
	std::string m;//消息内容
	time_t t;//客户端请求交易的时间戳
	size_t v;//视图编号
	std::string d;//消息摘要
	size_t n;//消息排序
	network_address_t c = 0;//节点地址 int类型

	Message(msg_type_t _type);
	std::string diggest();//生成REQUEST消息摘要
	std::string str() const;//生成消息内容
};