//
// Created by 姚黎东 on 2021/4/17.
//

#ifndef K_CA_TRANSLATION_H
#define K_CA_TRANSLATION_H
#include <cstdint>
#include <string>

class Translation
{
public:
    Translation();
    string GetTHash();
private:
    uint32_t _tIndex;//交易编号
    string _tHash;//交易哈希值
    time_t _tTime;//交易时间

    string _CalculateTransHash() const;//计算交易哈希
};

#endif //K_CA_TRANSLATION_H
