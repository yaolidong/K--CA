//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"


ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {
    switch (msg.msg_type) {
        case Message::REQUEST: {
            msg.msg_type = Message::PRE_PREPARE;
            Message::n++;
            msg.m = msg.str();
            msg.d = msg.diggest();
            node.SendAll(msg);
        }
            break;
        case Message::PRE_PREPARE: {
            msg.msg_type = Message::PREPARE;
              msg.i = node.GetNodeAddress();

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
        case Message::REPLY:
            break;
    }

}


ViewState ViewState::GetState(Message msg) {
    switch(msg.msg_type){
        case (Message::REQUEST):
        {
            (*this)._state = Pre_prepared;
            break;
		}
        case Message::PRE_PREPARE:
        {
            (*this)._state = Prepared;
            break;
		}
        case (Message::PREPARE):
        {
            (*this)._state = Committed;
            break;
        }
        case Message::COMMIT:
        {
            (*this)._state = Replyed;
            break;
        }

        case Message::REPLY:
            break;
    }

}

ViewState::ViewState() :_state(Pre_prepared){
}

