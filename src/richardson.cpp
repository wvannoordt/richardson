#include "r_real.h"
#include "operations.h"
#include "typedef.h"
#include "richardson.h"
namespace richardson
{
    void init(void)
    {
        operations::num_ops_total = 0;
    }
    void example(void)
    {
        r_real a(3.0);
        r_real b(4.1);
        for (int i = 0; i < 1000; i++)
            r_real c = a+b;
    }
}
