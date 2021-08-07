//______________________________________________________________
//_            File  Name   : Blockchain.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Thu 15 Apr 2021 03:30:36 PM CST
//______________________________________________________________

#include "Blockchain.h"

Blockchain::Blockchain()
{
	_bChain.emplace_back(Block(_bIndex,"Genesis Block", ""));
}

Block Blockchain::AddBlock(Block bNew)
{
	bNew.bPrevHash = GetLastBlock().GetHash();
        bNew._bHash = bNew.CalculateBlockHash();
	_bChain.push_back(bNew);
        return bNew;
}

Block Blockchain::GetLastBlock() const
{
	return _bChain.back();//返回向量中的最后一个元素
}

size_t Blockchain::GetBlockIndex() const{
    return _bIndex;
}

void Blockchain::BlockIndexAdd() {
    _bIndex++;

}
