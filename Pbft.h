#pragma one

#include <iostream>
#include <mutex>
#include "Node.h"

typedef int network_address_t;

static constexpr int Fault_Node = 4;//constexpr 用来在编译阶段验证变量的值是否为常量
static constexpr int Num_Node = 3 * Fault_Node + 1;

extern std::mutex console_mutex;//mutex互斥量

