//______________________________________________________________
//_            File  Name   : message.cpp
//_            Author       : Yaolidong
//_            My   email   :yao401405972@gmail.com
//_            Created Time :Fri 16 Apr 2021 12:13:18 PM CST
//______________________________________________________________

#include <sstream>
#include "sha256.h"
#include "Message.h"


//size_t Message::n = 0;




Message::Message(msg_type_t _type):msg_type(_type) {
}

Message::Message(const Message &m1) {
  msg_type = m1.msg_type;
  o = m1.o;
  t = m1.t;
  c = m1.c;
  d = m1.d;
  v = m1.v;
  i = m1.i;
  n = m1.n;
}
std::string Message::diggest() {
    std::stringstream ss;
    ss << o << t << c;
    return sha256(ss.str());
}
//消息内容
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
Message Message::operator=(const Message &m1) {
  if (this == &m1)
    return *this;
  else
  {
    msg_type = m1.msg_type;
    c = m1.c;
    t = m1.t;
    o = m1.o;
    d = m1.d;
    i = m1.i;
    n = m1.n;
    v = m1.v;
    return *this;
  }

}
