#include "sha256.h"
#include "Block.h"
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

Block::Block(uint32_t bIndexIn,const string & bDataIn, string merkroot):_bIndex(bIndexIn),_bData(bDataIn){
    merkle_root = merkroot;
	_bNonce = -1;
	_cTime = time(nullptr);
}

string Block::GetHash()
{
	return _bHash;
}

uint32_t Block::GetBIndex() {
    return _bIndex++;
}

 string Block::CalculateBlockHash()
{
	stringstream ss;
	ss<< _bIndex << _cTime << _bData << _bNonce << bPrevHash << merkle_root;
	return sha256(ss.str());

}
string Block::GetMerkleRoot() const {
    return merkle_root;
}
Block::Block() =default;
