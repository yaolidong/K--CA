//
// Created by 姚黎东 on 2021/4/16.
//

#include "FiniteStateMachine.h"
#include "Node.h"

void ViewState::handle_message(Message msg, Node &node) {
    switch (state_) {
        case No_State:
            msg.o = "Translation"
            msg.t = time(nullptr);
            msg.c = node.GetNodeAddress();
            msg.d = msg.diggest();
            msg.m = msg.str();

            break;
        case Prepared:
            msg.n++;
            msg.v++;

            break;
        case Committed:
            ;
            break;
        case Replyed:
            ;
            break;
        default:
            std::cout<<"Your Entered Message is not Standard!"<<std::endl;
    }

    // if (prepared) {
    //     for (auto addr : other_nodes_) {
    //         node.send_commit();
    //     }
    // }
    //
    // if (committed_local) {
    //     node.execute_operation();
    //     node.send_reply();
    // }

}