#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    return x * x * x - 2 * x - 5;
}

int main()
{
    int cnt = 1;
    float a, b;
    do
    {
        printf("Enter interval [a,b]: ");
        scanf("%f%f", &a, &b);

        if (fxn(a) * fxn(b) >= 0)
        {
            printf("Invalid argument, Please try again!");
        }
    } while (fxn(a) * fxn(b) >= 0);

    float x;
    float err = 0.00001;
    printf("cnt\t\ta\t\tb\t\tx\t\tfxn(x)\n");
    do
    {
        x = (a + b) / 2.0;
        printf("%d\t%f\t%f\t%f\t%f\n", cnt++, a, b, x, fxn(x));
        if (fxn(x) < 0)
            a = x;
        else
            b = x;
    } while (fabsf(fxn(x)) >= err);

    printf("Approximation root is:%f", x);
}