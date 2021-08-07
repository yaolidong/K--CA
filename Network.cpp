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

void Network::SendBlock(network_address_t src, network_address_t dst, Block bk){
  std::lock_guard<std::mutex> guard(_mutex);
  _blocks.push_back({src,dst,bk});
}
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

BlockAddressed Network::RecvBlock(network_address_t dst) {
  std::lock_guard<std::mutex> guard(_mutex);
  for (auto it = _blocks.begin(); it !=_blocks.end(); ++it)
  {
    if(it->dst == dst)
    {
      auto bk = *it;
      _blocks.erase(it);
      return bk;
    }
  }
  throw std::runtime_error("no block for you");
}
network_address_t Network::AssignAddress() {
    std::lock_guard<std::mutex> guard(_mutex);
    return ++nextAddress;
}
bool Network::List_Blocks() {
  return _blocks.empty();
}

network_address_t NetworkNode::GetNodeAddress() const{
    return _nAddress;
}

 NetworkNode::NetworkNode() :_nAddress(Network::instance().AssignAddress()) {
     std::thread([this]() {
         while (true) {
             try {
                 auto msg = Network::instance().RecvMsg(GetNodeAddress());
                 OnRecvMsg(msg.src, msg.msg);
             } catch (...) {
                 std::this_thread::sleep_for(1s);
             }
         }
     }).detach();
 }

 void NetworkNode::SendMsg(network_address_t dst, Message msg) {
    Network::instance().SendMsg(GetNodeAddress(),dst,msg);
}
void NetworkNode::SendBlock(network_address_t dst, Block bk) {
  Network::instance().SendBlock(GetNodeAddress(),dst,bk);
}