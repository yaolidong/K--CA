//
// Created by 姚黎东 on 2021/4/19.
//
#include "Cache.h"


Cache::Cache(){
    _num = 0;
    _store = 0;
}

void Cache::AddTranslation(Translation & tr) {
    _num ++;
    std::cout<<"The Cache has "<<_num <<" translations ."<<std::endl;
    _store += tr.GetTSize();
    _trans_cache.emplace_back(tr);
}

void Cache::ShowCacheStore() const{
    std::cout<<"The Cache has "<<_num <<" translations ."<<std::endl;
    std::cout<<"The Cache :" ;
    if(_store/1024/1024 >=1)
    {
        std::cout << _store/1024/1024<< " M "<< std::endl;
    }
    else {
        std::cout << _store/1024 << " K " << std::endl;
    }
}

std::vector <Translation> Cache::GetTransCache() {
    return  _trans_cache;
}
