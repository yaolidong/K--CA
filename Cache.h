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
    void AddTranslation (Message & tr);
    std::queue<Message>GetTransQueue();
    void PopTransQueue();

private:
    std::queue<Message> _trans_que;

};
#endif //K_CA_CACHE_H
