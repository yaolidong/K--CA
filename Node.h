//
// Created by 姚黎东 on 2021/4/16.
//

#ifndef K_CA_NODE_H
#define K_CA_NODE_H

#include <vector>
#include <map>
#include <iostream>



#include "ViewState.h"
#include "Network.h"
#include "Pbft.h"

//客户端
class Client : public NetworkNode {
public:
    void OnRecvMsg(network_address_t src,Message msg) override;
    void SendRequest(network_address_t dst, std::string o);
};


//共识节点
class Node : public NetworkNode {
    std::vector<network_address_t> _otherNodes;
    struct key_t {
        network_address_t c;//客户端标识
        std::string o;//具体操作
        time_t t;
    };
public:
    network_address_t  GetNodeAdd();
    void SendPrepare(Message msg);
    void SendCommit(Message msg);
    void SetAllNodes(const std::vector<std::unique_ptr<Node>> & allNodes);
    void OnRecvMsg(network_address_t src, Message msg) override;//检查是否收到过该节点的信息
    void SendAll(Message msg);//转发给所有节点



};
#endif //K_CA_NODE_H
