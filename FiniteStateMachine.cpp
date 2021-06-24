//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"


ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {

    switch (_state) {
        case Pre_prepared: {
            msg.msg_type = Message::PRE_PREPARE;
            Message::n++;
			
            msg.m = msg.str();
            msg.d = msg.diggest();
            node.SendAll(msg);
        }
            break;
        case Prepared: {
            msg.msg_type = Message::PREPARE;
            msg.i = node.GetNodeAdd();



        }
            break;
        case Committed:{
            node.SendAll(msg);
            msg.msg_type = Message::COMMIT;
            node.SendAll(msg);

        }
            break;


        case Replyed:
        {
            Message::v++;
            node.SendMsg(msg.c,msg);
            }
            break;
    }

}


//change state with msg  and pull in map<>
std::string ViewState::GetState(const Message & msg) {
    switch(msg.msg_type){
        case (Message::REQUEST):
        {
            (*this)._state = Pre_prepared;
            return "Pre_prepared";
		}
        case Message::PRE_PREPARE:
        {
            (*this)._state = Prepared;
            return "Prepared";
		}
        case (Message::PREPARE):
        {
            (*this)._state = Committed;
            return "Committed";
        }
        case Message::COMMIT:
        {
            (*this)._state = Replyed;
            return "Replyed";
        }

    }

}

ViewState::ViewState() :_state(Pre_prepared){
}

