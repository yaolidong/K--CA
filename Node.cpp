//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"



void Client::SendRequest(network_address_t dst, std::string o) {
    Message request(Message::REQUEST);
    request.t = std::time(nullptr);
    request.o = o;
    SendMsg(dst, request);
    //TODO：暂设置IP地址为0的节点是主节点，还未做主节点选拔

}

void Client::OnRecvMsg(network_address_t src, Message msg) {
    std::cout<<msg.str()<<std::endl;

}


void Node::SetAllNodes(const std::vector<std::unique_ptr<Node>> &allNodes) {
 /*   for (auto it = allNodes.begin(); it !=allNodes.end(); it ++)
    {
        if(*it != GetNodeAddress())
            _otherNodes.push_back(*it);
    }*/

    //主节点选举
    //if(GetNodeAddress() ==  % allNodes.size())

    for (auto & node : allNodes) {
        if (node->GetNodeAddress() == GetNodeAddress()) {
            continue;
        }
        _otherNodes.push_back(node->GetNodeAddress());
    }
}


//TODO:获取状态
ViewState & Node::GetState(Message msg) {
    switch (msg.msg_type) {
        case Message::REQUEST:
        {}
        break;
        case Message::PRE_PREPARE:
        {}
        break;

        case Message::PREPARE:
            break;
        case Message::COMMIT:
            break;
        case Message::REPLY:
            break;
    }
}

void Node::OnRecvMsg(network_address_t src, Message msg) {
    std::lock_guard<std::mutex> console_guard(console_mutex);
    std::cout << "Node() " << src << " -> " << GetNodeAddress() << ": " << msg.str() << std::endl;
    auto & state = GetState(msg);
    state.handle_message(msg, *this);

/*    if(GetNodeAddress() == _view % allNodes.size())
    {

    }*/

}

void Node::SendAll(Message msg) {
/*    for (auto it = _otherNodes.begin(); it != _otherNodes.end(); it++)
        SendMsg(*it, msg);*/
    for(auto dst : _otherNodes)
    {
        SendMsg(dst,msg);
    }
}