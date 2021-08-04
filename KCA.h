#ifndef K_CA_KCA_H
#define K_CA_KCA_H

#include <iostream>
#include <mutex>
#include <math.h>
#define NUMOFTRANS 8000


typedef int network_address_t;

static constexpr int Fault_Node =1;
static constexpr int Num_Node = 3 * Fault_Node + 1;
const int k_value = 2;

extern std::mutex console_mutex;

#endif
