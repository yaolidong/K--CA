#include "Node.h"
using std::cout;
using std::endl;


std::mutex console_mutex;

int main()
{
    using namespace std::chrono;
    auto start = system_clock::now();

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
        Message request(Message::REQUEST);
        request.t = std::time(nullptr);
        request.o = str;
        request.c = request.i = client.GetNodeAddress();
        request.d = request.diggest();
        request.m = request.str();
        for(int j = 0; j < Num_Node; j++)
        {
          client.SendRequest(nodes[j]->GetNodeAddress(),request);
        }
    }
    while (!Network::instance().Empty())
        std::this_thread::sleep_for(1s);

    duration<double> diff = system_clock::now() - start;
    cout<<"elapsed: " << diff.count() << " seconds" <<endl;
    cout<<"TPS: " << NUMOFTRANS/diff.count()<<endl;

	return 0;
}
