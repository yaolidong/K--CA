//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_CACHE_H
#define K_CA_CACHE_H
//#include <vector>
#include <queue>
#include "Message.h"


class Cache{
public:
//    Cache();
    void AddTranslation (Message & tr);
   // void ShowCacheStore();
//    std::vector<Translation> GetTransCache();
    std::queue<Message>GetTransQueue();
private:
    //uint32_t _num;//缓存池中的交易数量
   //std::vector<Translation> _trans_cache;
    std::queue<Message> _trans_que;
    //uint64_t _store;//交易所占空间

};
#endif //K_CA_CACHE_H
