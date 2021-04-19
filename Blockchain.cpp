//______________________________________________________________
//_            File  Name   : Blockchain.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Thu 15 Apr 2021 03:30:36 PM CST
//______________________________________________________________

#include "Blockchain.h"

Blockchain::Blockchain()
{
	_bChain.emplace_back(Block(0,"Genesis Block"));//emplace_back 和push_back作用相同，但更节省资源
	_mDifficulty = 5;//TODO:这里设置为固定难度，KCA实际要求随交易量变化，
}

void Blockchain::AddBlock(Block bNew)
{
    time_t now = time(nullptr);

    cout<<"Mining Block "<<bNew.GetBIndex()<<" ..."<<endl;
	bNew.bPrevHash = GetLastBlock().GetHash();
	bNew.MineBlock(_mDifficulty);
	char * localTime = ctime(& now);
    cout<<"The Block "<<bNew.GetBIndex()<<" Create Time is "<< localTime <<endl;
    cout<<endl;
	_bChain.push_back(bNew);



}

Block Blockchain::GetLastBlock() const
{
	return _bChain.back();//返回向量中的最后一个元素
}
