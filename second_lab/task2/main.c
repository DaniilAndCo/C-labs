#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef unsigned short bool;
#define pi acos(-1.0)

/* Clear buffer trash*/
void MyFlush(void) {
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
    return;
}
void CorrectInputLF(double* inputVar)
{
    while (!scanf("%lf", inputVar))
    {
        MyFlush();
        printf("Enter valid data!\n");
    }
    return;
}
double Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return num * Factorial(num - 1);
}
double* MySin(const double* x, const double* inf)
{
    double x_ = *x;
    x_ -= (int)(x_ / (2 * pi)) * 2 * pi;
    double* answer = (double*)malloc(2 * sizeof(double));
    if (!answer)
    {
        printf("Insufficiency of memory\n");
        exit(0);
    }
    answer[0] = answer[1] = 0;
    double exactValue = sin(x_);
    int i = 0;
    do
    {
        answer[0] += pow(-1, i) * pow(x_, 2 * i + 1) / Factorial(2 * i + 1);
        answer[1] = ++i;

    } while (fabs(exactValue - answer[0]) > *inf);
    return answer;
}

int main()
{
    double x = 0, inf = 0;
    printf("Enter angle in radians and infelicity: \n");
    CorrectInputLF(&x);
    CorrectInputLF(&inf);
    double exactValue = sin(x);
    double approximateValue = MySin(&x, &inf)[0];
    printf("exact value => %lf\nour value => %lf\n", exactValue, approximateValue);
    printf("convergence check with inf = 0.001\n");
    x = -2 * pi;
    inf = 0.001;
    for (; x <= 2 * pi; x += 0.1)
    {
        double* temp = MySin(&x, &inf);
        printf("%lf => %lf\n", x, temp[1]);
        free(temp);
    }
    return 0;
}
