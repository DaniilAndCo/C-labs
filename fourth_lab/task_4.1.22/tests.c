#include "main.h"
#include <assert.h>
#include <string.h>
#undef main

void TestsFix()
{
    string temp;
    SetString(&temp);
    strcpy(temp.str, "Hello. World");
    temp.size = strlen("Hello. World");
    assert(!strcmp(FixDotNextLetterProblems(&temp), "Hello. World"));
    strcpy(temp.str, ".   ");
    temp.size = strlen(".   ");
    assert(!strcmp(FixDotNextLetterProblems(&temp), ".   "));

    strcpy(temp.str, "Hello hello");
    temp.size = strlen("Hello hello");
    assert(!strcmp(FixTwiceWordProblem(&temp), "Hello -----"));
   
    Clear(&temp);
}

int main(){

    TestsFix();
    return 0;
}