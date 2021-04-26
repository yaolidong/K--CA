#include <cstdint>
#include <iostream>
#include <string>
#include "Sealer.h"
using namespace std;

//区块索引
class Block{
public:
	string bPrevHash;//上一个区块的哈希值
	Block(uint32_t bIndexIn, const string & bDataIn);
	string GetHash();
    string GetMerkRoot(Sealer & sl);
	uint32_t GetBIndex() const;
	void MineBlock(uint32_t mDifficulty);

private:
    string merkle_root;//merkle_root
	int64_t _bNonce;//区块随机数
	string _bData;//区块数据
	string _bHash;//区块哈希值
	time_t _cTime;//区块生成时间

	string CalculateBlockHash() const;//计算区块哈希值
    uint32_t _bIndex ;
};

