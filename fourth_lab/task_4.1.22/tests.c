#include "main.h"
#include <assert.h>
#include <string.h>
#undef main

void TestFix1()
{
    struct string temp;
    SetString(&temp);
    strcpy(temp.str, "Hello. World");
    temp.size = strlen("Hello. World");
    assert(!strcmp(FixDotNextLetterProblems(&temp), "Hello. World"));
    strcpy(temp.str, ".   ");
    temp.size = strlen(".   ");
    assert(!strcmp(FixDotNextLetterProblems(&temp), ".   "));
    Clear(&temp);
}

void TestFix2()
{
    struct string temp;
    SetString(&temp);
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
    Clear(&temp);
}

int main(){
    TestFix1();
    TestFix2();
    return 0;
}