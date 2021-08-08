//
// Created by 姚黎东 on 2021/4/19.
//
#include <sstream>
#include <string>
#include "Sealer.h"
#include "sha256.h"


Sealer::Sealer() {
    merkle_root = "";
}
bool Sealer::IsCacheEmpty(Cache & ca) {
    return ca.GetTransQueue().empty();
}

void  Sealer::CalculateMerkRoot(Cache & ca,Blockchain & bc)  {
    if(!IsCacheEmpty(ca))
    {
        trans_count++;
        //std::cout << "交易池中的交易数："<<trans_count << std::endl;
        std::stringstream ss;
        str = ca.GetTransQueue().front().diggest();
        ca.PopTransQueue();
        ss << merkle_root << str;
        merkle_root = sha256(ss.str());
    }

}

Block Sealer::Upchain(Blockchain & bc) {
        Block bNew = Block(bc.GetBlockIndex(),"",merkle_root);
        bNew = bc.AddBlock(bNew);
        bc.BlockIndexAdd();
        return bNew;
}

size_t Sealer::GetTransCount() const{
    return trans_count;
}

void Sealer::ReduceCount() {
    trans_count -= 400;

}



