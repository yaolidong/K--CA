//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Node.h"

ViewState::ViewState() {
        _state = REQUESTED;
}
ViewState::ViewState(const Message& msg) {
    if(msg.msg_type == Message::REQUEST)
        _state = REQUESTED;
    else if(msg.msg_type == Message::PRE_PREPARE)
        _state = PRE_PREPARED;
}

ViewState::ViewState(const ViewState &vt) {
    _state = vt._state;
    accepted_prepared = vt.accepted_prepared;
    accepted_committed = vt.accepted_committed;
}
ViewState & ViewState::operator=(const ViewState &vt) {
    if (this == &vt)
        return *this;
    _state = vt._state;
    accepted_prepared = vt.accepted_prepared;
    accepted_committed = vt.accepted_committed;
    return *this;
}
void ViewState::handle_message(Message msg, Node & node) {
    switch (_state) {
        case REQUESTED: {
            //TODO：主节点验证客户端请求消息签名是否正确，如果正确，则
            msg.msg_type = Message::PRE_PREPARE;
            msg.i = node.GetNodeAdd();
            msg.n = node.GetTransNum();
            node.SendAll(msg);
            _state = PRE_PREPARED;
            break;
        }

        case PRE_PREPARED: {
            //TODO：副本节点验证
            // a. 主节点PRE-PREPARE消息签名是否正确。
            // b. 当前副本节点是否已经收到了一条在同一v下并且编号也是n，但是签名不同的PRE-PREPARE信息。
            // c. d与m的摘要是否一致。
            // d. n是否在区间[h, H]内。
            // 如果正确，则
            if (msg.msg_type == Message::PRE_PREPARE)
            {
                node.SendPrepare(msg);
            }
            else if(msg.msg_type == Message::PREPARE)
            {

                accepted_prepared++;
            }
            if (accepted_prepared == k_value )//TODO:K_CA
            {
                _state = PREPARED;
                node.SendCommit(msg);
            }
            break;
        }
        case PREPARED: {
            if (msg.msg_type == Message::PREPARE)
              break;
            else if (msg.msg_type == Message::COMMIT)
                accepted_committed++;
            if (accepted_committed == k_value )//TODO:K_CA
            {
                _state = COMMITTED;
                msg.msg_type = Message::REPLY;
                if(node.GetNodeAdd() == 2 )//TODO:只看单一节点
                {
                  node.TransToCache(msg);
                  node.SealTrans();
                }

                //node.SendMessage(msg.c,msg);
            }
            break;
        }

        case COMMITTED:
            break;

    }

}








