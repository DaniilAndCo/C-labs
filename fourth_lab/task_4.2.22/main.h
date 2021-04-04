#ifndef _MAIN_H_
#define _MAIN_H_

struct string
{
    char* str;
    int size;
    int capacity;

};
char* FixMistakes(struct string* str);
void SetString(struct string* str);
void Clear(struct string* str);

#endif