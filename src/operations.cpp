#include "operations.h"
#include <iostream>
#include "typedef.h"
#include <string>
namespace richardson::operations
{
    unsigned long long num_ops_total;
    _real R_add(_real a, _real b)
    {
        return R_op_gen(a, b, R_ADD_OP);
    }

    _real R_sub(_real a, _real b)
    {
        return R_op_gen(a, b, R_SUB_OP);
    }

    _real R_mul(_real a, _real b)
    {
        return R_op_gen(a, b, R_MUL_OP);
    }

    _real R_div(_real a, _real b)
    {
        return R_op_gen(a, b, R_DIV_OP);
    }

    _real R_op_gen(_real a, _real b, const int op_code)
    {
        std::string op_string = "+";
        _real result = 0.0;
        switch (op_code)
        {
            case R_ADD_OP:
            {
                op_string + "+";
#if(EXPENSE_LEVEL>1)
                result = a+b;
#endif
                break;
            }
            case R_SUB_OP:
            {
                op_string = "-";
#if(EXPENSE_LEVEL>1)
                result = a-b;
#endif
                break;
            }
            case R_MUL_OP:
            {
                op_string = "*";
#if(EXPENSE_LEVEL>1)
                result = a*b;
#endif
                break;
            }
            case R_DIV_OP:
            {
                op_string = "/";
#if(EXPENSE_LEVEL>1)
                result = a/b;
#endif
                break;
            }
        }
#if(EXPENSE_LEVEL>1)
        return result;
#elif(EXPENSE_LEVEL>0)
        return sim_special_get(a, b, op_string);
#else
        return special_get(a, b, op_string);
#endif
    }

    _real sim_special_get(_real a, _real b, std::string op)
    {
        return 0.0;
    }

    _real special_get(_real a, _real b, std::string op)
    {
        return 0.0;
    }
}
