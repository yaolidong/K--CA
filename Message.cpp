//______________________________________________________________
//_            File  Name   : message.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Fri 16 Apr 2021 12:13:18 PM CST
//______________________________________________________________

#include <sstream>
#include <ctime>
#include "sha256.h"
#include "Message.h"


Message::Message(msg_type_t _type):msg_type(_type) {
    }




//消息摘要：具体操作+时间戳+客户端标识（网络地址）
std::string Message::diggest() {
    std::stringstream ss;
    ss << o << t << c;
    return sha256(ss.str());
}
//消息内容
std::string Message::str() const{
    std::stringstream ss;
    ss<<"Message("<<"msg_type=";
    switch (msg_type) {
        case REQUEST: ss<<"REQUEST";break;
        case PRE_PREPARE: ss<<"PRE_REQUEST";break;
        case PREPARE: ss<<"PREPARE";break;
        case COMMIT: ss<<"COMMIT";break;
        case REPLY: ss<<"REPLY";break;
    }
    ss
        <<", o="<<o
        <<", t="<<t
        <<", v="<<v
        <<", d="<<d
        <<", n="<<n
        <<", c="<<c
        <<")";
    return ss.str();
}

