//
// Created by 姚黎东 on 2021/4/19.
//

#ifndef K_CA_CACHE_H
#define K_CA_CACHE_H
#include <vector>
#include "Translation.h"
#include "sha256.h"

class Cache{
public:
    uint32_t _num = 0;//缓存池中的交易数量
    void AddTranslation (Translation tr);
private:
    std::vector<Translation> _trans_cache;
    uint64_t _store = 0;//交易所占空间
    uint64_t  ShowCacheStore() const;
};
#endif //K_CA_CACHE_H
