//
// Created by 姚黎东 on 2021/6/30.
//

#ifndef K_CA_BLOCKCHAIN_H
#define K_CA_BLOCKCHAIN_H

#include <vector>
#include "Block.h"
using namespace std;

class Blockchain{
public:
    Blockchain();
    void AddBlock(Block bNew);
private:
    uint32_t _mDifficulty;
    vector<Block> _bChain;

    Block GetLastBlock() const;

};

#endif //K_CA_BLOCKCHAIN_H
