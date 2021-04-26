//
// Created by 姚黎东 on 2021/4/17.
//

#ifndef K_CA_TRANSLATION_H
#define K_CA_TRANSLATION_H
#include <cstdint>
#include "Node.h"
class Translation
{
public:
    Translation();
    uint64_t GetTSize() const;
    std::string GetTHash() const;
private:
    static uint32_t _tIndex ;//交易编号
    time_t _tTime;//交易时间
    uint64_t _tSize;
    std::string _tHash;//交易哈希值
    std::string CalculateTransHash() const;//计算交易哈希
};

#endif //K_CA_TRANSLATION_H
