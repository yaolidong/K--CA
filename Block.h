#ifndef BLOCK_H
#define BLOCK_H
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

//区块索引
class Block{
public:
	string bPrevHash;//上一个区块的哈希值
        string _bHash;//区块哈希值
        Block();
	Block(uint32_t bIndexIn, const string & bDataIn,string merkroot);
	string GetHash();
	uint32_t GetBIndex();
        string GetMerkleRoot() const;
        string CalculateBlockHash() ;//计算区块哈希值


private:
        string merkle_root;//merkle_root
	int64_t _bNonce;//区块序号
	string _bData;//区块数据
	time_t _cTime;//区块生成时间
        uint32_t _bIndex = 0;
};
#endif

