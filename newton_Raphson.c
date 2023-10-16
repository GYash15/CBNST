#include <stdio.h>
#include <math.h>

float fxn(float x)
{
    return x * x * x - 3 * x - 5;
}
float fxdx(float x)
{
    return 3 * x * x - 3;
}

int main()
{
    float x0;
    printf("Enter intial guess: ");
    scanf("%f", &x0);

    int i = 1;
    do
    {
        x0 = x0 - fxn(x0) / fxdx(x0);
        printf("x%d = %f\n", i, x0);
        i++;
    } while (i <= 10);
    printf("The approximation root is:%f", x0);
}