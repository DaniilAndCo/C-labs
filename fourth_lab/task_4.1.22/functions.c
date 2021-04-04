#include "functions.h"

void CheckAllocationError(char* text)
{
    if (!text)
    {
        printf("Allocation error\n");
        exit(0);
    }
}

void SetString(struct string* str)
{
    str->capacity = DEFAULT_CAPACITY;
    str->size = 0;
    str->str = (char*)malloc(str->capacity * sizeof(char));
    CheckAllocationError(str->str);
}

void Push(struct string* str, char element)
{
    str->str[str->size++] = element;
    if (str->size >= str->capacity)
    {
        str->capacity *= 2;
        str->str = (char*)realloc(str->str, str->capacity * sizeof(char));
        CheckAllocationError(str->str);
    }
}

void Clear(struct string* str)
{
   if (str->str) free(str->str);
}

void EnterText(struct string* text)
{
    char temp;
    while ((temp = getche()) != '$')
    {
        if (temp == 13) Push(text, '%');
            else Push(text, temp);
    }
    Push(text, '\0');
}

char* FixDotNextLetterProblems(struct string* text)
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

bool_ IsEqual(struct string* text, int index1, int index2)
{
    do
    {
        if (text->str[index1] != text->str[index2]) return false;
        else 
        {
            ++index1;
            ++index2;
        }
    } while (text->str[index1] != ' ' && text->str[index1] != '%' && text->str[index2] != ' ' && text->str[index2] != '%' && text->str[index2] != '.' && text->str[index1] != '.');
    return true;
}

void DeleteTwicedWord(struct string* text, int index2)
{
    while (index2 < text->size && text->str[index2] != ' ' && text->str[index2] != '%' && text->str[index2] != '.')
    {
        text->str[index2] = '-';
        ++index2;
    }
}

char* FixTwiceWordProblem(struct string* text)
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

void PrintFixedText(struct string* text)
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