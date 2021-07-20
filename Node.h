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
    size_t accepeted_reply = 0;
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

        key_t(Message &msg);
        key_t(const key_t &kt);
        //bool operator>(const key_t &k1,const key_t &k2) const;
        bool operator<(const key_t &k1) const;
        key_t &operator=(const key_t &k2) ;
    };

    //std::map<key_t ,ViewState> _log;
    std::map<int,std::string> _log;
    size_t _seq = 0;
    size_t _view = 0;

    size_t accepted_prepared = 0;
    size_t accepted_committed = 0;

public:

//    void AddTransNum();
    size_t GetTransNum();

    bool TransQueueEmpty();
    void TransToCache(Message &msg);
    void SealTrans();
    network_address_t  GetNodeAdd();
    void SendPrepare(Message &msg);
    void SendCommit(Message &msg);
    void LogMessage(Message &msg);
    size_t GetAccPre() const;
    size_t GetAccCom() const;
    void ClearAccPre();
    void ClearAccCom();
    void SetAllNodes(const std::vector<std::unique_ptr<Node>> & allNodes);
    void OnRecvMsg(network_address_t src, Message &msg) override;//检查是否收到过该节点的信息
    void SendAll(Message &msg);//转发给所有节点



};
#endif //K_CA_NODE_H
