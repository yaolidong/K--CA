#include <cstdint>
#include <vector>
#include "Block.h"
using namespace std;

class Blockchain(){
public:
	Blockchain();
	void AddBlock(Block bNew);
private:
	uint32_t _mDifficulty;
	vector<Block> _bChain;

	Block _GetLastBlock() const;

};

