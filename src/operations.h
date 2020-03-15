#include <iostream>
#include "typedef.h"
#include <string>
#include "typedef.h"
namespace richardson::operations
{
    extern unsigned long long num_ops_total;
    _real R_add(_real a, _real b);
    _real R_sub(_real a, _real b);
    _real R_mul(_real a, _real b);
    _real R_div(_real a, _real b);
    _real R_op_gen(_real a, _real b, const int op_code);
    _real special_get(_real a, _real b, std::string op);
    _real sim_special_get(_real a, _real b, std::string op, _real result);
}
