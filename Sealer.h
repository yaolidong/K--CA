//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_SEALER_H
#define K_CA_SEALER_H

#include "Cache.h"

class Sealer{
public:
    Sealer();
    static bool IsCacheEmpty(Cache & ca) ;
    void CalculateMerkRoot(Cache & ca);
    std::string GetMerkleRoot();
private:
    std::string merkle_root;
};
#endif //K_CA_SEALER_H
