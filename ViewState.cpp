//
// Created by 姚黎东 on 2021/4/16.
//

#include "ViewState.h"
#include "Node.h"

ViewState::ViewState() {
        _state = SEND_TRANS;
}
ViewState::ViewState(const Message& msg) {
    if(msg.msg_type == Message::REQUEST)
        _state = SEND_TRANS;
    else if(msg.msg_type == Message::CONFIRM)
        _state = COMFIRM_TRANS;
}

ViewState::ViewState(const ViewState &vt) {
    _state = vt._state;
    accepted_confirm= vt.accepted_confirm;
}
ViewState & ViewState::operator=(const ViewState &vt) {
    if (this == &vt)
        return *this;
    _state = vt._state;
    accepted_confirm = vt.accepted_confirm;
    return *this;
}
void ViewState::handle_message(Message msg, Node & node) {
  switch (_state) {
  case SEND_TRANS: {
    // TODO：主节点验证客户端请求消息签名是否正确，如果正确，则
    msg.msg_type = Message::CONFIRM;
    msg.i = node.GetNodeAdd();
    msg.n = node.GetTransNum();
    node.SendAll(msg);
    if (node.GetNodeAdd() == 2)
      _state = COMFIRM_TRANS;
    else {
      //std::cout << "节点：" << node.GetNodeAdd() << "进入等待状态。"
                //<< std::endl;
      _state = WAIT_BLOCK;
    }
  }
  break;

  case WAIT_BLOCK:
  {
    if (msg.msg_type == Message::DONE)
    {
      //std::cout << "节点：" <<node.GetNodeAdd() << "接收到区块信息。" << std::endl;
      _state = SEND_BLOCK;
    }
  }
  break;
  case COMFIRM_TRANS: {
    // TODO：副本节点验证
    //  a. 主节点PRE-PREPARE消息签名是否正确。
    //  b. 当前副本节点是否已经收到了一条在同一v下并且编号也是n，但是签名不同的PRE-PREPARE信息。
    //  c. d与m的摘要是否一致。
    //  d. n是否在区间[h, H]内。
    //  如果正确，则

    if (msg.msg_type == Message::CONFIRM) {
      accepted_confirm++;
    }
    if (accepted_confirm == k_value) // TODO:K_CA
    {
        //std::cout << "节点：" << node.GetNodeAdd() << " 达到k确认！"
                  //<< std::endl;
        node.TransToCache(msg);
        node.SealTrans();
        //std::cout << "节点：" << node.GetNodeAdd() << "打包区块。" << std::endl;
        _state = SEND_BLOCK;
        node.SendBlock(msg);
    }
  }
  break;

  case SEND_BLOCK: {
    if (msg.msg_type == Message::CONFIRM)
    {
      //std::cout << "节点：" << node.GetNodeAdd() << "已k确认，不再接收确认信息。" << std::endl;
    }
    // TODO:复制区块
    if (msg.msg_type == Message::DONE)
      std::cout << "节点：" << node.GetNodeAdd() << " 打包区块。" << std::endl;
    }
    break;
  }
}








