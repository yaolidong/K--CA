#include <sstream>

#include "Message.h"

Message::Message(msg_type_t _type):msg_type(_type) {
}

std::string Message::diggest() {
    std::stringstream ss;
    ss << o << t << c;
    return sha256(ss.str());
}

std::string Message::str() const{
    std::stringstream ss;
    ss
        <<"o="<<o
        <<", t="<<t
        <<", v="<<v
        <<", n="<<n
        <<", c="<<c
        <<", d="<<d
        <<")";
    return ss.str();
}

