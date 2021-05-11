//______________________________________________________________
//_            File  Name   : pbft.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Fri 16 Apr 2021 11:55:54 AM CST
//______________________________________________________________



//pbft实现
#include "Pbft.h"



std::mutex console_mutex;

int main()
{
    Client client;
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < Num_Node; i++)
    {
        nodes.push_back(std::make_unique<Node>());
    }
    for (auto & node : nodes)
    {
        node->SetAllNodes(nodes);
    }

    client.SendRequest(nodes[0]->GetNodeAddress(),"Translations");
    while (!Network::instance().Empty())
        std::this_thread::sleep_for(1s);

	return 0;
}
