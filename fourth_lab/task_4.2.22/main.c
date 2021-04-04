#include "string.h"
#include "string.c"

bool_ IsFirstType(char symbol)
{
    switch (symbol)
    {
        case '.' :
        case ',' :
        case ':' :
        case ';' :
        case '!' :
        case '?' :
        case ')' :
        case '}' :
        case ']' : return true;
        default : return false;
    }
}
bool_ IsSecondType(char symbol)
{
    switch (symbol)
    {
        case '(' :
        case '{' :
        case '[' : return true;
        default : return false;
    }
}

char* FixMistakes(struct string* str)
{
    int i = 0;
    for (; i < str->size; ++i)
    {
        if (IsFirstType(str->str[i]))
        {
            if (str->str[i + 1] != ' ')
            {   
                AddAt(str, i + 1, ' ');
            }
            while (str->str[i - 1] == ' ')
            {
                RemoveAt(str, --i);
            }
        }
        else if (IsSecondType(str->str[i]))
        {
            while (str->str[i + 1] == ' ')
            {   
                RemoveAt(str, i + 1);
            }
            if (str->str[i - 1] != ' ')
            {
                AddAt(str, i, ' ');
            }
        }
    }
    return str->str;
}

int main()
{
    int i = 0;
    char buffer[255];
    FILE *in = fopen("input.txt","r"), *out = fopen("input.txt","r+");
    if (!in || !out)
    {
        perror ("input.txt");
        exit(0);
    }
    rewind(out);
    while (fgets(buffer, 255, in))
    {
        struct string temp;
        SetString(&temp);
        fputs(FixMistakes(CopyArrayToStr(&temp, buffer)),out);
        Clear(&temp);
    }
    fclose(in);
    fclose(out);
    system("pause");

    return 0;
}