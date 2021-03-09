#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
typedef unsigned short bool;
#define pi acos(-1.0)

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
bool IsCorrect(char* strNumber)
 {
    int numOfMinuses = 0, numOfDots = 0, i = 0;
    for (; i < strlen(strNumber); ++i) {
        if (strNumber[i] == '0' || strNumber[i] == '1' || strNumber[i] == '2'
            || strNumber[i] == '3' || strNumber[i] == '4' || strNumber[i] == '5'
            || strNumber[i] == '6' || strNumber[i] == '7' || strNumber[i] == '8'
            || strNumber[i] == '9')
        {
        }
        else if (strNumber[i] == '.') ++numOfDots;
        else if (strNumber[i] == '-') ++numOfMinuses;
        else return false;
    }
    if (numOfDots <= 1 && numOfMinuses <= 1) {
        if (numOfMinuses == 1 && strNumber[0] != '-')
            return false;
        else return true;
    }
    return false;
}

void main()
{
    double x = 0, inf = 0;
    char input[255];
    fflush(stdin);
    gets(input);
    while (!IsCorrect(input))
    {
        printf("Enter valid data!\n");
        fflush(stdin);
        gets(input);
    }
    x = atof(input);
    fflush(stdin);
    gets(input);
    while (!IsCorrect(input))
    {
        printf("Enter valid data!\n");
        fflush(stdin);
        gets(input);
    }
    inf = atof(input);
    double exactValue = sin(x);
    double approximateValue = MySin(&x, &inf)[0];
    printf("%lf | %lf\n", exactValue, approximateValue);
    printf("convergence check with inf = 0.001\n");
    x = -2 * pi;
    inf = 0.001;
    for (; x <= 2 * pi; x += 0.1)
    {
        double* temp = MySin(&x, &inf);
        printf("%lf => %lf\n", x, temp[1]);
        free(temp);
    }
    return;
}