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
    return ca.GetTransCache().empty();
}

std::string Sealer::CalculateMerkRoot(Cache & ca)  {
    int counter = 0;
    while (counter < 400 && !IsCacheEmpty(ca))
    {
            std::stringstream ss;
            std::string str = ca.GetTransCache().front().GetTHash();
            ca.GetTransCache().erase(ca.GetTransCache().begin());
            ss << merkle_root << str;
            merkle_root = sha256(ss.str());
            counter++;
    }
    return merkle_root;
}

std::string Sealer::GetMerkleRoot() const {
    return merkle_root;
}

