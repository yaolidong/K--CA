//______________________________________________________________
//_            File  Name   : main.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Thu 15 Apr 2021 03:36:15 PM CST
//______________________________________________________________

#include "Blockchain.h"
#define Max 400

int main()
{
    Cache ca = Cache();
    Sealer sl = Sealer();
	Blockchain bChain = Blockchain();
    uint32_t i = 1;
    uint32_t trans_sender = 0;
    uint32_t trans_receiver = 1;
	while(1)
    {
	    Translation tra[Max];
	    while( trans_sender < 400)
        {
	        tra[trans_sender] = Translation(to_string(trans_sender), to_string(trans_receiver));
	        ca.AddTranslation(tra[trans_sender]);
	        trans_receiver++;
	        trans_sender ++;
        }
        ca.ShowCacheStore();
        sl.CalculateMerkRoot(ca);
        bChain.AddBlock(Block(i++,"blockData",sl.GetMerkleRoot()));
    }




	//cout<<"Mining block 3..."<<endl;
	//bChain.AddBlock(Block(3,"Block 3 Data"));
	return 0;
}
