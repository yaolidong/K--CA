//
// Created by 姚黎东 on 2021/4/19.
//
#include <sstream>
#include <string>
#include <iostream>
#include "Sealer.h"
#include "sha256.h"


Sealer::Sealer() {
    merkle_root = "";
}
bool Sealer::IsCacheEmpty(Cache & ca) {
    return ca.GetTransQueue().empty();
}

void Sealer::CalculateMerkRoot(Cache & ca)  {
    int counter = 0;
    std::string str;
    std::queue<Translation>  ref_que = ca.GetTransQueue();
    while (counter < 400 && !IsCacheEmpty(ca))
    {
            std::stringstream ss;
//            std::string str = ca.GetTransCache().begin()->GetTHash();
//            ca.GetTransCache().erase(ca.GetTransCache().begin()+counter);
            str = ref_que.front().GetTHash();
            ref_que.pop();
            std::cout<<ref_que.front().GetTHash()<<std::endl;
//            std::cout<<"The queue has "<<ref_que.size()<<std::endl;
            ss << merkle_root << str;
            merkle_root = sha256(ss.str());
            counter++;
    }
}

std::string Sealer::GetMerkleRoot() {
    return merkle_root;
}

