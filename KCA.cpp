#include "Node.h"
using std::cout;
using std::endl;


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
    for(int i = 0; i < NUMOFTRANS; i++)
    {
        std::string str;
        str = "Test"+ to_string(i);
        for(int j = 0; j < Num_Node; j++)
        {
          client.SendRequest(nodes[j]->GetNodeAddress(), str);
        }
    }
    while (!Network::instance().Empty())
        std::this_thread::sleep_for(1s);
	return 0;
}
