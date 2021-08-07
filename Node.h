//
// Created by 姚黎东 on 2021/4/16.
//

#ifndef K_CA_NODE_H
#define K_CA_NODE_H

#include <vector>
#include <map>
#include <iostream>

#include "Network.h"
#include "Sealer.h"
#include "ViewState.h"

//客户端
class Client : public NetworkNode {
    std::map<std::string ,int> accepted_reply;
public:
    Client();
    void OnRecvMsg(network_address_t src,Message msg) override;
    void OnRecvBk(Block bk) override;
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

        key_t();
        explicit key_t(Message &msg);
        key_t(network_address_t c,std::string o, time_t t, std::string d);
        key_t(const key_t &kt);
        bool operator<(const key_t &k1) const;
        key_t &operator=(const key_t &k2) ;
    };
    std::map<key_t ,ViewState> _log;
    size_t _seq = 0;
    size_t _view = 0;

public:

    size_t GetTransNum();
    Blockchain GetBlockChain();
    void TransToCache(Message &msg);
    Block SealTrans();
    network_address_t  GetNodeAdd();
    void SetAllNodes(const std::vector<std::unique_ptr<Node>> & allNodes);
    void OnRecvMsg(network_address_t src, Message msg) override;
    void OnRecvBk(Block bk) override;
    void GetOutBk();
    void SendAll(Message &msg);
    void SendBlock(Block &bk);
    void SendUnpack(Message &msg);



};
#endif //K_CA_NODE_H
