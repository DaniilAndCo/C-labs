#ifndef _MAIN_H_
#define _MAIN_H_

struct string
{
    char* str;
    int size;
    int capacity;

};
char* FixDotNextLetterProblems(struct string* text);
char* FixTwiceWordProblem(struct string* text);
void SetString(struct string* str);
void Clear(struct string* str);

#endif