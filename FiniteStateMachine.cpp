//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"


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


ViewState ViewState::GetState(Message msg) {
    ViewState vs;
    switch(msg.msg_type){
        case Message::REQUEST:
        {}
            break;
        case Message::PREPARE:
        {}
            break;

    }


    return vs;
}

