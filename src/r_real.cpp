#include "r_real.h"
#include "operations.h"
#include "typedef.h"
namespace richardson
{
    r_real::r_real(_real _val)
    {
        val = _val;
    }
    r_real r_real::operator +(r_real const &b)
    {
        return r_real(operations::R_add(val, b.val));
    }
    r_real r_real::operator -(r_real const &b)
    {
        return r_real(operations::R_sub(val, b.val));
    }
    r_real r_real::operator *(r_real const &b)
    {
        return r_real(operations::R_mul(val, b.val));
    }
    r_real r_real::operator /(r_real const &b)
    {
        return r_real(operations::R_div(val, b.val));
    }
}
