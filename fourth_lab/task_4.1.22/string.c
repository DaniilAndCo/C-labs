#include "string.h"
#include <conio.h>
void Clear(string* str)
{
   if (str->str != NULL) free(str->str);
}

void CheckAllocationError(char* text)
{
    if (!text)
    {
        printf("Allocation error\n");
        exit(0);
    }
}

void SetString(string* str)
{
    str->capacity = DEFAULT_CAPACITY;
    str->size = 0;
    str->str = (char*)malloc(str->capacity * sizeof(char));
    CheckAllocationError(str->str);
}

void Push(string* str, char element)
{
    str->str[str->size++] = element;
    str->str[str->size] = '\0';
    if (str->size >= str->capacity - 1)
    {
        str->capacity *= 2;
        str->str = (char*)realloc(str->str, str->capacity * sizeof(char));
        CheckAllocationError(str->str);
    }
}

 string* RemoveAt(string* str, int index)
{
     string temp;
    SetString(&temp);
    int i = 0;
    for (; i < index; ++i)
    {
        Push(&temp, str->str[i]);
    }
    ++i;
    for (; i < str->size; ++i)
    {
        Push(&temp, str->str[i]);
    }
    Clear(str);
    *str = temp;
    return str;
}

 string* AddAt(string* str, int index, char element)
{
     string temp;
    SetString(&temp);
    int i = 0;
    for (; i < index; ++i)
    {
        Push(&temp, str->str[i]);
    }
    Push(&temp, element);
    for (; i < str->size; ++i)
    {
        Push(&temp, str->str[i]);
    }
    Clear(str);
    *str = temp;
    return str;
}

void EnterText(string* text)
{
    char temp;
    while ((temp = getche()) != '$')
    {
        if (temp == 13) Push(text, '%');
            else Push(text, temp);
    }
}

 string* CopyArrayToStr( string* str, char* array)
{
    Clear(str);
    SetString(str);
    int i = 0;
    for (; i < strlen(array); ++i)
    {
        Push(str, array[i]);
    }
    return str;
}