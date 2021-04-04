#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 50
#define true 1
#define false 0
typedef unsigned short bool_;

struct string
{
    char* str;
    int size;
    int capacity;

};

void CheckAllocationError(char* text);
void SetString(struct string* str);
void Push(struct string* str, char element);
void Clear(struct string* str);
void EnterText(struct string* text);
char* FixDotNextLetterProblems(struct string* text);
bool_ IsEqual(struct string* text, int index1, int index2);
void DeleteTwicedWord(struct string* text, int index2);
char* FixTwiceWordProblem(struct string* text);
void PrintFixedText(struct string* text);

#endif