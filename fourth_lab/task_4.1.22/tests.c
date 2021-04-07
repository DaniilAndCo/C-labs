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

    strcpy(temp.str, "Hell");
    temp.size = strlen("Hell");
    assert(!strcmp(FixTwiceWordProblem(&temp), "Hell"));
    strcpy(temp.str, "a a");
    temp.size = strlen("a a");
    assert(!strcmp(FixTwiceWordProblem(&temp), "a -"));
   
    Clear(&temp);
}

int main(){
    TestsFix();
    return 0;
}