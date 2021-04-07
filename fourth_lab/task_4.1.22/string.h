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

typedef struct
{
    char* str;
    int size;
    int capacity;

}string;
void SetString( string* str);
void Push( string* str, char element);
string* RemoveAt( string* str, int index);
string* AddAt( string* str, int index, char element);
void EnterText( string* text);
string* CopyArrayToStr( string* str, char* array);
void Clear( string* str);
void CheckAllocationError(char* text);

#endif