#include <math.h>
#include <stdio.h>

float fxn(float x)
{
    return x * x * x - 5 * x + 1;
}

int main()
{
    float x0, x1;
    do
    {
        printf("Enter interval [a,b]:");
        scanf("%f%f", &x0, &x1);

        if (fxn(x0) * fxn(x1) >= 0)
        {
            printf("Invalid intervals. try again");
        }
    } while (fxn(x0) * fxn(x1) >= 0);

    float err = 0.1;
    float x;
    int i = 1;
    do
    {
        x = (x0 * fxn(x1) - x1 * fxn(x0)) / (fxn(x1) - fxn(x0));
        x0 = x1;
        x1 = x;

        printf("x%d = %f\n", i + 1, x);
        i++;
    } while (i < 20);
    printf("The approximation root is:%f", x);
}
