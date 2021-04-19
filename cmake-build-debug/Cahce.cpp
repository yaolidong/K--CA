//
// Created by 姚黎东 on 2021/4/19.
//
#include "Cache.h"

void Cache::AddTranslation(Translation tr) {
    _num ++;
    std::cout<<"The Cache has "<<_num <<" translations ."<<std::endl;
    _store += tr.GetTSize();
    tr.ModTHash();
    _trans_cache.emplace_back(tr);
}

uint64_t Cache::ShowCacheStore() const{
    std::cout<<"The Cache :" ;
    if(_store/1024/1024 >=1)
    {
        std::cout << _store/1024/1024<< " M "<< std::endl;
    }
    else {
        std::cout << _store/1024 << " K " << std::endl;
    }

}