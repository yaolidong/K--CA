//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_CACHE_H
#define K_CA_CACHE_H
#include <vector>
#include "Translation.h"


class Cache{
public:
    Cache();
    void AddTranslation (Translation & tr);
    void ShowCacheStore() const;
    std::vector<Translation> GetTransCache();
private:
    uint32_t _num;//缓存池中的交易数量
    std::vector<Translation> _trans_cache;
    uint64_t _store;//交易所占空间

};
#endif //K_CA_CACHE_H
