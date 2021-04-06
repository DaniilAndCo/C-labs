#include "functions.h"
#include "functions.c"

int main()
{
    struct string text;
    SetString(&text);
    printf("Enter any text, then the program check it for mistakes\nTo end writing just type '$' symbol\n");
    EnterText(&text);
    FixDotNextLetterProblems(&text);
    FixTwiceWordProblem(&text);
    printf("\n");
    PrintFixedText(&text);
    Clear(&text);
    system("pause");
    return 0;
}
