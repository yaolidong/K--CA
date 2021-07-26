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

void Client::OnRecvMsg(network_address_t src, Message &msg) {

    for (auto iter = accepted_reply.begin();  iter!= accepted_reply.end() ; iter++) {
        if(iter->first == msg.d)
        {
            iter->second++;
        }
    }
    if(accepted_reply.find(msg.d)->second == 2 )//TODO:K_CA
    {
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
    prepare.d = msg.d;
    prepare.m = msg.str();

    for(auto i :_otherNodes)
    {
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
    commit.d = msg.d;
    commit.m = msg.str();


    for(auto i :_otherNodes)
    {
        SendMsg(i,commit);
    }


}


void Node::SetAllNodes(const std::vector<std::unique_ptr<Node>> &allNodes) {

    for (auto & node : allNodes) {
        if (node->GetNodeAddress() == GetNodeAddress()) {
            continue;
        }
        _otherNodes.push_back(node->GetNodeAddress());
    }
}

//void Node::GetState(Message &msg) {
//
//}

//输出消息发送方和消息内容 获取状态并处理信息
void Node::OnRecvMsg(network_address_t src, Message &msg)
{
    std::lock_guard<std::mutex> console_guard(console_mutex);
    if (msg.msg_type == Message::REQUEST || msg.msg_type == Message::PRE_PREPARE)
    {
        key_t kt = key_t(msg.c,msg.o,msg.t,msg.d);
        ViewState vs(msg);
        _log[kt] = vs;

    }
    key_t kt = key_t(msg.c,msg.o,msg.t,msg.d);
    auto iter = _log.find(kt);
    if (iter ==_log.end())
        std::cout << "找不到交易信息视图！"<< std::endl;
    else
        iter->second.handle_message(msg, *this);

}


//发送给其他所有节点
void Node::SendAll(Message &msg) {

    for(auto dst : _otherNodes)
    {
        SendMsg(dst,msg);
    }
}

network_address_t Node::GetNodeAdd() {
    return NetworkNode::GetNodeAddress();
}


void Node::TransToCache(Message &msg) {
    std::cout << "Node " <<Node::GetNodeAdd() << "交易进交易池" <<std::endl;
    ca.AddTranslation(msg);
}

bool Node::TransQueueEmpty() {
    return sl.IsCacheEmpty(ca);
}

void Node::SealTrans() {
    std::cout << "Node " <<Node::GetNodeAdd() << "打包交易" <<std::endl;
    sl.CalculateMerkRoot(ca,bChain);
    if(400 == sl.GetTransCount())
    {
        sl.Upchain(bChain);
        sl.ReduceCount();

    }

}

void Node::SendMessage(network_address_t dst, Message msg) {
    NetworkNode::SendMsg(dst,msg);

}
Node::key_t::key_t(Message &msg) {
    c = msg.c;
    o = msg.o;
    t = msg.t;
    d = msg.d;
}
 bool Node::key_t::operator<(const Node::key_t &k1) const
{
    if(t <k1.t)
        return true;
    else if(t == k1.t)
    {
        if (c < k1.c)
            return true;
        else if(c == k1.c)
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

Node::key_t::key_t():c(0),o("0"),t(0),d("0"){}



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

Node::key_t::key_t(network_address_t c, std::string o, time_t t, std::string d):c(c),o(std::move(o)),t(t),d(std::move(d)) {

}



