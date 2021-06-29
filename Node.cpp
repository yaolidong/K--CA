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
    SendMsg(dst, request);//TODO：暂设置IP地址为0的节点是主节点，还未做主节点选拔
}

void Client::OnRecvMsg(network_address_t src, Message msg) {
    std::cout<<msg.str()<<std::endl;

}

void Node::SendPrepare(network_address_t dst, Message msg)
{
    Message prepare(Message::PREPARE);
    SendMsg(dst,prepare);

}
void Node::SendCommit(network_address_t dst, Message msg)
{
    Message commit(Message::COMMIT);
    SendMsg(dst,commit);

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
    ViewState state;
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

//void Node::Signature(Message & msg,ViewState vs) {
//    std::stringstream  ss;
//    ss<<msg.c<<msg.o<<msg.t;
//    _state.insert(std::make_pair<std::string,std::string>(sha256(ss.str()),vs.GetState(msg)));
//}
//
//void Node::VerfitySignature( Message msg)
//{
//	std::stringstream ss;
//	ss << Message::v << msg.d << GetNodeAdd() << Message::n;
//	_log.insert(std::make_pair<int,std::string>((int)src, ss.str()));
//
//}
