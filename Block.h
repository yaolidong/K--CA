#include <cstdint>
#include <iostream>
using namespace std;

class Block{
public:
	string bPrevHash;//上一个区块的哈希值
	Block(u_int32_t bIndexIn, const string & bDataIn);
	string GetHash();
	void MineBlock(uint32_t mDifficulty);
private:
	uint32_t _bIndex;//区块索引
	int64_t bNonce;//区块随机数
	string _bData;//区块数据
	time_t _cTime;//区块生成时间

	string _CalculateHash() const;//计算区块哈希值
};

