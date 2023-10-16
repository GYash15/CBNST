#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    // return x * x * x + x - 1;
    return cosf(x) - 3 * x + 1;
}

float fxchosen(float x)
{
    // return pow(1 - x, 1.0 / 3);
    return (1 + cosf(x)) / 3;
}

float fxndx(float x)
{
    // return -1 / (3 * pow(1 - x, 2.0 / 3));
    return -(sinf(x)) / 3;
}

int main()
{
    float x0 = 0; // Initial guess

    if (fxndx(x0) < 1)
    {
        float err = 0.0001;
        int i = 1;
        do
        {
            printf("x%d = %f\n", i, fxchosen(x0));
            x0 = fxchosen(x0);
            i++;
        } while (i < 9);
        printf("The approximation root is %f\n", x0);
    }
    else
    {
        printf("Iteration method failed.\n");
    }

    return 0;
}
