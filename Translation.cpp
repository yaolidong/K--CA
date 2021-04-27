//
// Created by 姚黎东 on 2021/4/19.
//
#include "Translation.h"
#include "sha256.h"
#include <sstream>
#include <ctime>


std::string Translation::CalculateTransHash() const {
    std::stringstream st;
    st << _tIndex << sender <<reciever << _tTime;//TODO:参数增加交易发送方和接收方数据
    return sha256(st.str());

}

Translation::Translation() {
    sender = "yao";
    reciever = "hu";
    _tIndex++;
    _tTime = time(nullptr);
    _tSize = 100 * 1024;
    _tHash = CalculateTransHash();
}
uint64_t Translation::GetTSize() {
    return _tSize;
}

std::string Translation::GetTHash()  {
    return _tHash;
}

Translation::Translation(std::string sen, std::string rec) {
    sender = sen;
    reciever = rec;
    _tIndex++;
    _tTime = time(nullptr);
    _tSize = 100 * 1024;
    _tHash = CalculateTransHash();
}



