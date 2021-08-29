#define EPSILON 0.00001
#include "square_solve.h"
#include <assert.h>
//разбить на функции(ввод вывод и в мейне ничего, прочитатьпро .h файлы попробовать разбить на файлы
enum NRoots_e {
    INF_ROOTS =     4,
    ONE_ROOTS =     1,
    ONE_ROOTS_TWO = 5,
    ZERO      =     6,
    TWO_ROOTS =     2,
    NO_ROOTS =      0,
};
int main()
{
    int testQuadratic();
    double a  = NAN;
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
        case ONE_ROOTS:
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
    }
}

int cmp_with_0(double u)
{
    return fabs(u) < EPSILON;
}

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
            if(discr == 0)//cmp_with_0
            {
                if(c == 0)//cmp_with_0
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
                                                                                //3 массива для входных(коофициенты кв ур) данных
int testQuadratic()                                                                     //еще 3 массива(один лдя числа корней + 2 для самих корней
{
double testo[12][6]=
    {
    {1, 4, 1, -0.267949, -3.73205,2},           //1
    {2, 7, 3, -0.5, -3,2},                      //2
    {1, 4, 4, -0.5, 0, 1},                      //3
    {5, 8, 3, -0.6, -0.1, 2},                     //4
    {5, 15, 4, -0.295841, -2.70416, 2},         //5
    {7, 17, 3, -0.191584, -2.23699, 2},         //6
    {0, 4, -2, 2, 0, 1},                        //7
    {1, 0, 0, 0, 0, 1},                         //8
    {0, 1, 0, 0, 0, 1}, //чё                    //9
    {3, 2, 0, 0, -0.666667, 2},                 //10
    {1, 1, 1, 0, 0, 0},                         //11
    {2, 44, 13, -0.299533, -21.7005, 2}         //12
    };
    for(int i = 0; i < 12; i++)
    {
        double x1 = 0;
        double x2 = 0;

        int NeedsTesting = solve_square (testo[i][0], testo[i][1], testo[i][2], &x1, &x2);

        if (testo[i][5] == NeedsTesting &&
            cmp_with_0 (x1 - testo[i][3]) &&
            cmp_with_0 (x2 - testo[i][4]))
            printf ("Test number %3d - CORRECT\n", i+1);
        else
        {
            printf ("Test number %lg ERROR\n", i+1);
            printf ("Entern  b=%lg c=%lg\n", testo[i][0], testo[i][1], testo[i][2]);
            printf ("Expected out: x1=%lg x2=%lg n_roots=%d\n", testo[i][3], testo[i][4], testo[i][5]);
            printf ("Real     out: x1=%lg x2=%lg n_roots=%d\n\n", x1, x2, NeedsTesting);
        }
    }
}

