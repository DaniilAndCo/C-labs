#ifndef _STRING_H_
#define _STRING_H_

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define true 1
#define false 0
typedef unsigned short bool_;

#define DEFAULT_CAPACITY 50

struct string;
void SetString(struct string* str);
void Push(struct string* str, char element);
struct string* RemoveAt(struct string* str, int index);
struct string* AddAt(struct string* str, int index, char element);
void EnterText(struct string* text);
struct string* CopyArrayToStr(struct string* str, char* array);
void Clear(struct string* str);
void CheckAllocationError(char* text);

#endif