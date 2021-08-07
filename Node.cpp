//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"
#include <sstream>
#include <string>


size_t Node::GetTransNum()
{
    return _seq++;
}

void Client::SendRequest(network_address_t dst, std::string o) {
    Message request(Message::REQUEST);
    request.t = std::time(nullptr);
    request.o = std::move(o);
    request.c = request.i = GetNodeAddress();
    request.d = request.diggest();
    request.m = request.str();
    accepted_reply.insert(pair<std::string ,int>(request.d,0));
    SendMsg(dst, request);//TODO：暂设置地址为2的节点是主节点，还未做主节点选拔
}
void Client::OnRecvMsg(network_address_t src, Message msg) {
/*
    for (auto iter = accepted_reply.begin();  iter!= accepted_reply.end() ; iter++) {
        if(iter->first == msg.d)
        {
            iter->second++;
        }
    }
    if(accepted_reply.find(msg.d)->second == k_value  )//TODO:K_CA
    {
        //std::cout << msg.str() << std::endl;
    }*/
}

Client::Client() {
}
void Client::OnRecvBk(Block bk) {}

Blockchain Node::GetBlockChain() {
  return bChain;
}


void Node::SetAllNodes(const std::vector<std::unique_ptr<Node>> &allNodes) {

    for (auto & node : allNodes) {
        if (node->GetNodeAddress() == GetNodeAddress()) {
            continue;
        }
        _otherNodes.push_back(node->GetNodeAddress());
    }
}

void Node::OnRecvMsg(network_address_t src, Message msg)
{
    std::lock_guard<std::mutex> console_guard(console_mutex);
    key_t kt = key_t(msg.c,msg.o,msg.t,msg.d);

    if (msg.msg_type == Message::REQUEST)
    {
        ViewState vs = ViewState();
        _log[kt] = vs;
    }

    auto iter = _log.find(kt);
    if (iter ==_log.end())
    {
      std::cout <<"节点：" <<GetNodeAdd() << "找不到交易信息视图！"<< std::endl;
    }
    else
      iter->second.handle_message(msg, *this);
  }




void Node::SendAll(Message &msg) {

    for(auto dst : _otherNodes)
    {
      //std::cout << "Send Comfirm for " << GetNodeAdd() << " To " << dst <<std::endl;
        SendMsg(dst,msg);
    }
}

network_address_t Node::GetNodeAdd() {
    return NetworkNode::GetNodeAddress();
}


Node::key_t::key_t(Message &msg) {
    c = msg.c;
    o = msg.o;
    t = msg.t;
    d = msg.d;
}
 bool Node::key_t::operator<(const Node::key_t &k1) const
{
    if(c <k1.c)
        return true;
    else if(c == k1.c)
    {
        if (o < k1.o)
            return true;
        else if(o == k1.o)
        {
            if (t < k1.t)
                return true;
            else if (t == k1.t)
            {
                if (d < k1.d)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
Node::key_t &Node::key_t::operator=(const Node::key_t &k2) {
    if(this == &k2)
        return *this;
    c = k2.c;
    o = k2.o;
    t = k2.t;
    d = k2.d;
    return *this;
}
Node::key_t::key_t(const Node::key_t &kt) {
    c = kt.c;
    t = kt.t;
    o = kt.o;
    d = kt.d;
}

Node::key_t::key_t(network_address_t client, std::string object, time_t time, std::string diggest):c(client),o(std::move(object)),t(time),d(std::move(diggest)) {

}
Node::key_t::key_t():c(0),o("0"),t(0),d("0"){}


void Node::TransToCache(Message &msg) {
    ca.AddTranslation(msg);
}

Block Node::SealTrans() {
    sl.CalculateMerkRoot(ca,bChain);
    Block bNew;
    if(400 == sl.GetTransCount())
    {
        std::cout << "节点：" << GetNodeAdd() <<" ";
        bNew = sl.Upchain(bChain);
        sl.ReduceCount();
    }
    return bNew;
}
void Node::SendBlock(Block &bk) {
  for(auto dst : _otherNodes)
  {
    std::cout << "Send Block for " << GetNodeAdd() << " To " << dst <<std::endl;
    NetworkNode::SendBlock(dst,bk);
  }
}
void Node::OnRecvBk(Block bk) {
  bChain.AddBlock(bk);
  std::cout << "节点：" << GetNodeAdd() <<" 添加第 " << bk.GetBIndex() << " 个区块。"<<std::endl;

}
void Node::GetOutBk() {
  BlockAddressed bka;
  if (!Network::instance().List_Blocks())
  {
     bka = Network::instance().RecvBlock(GetNodeAdd());
     bChain.AddBlock(bka.bk);
    std::cout << "节点：" << GetNodeAdd() <<" 添加第 "<< bka.bk.GetBIndex() <<" 个区块 from "<<bka.src<< std::endl;
    std::cout << "Merkle_root:" << bka.bk.GetMerkleRoot()<<std::endl;
  }
  else
    std::cout << "区块列表为空！"<<std::endl;
}
void Node::SendUnpack(Message &msg) {
  Message unpack(Message::UNPACK);
  unpack.t = msg.t;
  unpack.o = msg.o;
  unpack.i = GetNodeAddress();
  unpack.d = msg.d;
  unpack.v = msg.v;
  unpack.c = msg.c;
  unpack.m = msg.m;
  SendAll(unpack);
}
