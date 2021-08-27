#define EPSILON 0.00001
#include "square_solve.h"
#include "math.h"
#include <assert.h>


int main()


{
    printf("a*x^2+b*x+c\n"
           "enter a b c: \n" );

    double a = NAN; //не вогнал, когда присваивать, че за NAN//
    double b = NAN;//live journal деда//sideof.lj.ru//
    double c = NAN;

    double x2 = NAN;
    double x1 = NAN;


    scanf("%lg %lg %lg",&a, &b, &c);

    int numRoots = solve_square(a, b, c, &x1, &x2);
    switch(numRoots)
    {
    case 0:
        printf("No Solution\n");
        break;
    case 1:
        printf("x= %lg\n", -c/b);
        printf("haha");
        break;
    case 2:
        printf("x1= %lg\n x2= %lg\n", x1, x2);
        break;
    case 4:
        printf("Any number");
        break;
    case 5:
        printf("x= %lg\n", -b/(2*c));
        break;
    case 6:
        printf("0");
        break;
    }
}
int cmp_with_0(double l)
{
    if(l<EPSILON)
        return 1;
    else return 0;
}

int cmp_with_0(double l);
int solve_square(double a, double b, double c, double *x1, double *x2)  //isnan isfinite NULL pointer загуглить
{                                                                       // шо такое дефайны
    if(cmp_with_0(a))
    {
        if(cmp_with_0(b))
        {
            if(cmp_with_0(c))
            {

                return 4;
            }
            else
            {

              return 0;
            }
        }
        else
        {
            if(cmp_with_0(c))
            {

                return 6;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        double discr=(b*b-4*a*c);
        if (discr > 0) //на два ифа
        {
            *x1 = (-b+sqrt(discr))/(2*a);
            *x2 = (-b-sqrt(discr))/(2*a);
            return 2;
        }
        else
        {
            if(discr=0)
            {
                *x1 = -b/(2*c);
                return 5;
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

