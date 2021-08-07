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
        std::cout << "添加第" << bc.GetBlockIndex()<< "个区块"<<std::endl;
        std::cout << "区块merkle_root:" << merkle_root<<std::endl;
        static clock_t start;
        //static clock_t end;
        if(bc.GetBlockIndex() == 1)
        {
          start = clock();
        }
        if (bc.GetBlockIndex() == 10)
        {
          auto duration = (double )(clock()-start)/CLOCKS_PER_SEC;
          std::cout<< "TPS: "<< NUMOFTRANS/duration << std::endl;
        }
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



