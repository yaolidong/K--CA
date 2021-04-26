//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_SEALER_H
#define K_CA_SEALER_H

#include "Cache.h"

class Sealer{
public:
    Sealer(Cache & ca);
    static bool IsCacheEmpty(Cache & ca) ;
    std::string CalculateMerkRoot(Cache & ca);
    std::string GetMerkleRoot() const;
private:
    std::string merkle_root;
};
#endif //K_CA_SEALER_H
