//______________________________________________________________
//_            File  Name   : main.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Thu 15 Apr 2021 03:36:15 PM CST
//______________________________________________________________

#include "Blockchain.h"

int main()
{
	Blockchain bChain = Blockchain();

    uint32_t i = 1;
	while(1)
    {
        bChain.AddBlock(Block(i++,"blockData"));
    }




	//cout<<"Mining block 3..."<<endl;
	//bChain.AddBlock(Block(3,"Block 3 Data"));
	return 0;
}
