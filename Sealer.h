//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_SEALER_H
#define K_CA_SEALER_H

#include "Cache.h"
#include "Blockchain.h"

class Sealer{
public:
    Sealer();
     bool IsCacheEmpty(Cache & ca) ;
    void CalculateMerkRoot(Cache & ca, Blockchain & bc);
    Block Upchain(Blockchain & bc);
    size_t GetTransCount() const;
    void ReduceCount();

private:
    std::string str;
    size_t trans_count = 0;
    std::string merkle_root;
};
#endif //K_CA_SEALER_H
