//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_SEALER_H
#define K_CA_SEALER_H

#include "Cache.h"

class Sealer{
public:
    Sealer(Cache & ca);
    bool IsCacheEmpty() const;
    std::string CaculateMerkRoot() const;
private:
    std::string merkle_root;

};
#endif //K_CA_SEALER_H
