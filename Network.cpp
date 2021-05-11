//
// Created by 姚黎东 on 2021/4/16.
//

#include "Network.h"

Network & Network::instance() {
    static Network inst;
    return inst;
}
bool Network::Empty(){
    std::lock_guard<std::mutex> guard(_mutex);//互斥锁，保证多线程情况下只有一个在运行。
    return _messages.empty();
}

void Network::SendMsg(network_address_t src, network_address_t dst, Message msg) {
    std::lock_guard<std::mutex> guard(_mutex);
    _messages.push_back({src,dst,msg});
}

//从msg list里遍历，如果接收方一样，取出msg;
MessageAddressed Network::RecvMsg(network_address_t dst) {
    std::lock_guard<std::mutex> guard(_mutex);
    for (auto it = _messages.begin(); it !=_messages.end(); ++it)
    {
        if(it->dst == dst)
        {
            auto msg = * it;
            _messages.erase(it);
            return msg;
        }
    }
    throw std::runtime_error("no message for you");
}

network_address_t Network::AssignAddress() {
    std::lock_guard<std::mutex> guard(_mutex);
    return ++nextAddress;
}

network_address_t NetworkNode::GetNodeAddress() const {
    return _nAddress;
}

 NetworkNode::NetworkNode() :_nAddress(Network::instance().AssignAddress()) {
     std::thread([this]() {
         while (true) {
             try {
                 auto msg = Network::instance().RecvMsg(GetNodeAddress());//查询消息列表里发给自己的消息
                 OnRecvMsg(msg.src, msg.msg);//TODO：记录消息发送方和消息?
             } catch (...) {
                 std::this_thread::sleep_for(1s);
             }
         }
     }).detach();
 }

 void NetworkNode::SendMsg(network_address_t dst, Message msg) {
    Network::instance().SendMsg(GetNodeAddress(),dst,msg);
}