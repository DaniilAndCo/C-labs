#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct
{
    char* str;
    int size;
    int capacity;

}string;

char* FixDotNextLetterProblems(string* text);
char* FixTwiceWordProblem(string* text);
void SetString(string* str);
void Clear(string* str);

#endif