//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"



void Client::SendRequest(network_address_t dst, std::string o) {
    Message request(Message::REQUEST);
    request.t = std::time(nullptr);
    request.o = o;
    request.c = request.i = GetNodeAddress();
    request.m = request.str();
    request.n = 0;
    request.d = request.diggest();



    SendMsg(dst, request);//TODO：暂设置IP地址为0的节点是主节点，还未做主节点选拔

}

void Client::OnRecvMsg(network_address_t src, Message msg) {
    std::cout<<msg.str()<<std::endl;

}


void Node::SetAllNodes(const std::vector<std::unique_ptr<Node>> &allNodes) {

    for (auto & node : allNodes) {
        if (node->GetNodeAddress() == GetNodeAddress()) {
            continue;
        }
        _otherNodes.push_back(node->GetNodeAddress());
    }
}


//TODO:获取信息更改视图状态
ViewState  Node::GetState(Message msg) {

    switch (msg.msg_type) {
        case Message::REQUEST: {
            ViewState vt = ViewState(ViewState::SetState(msg));
            return vt;
        }
        case Message::PRE_PREPARE: {
            ViewState vt = ViewState(ViewState::SetState(msg));
            return vt;
        }
        case Message::PREPARE: {
            ViewState vt = ViewState(ViewState::SetState(msg));
            return vt;
        }
        case Message::COMMIT: {
            ViewState vt = ViewState(ViewState::SetState(msg));
            return vt;
        }
        case Message::REPLY: {
            ViewState vt = ViewState(ViewState::SetState(msg));
            return vt;
        }
    }
}

//输出消息发送方和消息内容 获取状态并处理信息
void Node::OnRecvMsg(network_address_t src, Message msg)
{
    std::lock_guard<std::mutex> console_guard(console_mutex);
    std::cout << "Node() " << src << " -> " << GetNodeAddress() << ": " << msg.str() << std::endl;
    auto state = GetState(msg);
    state.handle_message(msg, *this);


}

void Node::SendAll(Message msg) {

    for(auto dst : _otherNodes)
    {
        SendMsg(dst,msg);
    }
}