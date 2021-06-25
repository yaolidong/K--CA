//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Node.h"


ViewState::ViewState() :_state(Pre_prepared){}
ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {

    switch (_state) {
        case Pre_prepare: {
            msg.msg_type = Message::PRE_PREPARE;
            Message::n++;


			
            msg.m = msg.str();
            msg.d = msg.diggest();
            node.SendAll(msg);
        }
            break;
        case Prepare: {
            msg.msg_type = Message::PREPARE;
            msg.i = node.GetNodeAdd();



        }
            break;
        case Commit:{
            accepeted_prepares++;
            node.SendAll(msg);
            msg.msg_type = Message::COMMIT;
            node.SendAll(msg);

        }
            break;


        case Reply:
        {
            Message::v++;
            accepeted_commits++;
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
            (*this)._state = Pre_prepare;
            return "Pre_prepared";
		}
        case Message::PRE_PREPARE:
        {
            (*this)._state = Prepare;
            return "Prepared";
		}
        case (Message::PREPARE):
        {
            (*this)._state = Commit;
            return "Committed";
        }
        case Message::COMMIT:
        {
            (*this)._state = Reply;
            return "Replyed";
        }

    }

}


