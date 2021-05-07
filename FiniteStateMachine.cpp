//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"

void ViewState::handle_message(Message msg, Node &node) {
    switch (msg.msg_type) {
        case Message::REQUEST:
            msg.o = "Translation"
            msg.t = time(nullptr);
            msg.c = node.GetNodeAddress();
            msg.d = msg.diggest();
            msg.m = msg.str();

            break;
        case Message::PRE_PREPARE:
            msg.n++;
            msg.v++;

            break;
        case Message::PREPARE:
            ;
            break;
        case Message::COMMIT:
            ;
            break;
        case Message::REPLY:
            ;
            break;
        default:
            std::cout<<"Your Entered Message is not Standard!"<<std::endl;
    }

}