#ifndef R_REAL_H
#define R_REAL_H

#include "typedef.h"
namespace richardson
{
    class r_real
    {
        public:
            _real val;
            r_real(_real _val);
            r_real operator +(r_real const &b);
            r_real operator -(r_real const &b);
            r_real operator *(r_real const &b);
            r_real operator /(r_real const &b);
    };
}

#endif
