#ifndef TYPEDEF_H
#define TYPEDEF_H

#ifndef EXPENSE_LEVEL
#define EXPENSE_LEVEL 0
#endif

#define R_ADD_OP 0
#define R_SUB_OP 1
#define R_MUL_OP 2
#define R_DIV_OP 3

#ifndef PRECISION
#define PRECISION 2
#endif

#if(PRECISION==1)
typedef float _real;
#else
typedef double _real;
#endif

#endif
