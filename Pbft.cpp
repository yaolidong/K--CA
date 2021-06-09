//______________________________________________________________
//_            File  Name   : pbft.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Fri 16 Apr 2021 11:55:54 AM CST
//______________________________________________________________



//pbft实现
#include "Node.h"
#include "Blockchain.h"
#define Max 400

std::mutex console_mutex;

int main()
{
    Cache ca = Cache();
    Sealer sl = Sealer();
    Blockchain bChain = Blockchain();
    uint32_t num_block = 1;
    uint32_t trans_sender = 0;
    uint32_t trans_receiver = 1;

    Translation tra[Max];
    while( trans_sender < 400)
    {
        tra[trans_sender] = Translation(to_string(trans_sender), to_string(trans_receiver));
        ca.AddTranslation(tra[trans_sender]);
        ca.ShowCacheStore();
        trans_receiver++;
        trans_sender ++;
    }
    std::cout << "计算Merkleroot"<<std::endl;
    sl.CalculateMerkRoot(ca);
    std::cout << "添加区块"<<std::endl;
    Block bk = Block(num_block++,"blockData",sl.GetMerkleRoot());
    bChain.AddBlock(bk);

    Client client;
    //创建节点
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < Num_Node; i++)
    {
        nodes.push_back(std::make_unique<Node>());
    }

    //P2P网络
    for (auto & node : nodes)
    {
        node->SetAllNodes(nodes);
    }

    //客户端发送Request请求
    client.SendRequest(nodes[0]->GetNodeAddress(),"Translations");
    while (!Network::instance().Empty())
        std::this_thread::sleep_for(1s);


	return 0;
}
