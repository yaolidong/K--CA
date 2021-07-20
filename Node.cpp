//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"
#include "Message.h"
#include <sstream>
#include <string>


size_t Node::GetAccCom() const{
    return accepted_committed;
}

size_t Node::GetAccPre() const{
    return accepted_prepared;
}

/*void Node::AddTransNum()
{
    _seq++;
}*/

size_t Node::GetTransNum()
{
    return _seq++;
}

void Client::SendRequest(network_address_t dst, std::string o) {
    Message request(Message::REQUEST);
    request.t = std::time(nullptr);
    request.o = o;
    request.c = request.i = GetNodeAddress();
    request.d = request.diggest();
    request.m = request.str();
    SendMsg(dst, request);//TODO：暂设置地址为2的节点是主节点，还未做主节点选拔
}

void Client::OnRecvMsg(network_address_t src, Message &msg) {
    accepeted_reply++;
    if(accepeted_reply > 2 * Fault_Node)
    {
        accepeted_reply = 0;
        std::cout << msg.str() << std::endl;

    }
}

Client::Client() {
}


void Node::SendPrepare( Message &msg)
{
    Message prepare(Message::PREPARE);
    prepare.t = msg.t;
    prepare.o = msg.o;
    prepare.c = msg.c;
    prepare.v = msg.v;
    prepare.n = msg.n;
    prepare.i = GetNodeAdd();
    prepare.d = msg.diggest();
    prepare.m = msg.str();



    for(auto i :_otherNodes)
    {
        //std::cout<<"Send Prepare for " << Node::GetNodeAdd() <<" to " << i <<std::endl;
        SendMsg(i,prepare);
    }


}
void Node::SendCommit( Message &msg)
{
    Message commit(Message::COMMIT);
    commit.t = msg.t;
    commit.o = msg.o;
    commit.c = msg.c;
    commit.v = msg.v;
    commit.n = msg.n;
    commit.i = GetNodeAdd();
    commit.d = msg.diggest();
    commit.m = msg.str();



    for(auto i :_otherNodes)
        SendMsg(i,commit);

}


void Node::SetAllNodes(const std::vector<std::unique_ptr<Node>> &allNodes) {

    for (auto & node : allNodes) {
        if (node->GetNodeAddress() == GetNodeAddress()) {
            continue;
        }
        _otherNodes.push_back(node->GetNodeAddress());
    }
}



//输出消息发送方和消息内容 获取状态并处理信息
void Node::OnRecvMsg(network_address_t src, Message &msg)
{
    std::lock_guard<std::mutex> console_guard(console_mutex);
    ViewState state ;
    state.GetState(msg);
    state.handle_message(msg, *this);
}

//发送给其他所有节点
void Node::SendAll(Message &msg) {

    for(auto dst : _otherNodes)
    {
        //std::cout << "Send PrePrepare for " <<Node::GetNodeAdd() << " to " << dst <<std::endl;
        SendMsg(dst,msg);
    }
}

network_address_t Node::GetNodeAdd() {
    return NetworkNode::GetNodeAddress();
}


void Node::ClearAccPre() {
    accepted_prepared = 0;
}

void Node::ClearAccCom() {
    accepted_committed = 0;
}

void Node::TransToCache(Message &msg) {
    //std::cout << "Node " <<Node::GetNodeAdd() ;
    ca.AddTranslation(msg);
}

bool Node::TransQueueEmpty() {
    return sl.IsCacheEmpty(ca);
}

void Node::SealTrans() {
    sl.CalculateMerkRoot(ca,bChain);
    if(400 == sl.GetTransCount())
    {
        sl.Upchain(bChain);
        sl.ReduceCount();
        //std::cout << "The Node " << Node::GetNodeAdd() << " 添加 " << bChain.GetBlockIndex()
        //<< "个区块。 " << std::endl;
        std::cout << std::endl;

    }

}


Node::key_t::key_t(Message &msg) {
    c = msg.c;
    o = msg.o;
    t = msg.t;
}



bool Node::key_t::operator<(const Node::key_t &k1) const{
    if(t < k1.t && c < k1.c)
        return true;
    else
        return false;
}

Node::key_t::key_t(const key_t &kt) {
    c = kt.c;
    o = kt.o;
    t = kt.t;
}

Node::key_t &Node::key_t::operator=(const Node::key_t &k2) {
    if(this == &k2)
        return *this;
    c = k2.c;
    o = k2.o;
    t = k2.t;
    return *this;


}
