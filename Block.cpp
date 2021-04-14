//______________________________________________________________
//_            File  Name   : Block.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :三  4/14 17:15:59 2021
//______________________________________________________________
#include <bits/stdint-uintn.h>
#include <cstdint>
#include <string>
#include <vector>
#include "sha256.h"
#include "Block.h"

using namespace std;

class BlockChain{
public:
	BlockChain();
	void AddBlock(Block bNew);
private:
	uint32_t _mDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;

};

Block::Block(uint32_t bIndexIn,const string & bDataIn):_bIndex(bIndexIn),_bData(bDataIn){
	bNonce = -1;
	_cTime = time(nullptr);
}


string GetHash()
{
	return _bHash;
}
