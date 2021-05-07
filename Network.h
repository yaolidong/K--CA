//
// Created by 姚黎东 on 2021/4/16.
//

#ifndef K_CA_NETWORK_H
#define K_CA_NETWORK_H

#include <list>
#include <thread>

#include "Pbft.h"
#include "Message.h"

using namespace std::chrono_literals;

struct MessageAddressed{
    network_address_t src;//消息发送方
    network_address_t dst;//消息接收方
    Message msg;
};

//P2P网络
class Network
{
    std::list<MessageAddressed> _messages;
    network_address_t  nextAddress = 0;
    std::mutex _mutex;

public:
    static Network & instance();//返回网络实例（静态全局）
    bool Empty();
    void SendMsg(network_address_t src, network_address_t dst, Message msg);
    MessageAddressed RecvMsg(network_address_t dst);//查询消息列表中是否有该节点的消息
    network_address_t  AssignAddress();//分配网络地址，0，1，2，3，4
};

//网络节点
class NetworkNode
{
    const network_address_t _nAddress;
    std::mutex _mutex;

public:
    NetworkNode();//将网络地址分配给节点_nAddress
    network_address_t GetNodeAddress() const;//获取节点地址
    virtual void OnRecvMsg(network_address_t src, Message msg) = 0;
    void SendMsg(network_address_t dst, Message msg);//向消息接收方发送消息
};
#endif //K_CA_NETWORK_H