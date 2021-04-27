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
    Translation(std::string sen, std::string rec);
    uint64_t GetTSize();
    std::string GetTHash();
private:
    uint32_t _tIndex ;//交易编号
    std::string sender;
    std::string reciever;
    time_t _tTime;//交易时间
    uint64_t _tSize;
    std::string _tHash;//交易哈希值
    std::string CalculateTransHash() const;//计算交易哈希
};

#endif //K_CA_TRANSLATION_H
