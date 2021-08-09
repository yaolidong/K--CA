//
// Created by 姚黎东 on 2021/4/16.
//

#ifndef K_CA_NETWORK_H
#define K_CA_NETWORK_H

#include <list>
#include <thread>
#include "Message.h"
#include "Block.h"

using namespace std::chrono_literals;

struct MessageAddressed{
    network_address_t src;
    network_address_t dst;
    Message msg;
};

struct BlockAddressed{
  network_address_t src;
  network_address_t dst;
  Block bk;
};

//P2P网络
class Network
{
    std::list<MessageAddressed> _messages;
    std::list<BlockAddressed> _blocks;
    network_address_t  nextAddress = 0;
    std::mutex _mutex;

public:

    static Network & instance();
    bool Empty();
    bool List_Blocks();
    void SendMsg(network_address_t src, network_address_t dst, Message msg);
    void SendBlock(network_address_t src, network_address_t dst, Block bk);
    MessageAddressed RecvMsg(network_address_t dst);
    BlockAddressed RecvBlock(network_address_t dst);
    network_address_t  AssignAddress();
};

class NetworkNode
{
private:
    const network_address_t _nAddress;
    std::mutex _mutex;

public:
    NetworkNode();
    network_address_t GetNodeAddress() const;
    virtual void OnRecvMsg(network_address_t src, Message msg) = 0;
    void SendMsg(network_address_t dst, Message msg);
    void SendBlock(network_address_t dst, Block bk);
};
#endif
