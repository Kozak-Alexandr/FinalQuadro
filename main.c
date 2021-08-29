#include <assert.h>

#include "square_solve.h"

#define EPSILON 0.00001

enum NRoots_e {
    INF_ROOTS     = 4,
    ONE_ROOTS     = 1,
    ONE_ROOTS_TWO = 5,
    ZERO          = 6,
    TWO_ROOTS     = 2,
    NO_ROOTS      = 0,
};



int main()
{
   testQuadratic();
   /* double a  = NAN;
    double b  = NAN;//live journal деда//sideof.lj.ru//
    double c  = NAN;
    double x2 = NAN;
    double x1 = NAN;
    printf("a*x^2+b*x+c\n"
           "enter a b c: \n");
    int result = scanf ("%lg %lg %lg", &a, &b, &c);
    if (result < 3) //сканф держит в памяти 3 значения
    {
        printf("Did your cat walk on the keyboard?\n");   //в мейн
        //while(getchar() != '\n')
        //    printf(" ^._.^ PURR PURR PURR ^._.^ PURR PURR PURR\n ");
        return 0;
    }


    if  (isnan(a) || isnan(b) || isnan(c))
    {
        puts("Error occured");
        return 0;
    }
    else
    {
        int numRoots = solve_square(a, b, c, &x1, &x2);

        switch(numRoots)
        {
      //  case :
        //    break;
        //default:
          //  break;
        case NO_ROOTS:
            printf(" No Solution\n");
            break;
        case ONE_ROOTS:.
            printf(" x= %lg\n", x1 );
            printf(" haha");
            break;
        case TWO_ROOTS:
            printf(" x1= %lg\n x2= %lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf(" Any number\n");
            break;
        case ONE_ROOTS_TWO:
            printf(" x= %lg\n", x1);
            break;
        case ZERO:
            printf(" 0");
            break;
        }
    }*/
}

//------------------------------------------------------------------------------

/*!
    \brief compares the parameter with zeros within the margin of error
          returns true or false respectively
    \param [in] u - the compared number,
*/

bool cmp_with_0(double u)
{
    return fabs(u) < EPSILON;
}


/*!
   \brief Finds the roots of a quadratic equation
          of the form ax ^ 2 + bx + c = 0
          and returns them in number.
    \param[in] a      - coefficient before x ^ 2;
    \param[in] b      - coefficient before x;
    \param[in] c      - free member;
    \param[in] x1, x2 - pointers to variables
                        for the roots of the equation;
    \warning x1 and x2 will not be initialized,
            if the equation has no roots
*/

int solve_square(double a, double b, double c, double *x1, double *x2)  //isnan isfinite NULL pointer загуглить
{
    // шо такое дефайны
    if(cmp_with_0(a))
    {
        if(cmp_with_0(b))
        {
            if(cmp_with_0(c))
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {
            *x1 = - b / c;
            if(cmp_with_0(c))
            {
                return ZERO;
            }
            else
            {
                return ONE_ROOTS;
            }
        }
    }
    else
    {
        double discr=(b * b - 4 *a * c);
        if (discr > 0)
        {
            *x1 = ( - b + sqrt(discr)) / (2 * a);
            *x2 = ( - b - sqrt(discr)) / (2 * a);
            return TWO_ROOTS;
        }
        else
        {
            if(cmp_with_0(discr))//cmp_with_0
            {
                if(cmp_with_0(c))//cmp_with_0
                {
                   return ZERO;
                }
                else
                {
                    *x1 = -b / (2 * c);
                    return ONE_ROOTS_TWO;
                }
            }
            else
            {
               return NO_ROOTS;
            }
        }
    }
    return 0;
}
/*!
    \brief If entered, junk outputs a funny thing
          and returns them in number.
    \param [in] a - coefficient before x ^ 2;
    \param [in] b - coefficient before x;
    \param [in] c - free member;

*/
 int check_for_junk_and_cats(double a, double b, double c)
 {
        int   ok = 0;
        int   result = 0;
        while (ok == 0)

        {
            int result = scanf ("%lg %lg %lg", &a, &b, &c);
            if (result < 3) //сканф держит в памяти 3 значения
            {
                printf(" Did your cat walk on the keyboard?\n");   //в мейн
                while(getchar() != '\n')
                printf(" ^._.^ PURR PURR PURR ^._.^ PURR PURR PURR\n ");
            }
            else
            {
                ok = 1;
            }
        }
 }

int testQuadratic()
{
    double coof[12][3]=
    {
    {1, 4, 1},      //1
    {2, 7, 3},      //2
    {1, 4, 4},      //3
    {5, 8, 3},      //4
    {5, 15, 4},     //5
    {7, 17, 3},     //6
    {0, 4, -2},     //7
    {1, 0, 0},      //8
    {0, 1, 0},      //9
    {3, 2, 0},      //10
    {1, 1, 1},      //11
    {2, 44, 13}     //12
    };

    double solut[12][2]=
    {
    { -0.267949, -3.73205},           //1
    { -0.5, -3},                      //2
    { -0.5, 0},                       //3
    { -0.6, -0.1},                    //4
    { -0.295841, -2.70416},           //5
    { -0.191584, -2.23699},           //6
    { 2, 0},                          //7
    { 0, 0},                          //8
    { 0, 0}, //чё                     //9
    { 0, -0.666667},                  //10
    { 0, 0},                          //11
    { -0.299533, -21.7005}            //12
    };

    int numb[12][1]=
    {
    {2},                      //1
    {2},                      //2
    {1},                      //3
    {2},                      //4
    {2},                      //5
    {2},                      //6
    {1},                      //7
    {1},                      //8
    {1},                      //9
    {2},                      //10
    {0},                      //11
    {2}                       //12
    };

    for(int i = 0; i < 12; i++)
    {
        double x1 = 0;
        double x2 = 0;

        int NeedsTesting = solve_square (coof[i][0], coof[i][1], coof[i][2], &x1, &x2);        //задаются от 0

        if (numb[i][0] == NeedsTesting &&
            cmp_with_0 (x1 - solut[i][0]) &&
            cmp_with_0 (x2 - solut[i][1]))
            printf ("Test number %3d - CORRECT\n", i+1);
        else
        {
            printf ("Test number %lg ERROR\n", i+1);
            printf ("Entern  b=%lg c=%lg\n", coof[i][0], coof[i][1], coof[i][2]);
            printf ("Expected: x1=%lg x2=%lg n_roots=%d\n", solut[i][0], solut[i][1], numb[i][0]);
            printf ("True: x1=%lg x2=%lg n_roots=%d\n\n", x1, x2, NeedsTesting);
        }
    }
}

