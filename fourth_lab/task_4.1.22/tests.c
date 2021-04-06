#include "main.h"
#include <assert.h>
#include <string.h>
#undef main

struct string temp;

void TestFix1()
{
    strcpy(temp.str, "Hello. World");
    temp.size = strlen("Hello. World");
    assert(!strcmp(FixDotNextLetterProblems(&temp), "Hello. World"));
    strcpy(temp.str, ".   ");
    temp.size = strlen(".   ");
    assert(!strcmp(FixDotNextLetterProblems(&temp), ".   "));
}

void TestFix2()
{
    strcpy(temp.str, "Hello hello");
    temp.size = strlen("Hello hello");
    assert(!strcmp(FixTwiceWordProblem(&temp), "Hello hello"));
    strcpy(temp.str, "hello hello");
    temp.size = strlen("hello hello");
    assert(!strcmp(FixTwiceWordProblem(&temp), "hello -----"));
    strcpy(temp.str, "a a b");
    temp.size = strlen("a a b");
    assert(!strcmp(FixTwiceWordProblem(&temp), "a - b"));
    strcpy(temp.str, "my Mam. Mam");
    temp.size = strlen("my Mam. Mam");
    assert(!strcmp(FixTwiceWordProblem(&temp), "my Mam. Mam"));
}

int main(){
    SetString(&temp);
    TestFix1();
    TestFix2();
    Clear(&temp);
    return 0;
}