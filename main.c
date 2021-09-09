#include <assert.h>

#include "square_solve.h"
#include <assert.h>

#include "square_solve.h"

//#define TEST



enum NRoots_e {
    INF_ROOTS     = 4,
    ONE_ROOTS     = 1,
    TWO_ROOTS     = 2,
    NO_ROOTS      = 0,
};



int main()
{
    #ifdef TEST
    testQuadratic();
    #endif // TEST
    printf("             \n"
           "a*x^2+b*x+c  \n"
           "enter a b c: \n");
    solver();
}

