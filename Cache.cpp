//
// Created by 姚黎东 on 2021/4/19.
//
#include "Cache.h"
#include <iostream>


Cache::Cache(){
    //_store = 0;
}

void Cache::AddTranslation(Message & tr) {

    //_store += tr.GetTSize();
    _trans_que.push(tr);
   std::cout <<" The Cache : " << _trans_que.size() <<std::endl;
    /* std::cout <<" 具体内容 ： " << tr.o <<std::endl;
    std::cout <<" Hash ： " << tr.diggest()<<std::endl;
    std::cout << std::endl;*/
//    _trans_cache.emplace_back(tr);
}

/*void Cache::ShowCacheStore(){
    std::cout<<"The Cache has "<<_num <<" translations ."<<std::endl;
    std::cout<<"The Cache :" ;
    if(_store/1024/1024 >=1)
    {
        std::cout << _store/1024/1024<< " M "<< std::endl;
    }
    else {
        std::cout << _store/1024 << " K " << std::endl;
    }
}*/

//std::vector <Translation> Cache::GetTransCache() {
//    return  _trans_cache;
//}

std::queue<Message> Cache::GetTransQueue() {
    return _trans_que;
}
