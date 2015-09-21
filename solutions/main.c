#include<stdio.h>
#include<math.h>

double solutions(double a, double b, double c)
{
    double x1, x2, x;


    /*if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("wrong input\n");
        return 0;
    }*/

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("R\n");
            else
                printf("NO\n");
        }
        else
        {
            x = -c / b;
            if (x == -0)
                x = 0;
            printf("%lg", x);
        }
    }
    else
    {
        if ((b * b - 4 * a * c) >= 0)
        {
            x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            if (x1 == -0)
                x1 = 0;
            if (x2 == -0)
                x2 = 0;
            if (x1 == x2)
                printf("%lg", x1);
            else
            {
                if (x1 > x2)
                {
                    printf("%lg %lg", x2, x1);
                }
                else
                {
                    printf("%lg %lg", x1, x2);
                }
            }
        }
        else
            printf("NO\n");
    }

    return 0;
}

int main ()
{
    double a, b, c;

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("wrong input\n");
        return 0;
    }

    solutions(a, b, c);

    return 0;
}
