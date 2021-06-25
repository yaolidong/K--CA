//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Message.h"
#include "Node.h"


ViewState::ViewState() :_state(Pre_prepare){}
ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {

    switch (_state) {
        case Pre_prepare:	
            msg.msg_type = Message::PRE_PREPARE;
            Message::n++;
            msg.m = msg.str();
            msg.d = msg.diggest();
            node.SendAll(msg);
        }
            break;
        case Prepare: {
            msg.msg_type = Message::PREPARE;
			//sure tx if true;
			msg.i = node.GetNodeAdd();
			node.SendAll(msg);
        }

            break;
        case Commit:{
            msg.msg_type = Message::COMMIT;
			accepeted_prepares++;
			if (accepeted_prepares > 2 * Fault_Node + 1 )
			{
				// up chain;
				msg.o = "true";
			}
			if("true" == msg.o)
				 node.SendAll(msg);

        }
            break;


        case Reply:
        {
            accepeted_commits++;
			if(accepeted_commits > 2 * Fault_Node + 1 )
			{
				//up chain;
				msg.o = "upchain";
			}
			if("upchain" == msg.o)
				{}	//TODO:send reply msg;
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


