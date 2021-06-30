//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Node.h"

ViewState::ViewState() :_state(Pre_prepare){
}
ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {

    switch (_state) {
        case Pre_prepare: {
            //TODO：主节点验证客户端请求消息签名是否正确，如果正确，则
            msg.msg_type = Message::PRE_PREPARE;
            msg.i = node.GetNodeAdd();
            node.SendAll(msg);
        }
            break;
        case Prepare: {
            //TODO：副本节点验证
            // a. 主节点PRE-PREPARE消息签名是否正确。
            // b. 当前副本节点是否已经收到了一条在同一v下并且编号也是n，但是签名不同的PRE-PREPARE信息。
            // c. d与m的摘要是否一致。
            // d. n是否在区间[h, H]内。
            // 如果正确，则
            msg.msg_type = Message::PREPARE;
            msg.i = node.GetNodeAdd();
            node.SendPrepare(msg);
        }
            break;
        case Commit:{
            //TODO：如果验证prepare消息正确，则
            if(node.GetAccPre() > 2 * Fault_Node)
            {
                msg.msg_type = Message::COMMIT;
                node.SendCommit(msg);
            }
        }
            break;


        case Reply:
        {
                msg.msg_type = Message::DONE;
                node.SendMsg(msg.c,msg);
        }
            break;

    }

}


void ViewState::GetState(const Message & msg) {
    switch(msg.msg_type){
        case (Message::REQUEST):
        {
            _state = Pre_prepare;
		}
		    break;
        case Message::PRE_PREPARE:
        {
            _state = Prepare;
		}
            break;
        case (Message::PREPARE):
        {
            _state = Commit;
        }
            break;
        case Message::COMMIT:
        {
           _state = Reply;
        }
            break;
        case (Message::DONE):
        {
            _state = Reset;
        }
            break;

    }

}


