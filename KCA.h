#ifndef K_CA_KCA_H
#define K_CA_KCA_H

#include <iostream>
#include <mutex>
#define NUMOFTRANS 4000


typedef int network_address_t;

static constexpr int Fault_Node =2;//constexpr 用来在编译阶段验证变量的值是否为常量
static constexpr int Num_Node = 3 * Fault_Node + 1;
const int k_value = 3;

extern std::mutex console_mutex;//mutex互斥量

#endif
