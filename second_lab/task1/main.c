#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define true 1
#define false 0
typedef unsigned short bool;
#define ARGUMENTS_0 &firstNumber_0, &firstNumber_1, &secondNumber_0, &secondNumber_1
#define ARGUMENTS_1 int* firstNumber_0, int* firstNumber_1, int* secondNumber_0, int* secondNumber_1

double Sum(const double first, const double second)
{
    return first + second;
}
double Substract(const double first, const double second)
{
    return first - second;
}
double Division(const double first, const double second)
{
    return first / second;
}
double Multiplying(const double first, const double second)
{
    return first * second;
}
double AverageGarmonic(const double first, const double second)
{
    return 2 / (1 / first + 1 / second);
}
void PrintMenu()
{
    printf("1. Enter two rational numbers\n");
    printf("2. Show two rational numbers\n");
    printf("3. Sum of two rational numbers\n");
    printf("4. Substract two rational numbers\n");
    printf("5. Multiply two rational numbers\n");
    printf("6. Division of two rational numbers\n");
    printf("7. Get average garmonic of two rational numbers\n");
    printf("8. Information about version and author of program\n");
    printf("9. Exit\n");
    return;
}
void EnterValues(ARGUMENTS_1)
{
    printf("numerator of first one: ");
    scanf("%d", firstNumber_0);
    printf("denominator of first one: ");
    scanf("%d", firstNumber_1);
    printf("numerator of second one: ");
    scanf("%d", secondNumber_0);
    printf("denominator of second one: ");
    scanf("%d", secondNumber_1);
    return;
}
void ShowValues(ARGUMENTS_1)
{
    printf("Two rational numbers: ");
    printf("%d / %d and %d / %d\n", *firstNumber_0, *firstNumber_1, *secondNumber_0, *secondNumber_1);
    return;
}
void ShowSum(ARGUMENTS_1)
{
    printf("%d / %d + %d / %d = %f\n", *firstNumber_0, *firstNumber_1, *secondNumber_0, *secondNumber_1,
        Sum((*firstNumber_0 + 0.0) / *firstNumber_1, (*secondNumber_0 + 0.0) / *secondNumber_1));
    return;
}
void ShowSubstract(ARGUMENTS_1)
{
    printf("%d / %d - %d / %d = %f\n", *firstNumber_0, *firstNumber_1, *secondNumber_0, *secondNumber_1,
        Substract((*firstNumber_0 + 0.0) / *firstNumber_1, (*secondNumber_0 + 0.0) / *secondNumber_1));
    return;
}
void ShowDivision(ARGUMENTS_1)
{
    printf("%d / %d : %d / %d = %f\n", *firstNumber_0, *firstNumber_1, *secondNumber_0, *secondNumber_1,
        Division((*firstNumber_0 + 0.0) / *firstNumber_1, (*secondNumber_0 + 0.0) / *secondNumber_1));
    return;
}
void ShowMultiplying(ARGUMENTS_1)
{
    printf("%d / %d x %d / %d = %f\n", *firstNumber_0, *firstNumber_1, *secondNumber_0, *secondNumber_1,
        Multiplying((*firstNumber_0 + 0.0) / *firstNumber_1, (*secondNumber_0 + 0.0) / *secondNumber_1));
    return;
}
void ShowAverageGarmonic(ARGUMENTS_1)
{
    printf("average garmonic = %f\n", AverageGarmonic((*firstNumber_0 + 0.0) / *firstNumber_1, (*secondNumber_0 + 0.0) / *secondNumber_1));
    return;
}
void ShowInfo()
{
    printf("The author is Daniel Bondarcov 053501\nversion of the program - 1.0.0\n");
    return;
}
bool IsCorrect(char* strNumber) {
    int i = 0;
    for (; i < strlen(strNumber); ++i)
    {
        if (!(strNumber[i] == '0' || strNumber[i] == '1' || strNumber[i] == '2'
            || strNumber[i] == '3' || strNumber[i] == '4' || strNumber[i] == '5'
            || strNumber[i] == '6' || strNumber[i] == '7' || strNumber[i] == '8'
            || strNumber[i] == '9'))
        {
            return false;
        }
    }
    return true;
}
int main()
{


    assert(Division(5, 20) == 0.25);

    PrintMenu();
    int manageVar = 0;
    int firstNumber_0 = 0, firstNumber_1 = 0;
    int secondNumber_0 = 0, secondNumber_1 = 0;
    bool flag = true;
    while (manageVar != 9 && flag)
    {
        char input[255];
        fflush(stdin);
        gets(input);
        while (!IsCorrect(input))
        {
            printf("Enter valid data!\n");
            fflush(stdin);
            gets(input);
        }
        manageVar = atoi(input);
        switch (manageVar)
        {
        case 1:
            EnterValues(ARGUMENTS_0);
            break;
        case 2:
            ShowValues(ARGUMENTS_0);
            break;
        case 3:
            ShowSum(ARGUMENTS_0);
            break;
        case 4:
            ShowSubstract(ARGUMENTS_0);
            break;
        case 5:
            ShowMultiplying(ARGUMENTS_0);
            break;
        case 6:
            ShowDivision(ARGUMENTS_0);
            break;
        case 7:
            ShowAverageGarmonic(ARGUMENTS_0);
            break;
        case 8:
            ShowInfo();
            break;
        case 9:
            flag = false;
            break;
        default:
            printf("Invalid data, enter new one!\n");
            break;
        }
    }
    return 0;
}