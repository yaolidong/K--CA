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
#include "Sealer.h"

//客户端
class Client : public NetworkNode {
    std::map<std::string ,int> accepted_reply;
public:
    Client();
    void OnRecvMsg(network_address_t src,Message &msg) override;
    void SendRequest(network_address_t dst, std::string o);
};


//共识节点
class Node : public NetworkNode {

    Cache ca = Cache();
    Sealer sl = Sealer();
    Blockchain bChain = Blockchain();
    std::vector<network_address_t> _otherNodes;



    struct key_t {
        network_address_t c;//客户端标识
        std::string o;//具体操作
        time_t t;
        std::string d;

        explicit key_t(Message &msg);
        key_t(const key_t &kt);
        bool operator<(const key_t &k1) const;
        key_t &operator=(const key_t &k2) ;
    };

    std::map<key_t ,ViewState> _log;
    //std::map<std::string ,ViewState> _log
    size_t _seq = 0;
    size_t _view = 0;

public:

    size_t GetTransNum();
    bool TransQueueEmpty();
    void TransToCache(Message &msg);
    void SealTrans();
    network_address_t  GetNodeAdd();
    void SendPrepare(Message &msg);
    void SendCommit(Message &msg);
    //void GetState( Message & msg);
    void SendMessage(network_address_t dst,Message msg);
    void SetAllNodes(const std::vector<std::unique_ptr<Node>> & allNodes);
    void OnRecvMsg(network_address_t src, Message &msg) override;//检查是否收到过该节点的信息
    void SendAll(Message &msg);//转发给所有节点



};
#endif //K_CA_NODE_H
