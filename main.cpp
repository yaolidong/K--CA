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

	cout<<"Mining block 1..."<<endl;
	bChain.AddBlock(Block(1,"Block 1 Data"));

	cout<<"Mining block 2..."<<endl;
	bChain.AddBlock(Block(2,"Block 2 Data"));

	cout<<"Mining block 3..."<<endl;
	bChain.AddBlock(Block(3,"Block 3 Data"));
	return 0;
}
