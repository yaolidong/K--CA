#ifndef K_CA_MESSAGE_H
#define K_CA_MESSAGE_H
#include "Pbft.h"
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
	time_t t;//客户端请求交易的时间戳
	network_address_t c = 0;//节点地址 int类型
	std::string d;//消息摘要
	size_t v = 0;//视图编号
	size_t n = 0;//消息排序
	network_address_t i = 0;
     std::string m;//消息内容


    explicit Message(msg_type_t _type);
	std::string diggest();//生成REQUEST消息摘要
	std::string str() const;//生成消息内容
};
#endif
