#include "string.h"
#include "string.c"
#include <math.h>


char* FixDotNextLetterProblems(string* text)
{
    int i = 0;
    for (; i < text->size; ++i)
    {
        if (text->str[i] == '.')
        {
            ++i;
            while (i < text->size && (text->str[i] == ' ' || text->str[i] == '%'))
            {
                ++i;
            }
            if (i < text->size && (text->str[i] >= 97 && text->str[i] <= 122))
            {
                printf("%c", text->str[7] - 32);
                text->str[i] -= 32;
            }
        }
    }
    return text->str;
}

bool_ IsEqual(string* text, int index1, int index2)
{
    do
    {
        if ((text->str[index1] != text->str[index2]) && (abs(text->str[index1] - text->str[index2]) != 32)) return false;
        else 
        {
            ++index1;
            ++index2;
        }
    } while (text->str[index1] != ' ' && text->str[index1] != '%' && text->str[index2] != ' ' && text->str[index2] != '%' && text->str[index2] != '.' && text->str[index1] != '.');
    return true;
}

void DeleteTwicedWord(string* text, int index2)
{
    while (index2 < text->size && text->str[index2] != ' ' && text->str[index2] != '%' && text->str[index2] != '.')
    {
        text->str[index2] = '-';
        ++index2;
    }
}

char* FixTwiceWordProblem(string* text)
{

    int i1 = 0, i2 = 0;
    while (i2 < text->size)
    {
        while (text->str[i1] == ' ' || text->str[i1] == '%')
        {
            ++i1;
        }
        i2 = i1;
        while (text->str[i2] != ' ' && text->str[i2] != '%')
        {
            ++i2;
        }
        while (text->str[i2] == ' ' || text->str[i2] == '%')
        {
            ++i2;
        }
        if (IsEqual(text, i1, i2))
        {
            DeleteTwicedWord(text, i2);
        }
        if (i2 < text->size) i1 = ++i2;
    }
    return text->str;
}

void PrintFixedText(string* text)
{
    int i = 0;
    for (; i < text->size; ++i)
    {
        if (text->str[i] != '-')
        if (text->str[i] == '%') 
            printf("\n");
        else
            printf("%c", text->str[i]);
    }
    printf("\n");
}

int main()
{
    string text;
    SetString(&text);
    printf("Enter any text, then the program check it for mistakes\nTo end writing just type '$' symbol\n");
    EnterText(&text);
    FixDotNextLetterProblems(&text);
    FixTwiceWordProblem(&text);
    printf("\n");
    PrintFixedText(&text);
    Clear(&text);
    return 0;
}
