#include "string.h"

struct string
{
    char* str;
    int size;
    int capacity;

};

void Clear(struct string* str)
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
    str->str[str->size] = '\0';
    if (str->size >= str->capacity - 1)
    {
        str->capacity *= 2;
        str->str = (char*)realloc(str->str, str->capacity * sizeof(char));
        CheckAllocationError(str->str);
    }
}

struct string* RemoveAt(struct string* str, int index)
{
    struct string temp;
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

struct string* AddAt(struct string* str, int index, char element)
{
    struct string temp;
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

void EnterText(struct string* text)
{
    char temp;
    while ((temp = getche()) != '$')
    {
        if (temp == 13) Push(text, '%');
            else Push(text, temp);
    }
}

struct string* CopyArrayToStr(struct string* str, char* array)
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