//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"


ViewState::ViewState(ViewState::state_t _st): _state(_st){

}

void ViewState::handle_message(Message msg, Node & node) {
    switch (msg.msg_type) {
        case Message::REQUEST: {
            std::cout<<msg.str()<<std::endl;
            msg.n = 0;
            msg.i = node.GetNodeAddress();
            msg.msg_type = Message::PRE_PREPARE;
            node.SendAll(msg);
        }
            break;


        case Message::PRE_PREPARE: {
            msg.o = "True";
            msg.i = node.GetNodeAddress();
            msg.msg_type = Message::PREPARE;
            node.SendAll(msg);

        }
            break;
        case Message::PREPARE:{
            msg.o = "Verify";
            msg.i = node.GetNodeAddress();
            msg.msg_type = Message::COMMIT;
            node.SendAll(msg);

        }
            break;


        case Message::COMMIT:
        {
            msg.o = "Commit";
            msg.msg_type = Message::REPLY;
            msg.v++;
            node.SendMsg(msg.c,msg);
            }
            break;
    }

}

ViewState::state_t ViewState::SetState(Message msg) {

    switch (msg.msg_type) {
        case Message::REQUEST:
            return ViewState::Requested;
        case Message::PRE_PREPARE:
            return ViewState::Pre_prepared;
        case Message::PREPARE:
            return ViewState::Prepared;
        case Message::COMMIT:
            return ViewState::Committed;
        case Message::REPLY:
            return ViewState::Replyed;
    }
}

