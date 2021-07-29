//______________________________________________________________
//_            File  Name   : pbft.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Fri 16 Apr 2021 11:55:54 AM CST
//______________________________________________________________



//pbft实现
#include "Node.h"
using std::cout;
using std::endl;


std::mutex console_mutex;

int main()
{

    using namespace std::chrono;
    auto start = system_clock::now();

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
    for(int i = 0; i < 1200; i++)
    {
        std::string str;
        str = "Test"+ to_string(i);
        client.SendRequest(nodes[0]->GetNodeAddress(), str);
    }



    while (!Network::instance().Empty())
        std::this_thread::sleep_for(1s);


    duration<double> diff = system_clock::now() - start;
    cout<<"elapsed: " << diff.count() << "seconds" <<endl;

//    std::this_thread::sleep_for(5s);


	return 0;
}
