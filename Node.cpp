//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"
#include "Message.h"
#include "sha256.h"
#include <sstream>
#include <string>
#include <utility>



void Client::SendRequest(network_address_t dst, std::string o) {
    Message request(Message::REQUEST);
    request.t = std::time(nullptr);
    request.o = o;
    request.c = request.i = GetNodeAddress();
    request.m = request.str();
    request.d = request.diggest();
    SendMsg(dst, request);//TODO：暂设置地址为2的节点是主节点，还未做主节点选拔
}

void Client::OnRecvMsg(network_address_t src, Message msg) {
    std::cout<<msg.str()<<std::endl;

}

void Node::SendPrepare( Message msg)
{
    Message prepare(Message::PREPARE);
    prepare.t = msg.t;
    prepare.o = msg.o;
    prepare.c = msg.c;
    prepare.i = GetNodeAdd();
    prepare.m = msg.str();
    prepare.d = msg.diggest();


    for(auto i :_otherNodes)
        SendMsg(i,prepare);

}
void Node::SendCommit( Message msg)
{
    Message commit(Message::COMMIT);
    commit.t = msg.t;
    commit.o = msg.o;
    commit.c = msg.c;
    commit.i = GetNodeAdd();
    commit.m = msg.str();
    commit.d = msg.diggest();


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
void Node::OnRecvMsg(network_address_t src, Message msg)
{
    std::lock_guard<std::mutex> console_guard(console_mutex);
    ViewState state ;
    state.GetState(msg);
    state.handle_message(msg, *this);
}

//发送给其他所有节点
void Node::SendAll(Message msg) {

    for(auto dst : _otherNodes)
    {
        SendMsg(dst,msg);
    }
}

network_address_t Node::GetNodeAdd() {
    return NetworkNode::GetNodeAddress();
}
