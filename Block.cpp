//______________________________________________________________
//_            File  Name   : Block.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :三  4/14 17:15:59 2021
//______________________________________________________________

#include "sha256.h" 
#include "Block.h"
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

Block::Block(uint32_t bIndexIn,const string & bDataIn):_bIndex(bIndexIn),_bData(bDataIn){
	_bNonce = -1;
	_cTime = time(nullptr);
	char * localTime =ctime(&_cTime) ;
	cout<<"The Block "<<bIndexIn<<" Create Time is "<<localTime<<endl;
}

string Block::GetHash()
{
	return _bHash;
}



void Block::MineBlock(uint32_t mDifficulty)
{
	char cstr[mDifficulty +1];
	for (uint32_t i = 0; i < mDifficulty; i++)
	{
		cstr[i] = '0';
	}
	cstr[mDifficulty+1] = '\0';

	string str(cstr);

	do
	{
		_bNonce++;
		_bHash = _CalculateBlockHash();
	}
	while
		(_bHash.substr(0,mDifficulty) !=str);//

	cout<<"Block mined: "<<_bHash<<endl;

}

inline string Block::_CalculateBlockHash() const
{
	stringstream ss;
	ss<< _bIndex<<_cTime<<_bData<<_bNonce<<bPrevHash;
	return sha256(ss.str());

}
