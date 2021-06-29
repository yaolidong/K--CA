//
// Created by 姚黎东 on 2021/4/16.
//

#include "Node.h"
#include "Message.h"
#include "sha256.h"
#include <sstream>
#include <string>
#include <utility>



size_t Node::GetSeq() {
    return _seq++;
}

size_t Node::GetView() {
    return _view++;
}

size_t Node::GetAccCom() const{
    return accepeted_committed;
}

size_t Node::GetAccPre() const{
    return accepeted_prepared;
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

void Client::OnRecvMsg(network_address_t src, Message msg) {
    accepeted_reply++;
    if(accepeted_reply > 2 * Fault_Node)
        std::cout<<msg.str()<<std::endl;

}

Client::Client() {
}


void Node::SendPrepare( Message msg)
{
    Message prepare(Message::PREPARE);
    prepare.t = msg.t;
    prepare.o = msg.o;
    prepare.c = msg.c;
    prepare.v = msg.v;
    prepare.n = msg.n;
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
    commit.v = msg.v;
    commit.n = msg.n;
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
    LogMessage(msg);
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

void Node::LogMessage(Message msg) {
    switch (msg.msg_type) {
        case Message::REQUEST:
       //     _log.insert(std::map<int,std::string>::value_type(msg.i,"REQUEST"));
            _log[msg.i] = "REQUEST";
            break;
        case Message::PRE_PREPARE:
          //  _log.insert(std::map<int,std::string>::value_type(msg.i,"PRE_PREPARE"));
            _log[msg.i] = "PRE_PREPARE";
            _seq++;
            break;
        case Message::PREPARE:
         //   _log.insert(std::map<int,std::string>::value_type (msg.i,"PREPARE"));
            _log[msg.i] = "PREPARE";
            accepeted_prepared++;
            break;
        case Message::COMMIT:
        //    _log.insert(std::map<int,std::string>::value_type(msg.i,"COMMIT"));
            _log[msg.i] = "COMMIT";
            accepeted_committed++;
            break;
        case Message::DONE:
           // _log.insert(std::map<int,std::string>::value_type(msg.i,"Done"));
            _log[msg.i] = "DONE";
            _view++;
            accepeted_prepared = 0;
            accepeted_committed = 0;
            break;
        case Message::BAD:
            _view++;
            accepeted_prepared = 0;
            accepeted_committed = 0;
            break;
    }

}

