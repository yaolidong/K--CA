//
// Created by 姚黎东 on 2021/4/19.
//
#include "Cache.h"
#include <iostream>




void Cache::AddTranslation(Message & tr) {

    _trans_que.push(tr);
}


std::queue<Message> Cache::GetTransQueue() {
    return _trans_que;
}
