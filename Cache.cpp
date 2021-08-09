
#include "Cache.h"




void Cache::AddTranslation(Message & tr) {
    _trans_que.push(tr);
}


std::queue<Message> Cache::GetTransQueue() {
    return _trans_que;
}

void Cache::PopTransQueue() {
    _trans_que.pop();
}
