#include "square_solve.h"


int main()
{
    solve_quadratic();
    solve_discr();
    return 0;
}

void solve_quadratic()
{
    printf("a*x^2+b*x+c\n"
           "enter a b c: \n" );

    double a = 0;
    double b = 0;
    double c = 0;

    scanf("%lg, %lg, %lg", &a, &b, &c);

       if(a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
            {
                printf("any number\n");
            }
            else
            {
                printf("no solution\n");
            }
        }
        else
        {
            printf ("x = %lg\n", -c/b);
        }
    }
    else
    {
         solve_discr();
    }
}

void solve_discr()
{


         double a = 0;
         double b = 0;
         double c = 0;
         double x1 = 0;
         double x2 = 0;
         double discr = b * b - 4 * a * c;

         if (discr < 0)
         {
             printf("no solution\n");
         }
         else
         {
            if (discr == 0)
            {
                printf("x = %lg\n", -b / (2 * a));
            }
            else
            {
                printf("x1= %lg, x2= %lg",(-b+sqrt(discr))/(2*a),(-b-sqrt(discr))/(2*a));
            }

        }
}
