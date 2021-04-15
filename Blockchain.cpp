//______________________________________________________________
//_            File  Name   : Blockchain.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Thu 15 Apr 2021 03:30:36 PM CST
//______________________________________________________________

#include "Blockchain.h"

Blockchain::Blockchain()
{
	_bChain.emplace_back(Block(0,"Genesis Block"));
	_mDifficulty = 3;
}

void Blockchain::AddBlock(Block bNew)
{
	bNew.bPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_mDifficulty);
	_bChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
	return _bChain.back();//返回向量中的最后一个元素
}
