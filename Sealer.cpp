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
        std::stringstream ss;
        str = ca.GetTransQueue().front().diggest();
        ca.GetTransQueue().pop();
        ss << merkle_root << str;
        merkle_root = sha256(ss.str());


    }

}

void Sealer::Upchain(Blockchain & bc) {

        Block bnew = Block(bc.GetBlockIndex(),"",merkle_root);
        bc.AddBlock(bnew);
        bc.BlockIndexAdd();

}

size_t Sealer::GetTransCount() {
    return trans_count;
}

void Sealer::ReduceCount() {
    trans_count -= 400;

}



