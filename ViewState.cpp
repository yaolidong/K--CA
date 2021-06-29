//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Node.h"

size_t ViewState::accepeted_commits = 0;
size_t ViewState::accepeted_prepares = 0;

ViewState::ViewState() :_state(Pre_prepare){
}
ViewState::ViewState(state_t _st):_state(_st){}
void ViewState::handle_message(Message msg, Node & node) {

    switch (_state) {
        case Pre_prepare: {
            msg.msg_type = Message::PRE_PREPARE;
           Message::n++;
           msg.i = node.GetNodeAdd();
           msg.m = msg.str();
           msg.d = msg.diggest();
            node.SendAll(msg);
        }
            break;
        case Prepare: {
            msg.msg_type = Message::PREPARE;
            msg.i = node.GetNodeAdd();
            node.SendPrepare(msg);



        }
            break;
        case Commit:{
            accepeted_prepares++;
            //TODO：如果验证prepare消息正确，则
            msg.msg_type = Message::COMMIT;
            node.SendCommit(msg);



        }
            break;


        case Reply:
        {
            accepeted_commits++;
            if (accepeted_commits > 2 * Num_Node)
            {
                msg.msg_type = Message::Done;
                node.SendMsg(msg.c,msg);
            }


        }
            break;

        case Reset:
        {
            Message::v++;
            accepeted_prepares = 0;
            accepeted_commits = 0;
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
        case (Message::Done):
        {
            _state = Reset;
        }
            break;

    }

}


