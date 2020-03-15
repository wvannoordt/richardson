#include "operations.h"
#include <iostream>
#include "typedef.h"
#include <string>
#include <unistd.h>
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
#if(EXPENSE_LEVEL>0)
                result = a+b;
                num_ops_total ++;
#endif
                break;
            }
            case R_SUB_OP:
            {
                op_string = "-";
#if(EXPENSE_LEVEL>0)
                result = a-b;
                num_ops_total ++;
#endif
                break;
            }
            case R_MUL_OP:
            {
                op_string = "*";
#if(EXPENSE_LEVEL>0)
                result = a*b;
                num_ops_total ++;
#endif
                break;
            }
            case R_DIV_OP:
            {
                op_string = "/";
#if(EXPENSE_LEVEL>0)
                result = a/b;
                num_ops_total ++;
#endif
                break;
            }
        }
#if(EXPENSE_LEVEL>1)
        return result;
#elif(EXPENSE_LEVEL>0)
        return sim_special_get(a, b, op_string, result);
#else
        return special_get(a, b, op_string);
#endif
    }

    _real sim_special_get(_real a, _real b, std::string op, _real result)
    {
        std::cout << "Please compute the following: ";
        std::cout << a << " " << op << " " << b;
        std::cout << " = ";
        std::string str = std::to_string(result);
        int len = str.length();
        double r = 0;
        for (int i = 0; i < len; i++)
        {
            r = ((double) rand() / (RAND_MAX));
            std::cout << str[i] << std::flush;
            usleep((int)(9000 + r*6000));
        }
        std::cout << std::endl;
    }

    _real special_get(_real a, _real b, std::string op)
    {
        std::cout << "Please compute the following: ";
        std::cout << a << " " << op << " " << b;
        std::cout << " = ";
        double n;
        while(!(std::cin >> n ))
        {
            std::string str;
            std::cin.clear();
            getline(std::cin, str);
            std::cout << str << " is not a number!\n";
        }
    }
}
