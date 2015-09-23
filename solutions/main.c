#include <stdio.h>
#include <math.h>

void solutions(double a, double b, double c)
{
    double x1, x2, x, d;

    if (a == 0.0)
    {
        if (b == 0.0)
        {
            if (c == 0.0)
                printf("Countless number of solutions.\n");
            else
                printf("Unfortunately, no solutions. :(\n");
        }
        else
        {
            x = -c / b;
            if (x == -0.0)
                x = 0.0;
            printf("Equation has 1 solution: %lg\n", x);
        }
    }
    else
    {
        d = b * b - 4 * a * c;
        if (d >= 0.0)
        {
            x2 = (-b - sqrt(d)) / (2 * a);
            x1 = (-b + sqrt(d)) / (2 * a);
            if (x1 == -0.0)
                x1 = 0.0;
            if (x2 == -0.0)
                x2 = 0.0;
            if (x1 == x2)
                printf("Equation has 1 solution: %lg\n", x1);
            else
            {
                if (x1 > x2)
                {
                    printf("Equation has 2 solutions: %lg and %lg\n", x2, x1);
                }
                else
                {
                    printf("Equation has 2 solutions: %lg and %lg\n", x1, x2);
                }
            }
        }
        else
            printf("Unfortunately, no solutions. :(\n");
    }

}

int main ()
{
    double a, b, c;

    printf("Hello! Please, input coefficients of quadratic equation..\n");

    if (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("Unfortunately, wrong input. :(\n");
        return 0;
    }

    solutions(a, b, c);

    return 0;
}
