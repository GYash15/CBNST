#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    return x * x * x - 5 * x + 1;
}

int main()
{
    float a, b;
    int cnt = 1;
    do
    {
        printf("Enter interval [a,b]:");
        scanf("%f%f", &a, &b);

        if (fxn(a) * fxn(b) >= 0)
        {
            printf("Invalid intervals. try again");
        }
    } while (fxn(a) * fxn(b) >= 0);
    float c;
    float err = 0.0001;
    do
    {
        c = (a * fxn(b) - b * fxn(a)) / (fxn(b) - fxn(a));
        if (fxn(c) * fxn(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        cnt++;
    } while (fabsf(fxn(c)) >= err);
    printf("Approximation root is:%f\n", c);
    printf("total iteration is %d", cnt);
}