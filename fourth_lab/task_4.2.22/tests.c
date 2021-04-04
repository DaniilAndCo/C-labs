#include "main.h"
#include <assert.h>
#include <string.h>
#undef main

struct string temp;

void TestFixMistakes()
{
    strcpy(temp.str, "{}");
    temp.size = strlen("{}");
    assert(!strcmp(FixMistakes(&temp), " {} "));
    strcpy(temp.str, "hi(");
    temp.size = strlen("hi(");
    assert(!strcmp(FixMistakes(&temp), "hi ("));
    strcpy(temp.str, ")hi");
    temp.size = strlen(")hi");
    assert(!strcmp(FixMistakes(&temp), ") hi"));
    strcpy(temp.str, "Daniel (Bondarcov)[Vasilievich]");
    temp.size = strlen("Daniel (Bondarcov)[Vasilievich]");
    assert(!strcmp(FixMistakes(&temp), "Daniel (Bondarcov) [Vasilievich] "));
}


int main(){
   
    SetString(&temp);
    TestFixMistakes();    
    Clear(&temp);
    return 0;
}