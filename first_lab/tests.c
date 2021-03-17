#include "main.h"
#include <assert.h>

void testCreateBinaryNumber(){
    assert(!strcmp(CreateBinaryNumber(0, ""), "111"));
    assert(!strcmp(CreateBinaryNumber(1, "111"), "111000"));
    assert(!strcmp(CreateBinaryNumber(2, "111000"), "111000111"));
    assert(!strcmp(CreateBinaryNumber(3, "111000111"), "111000111000"));
    return;
}

void testConcat(){
    assert(!strcmp(Concat("1", "2"), "12"));
    assert(!strcmp(Concat("", "2"), "2"));
    assert(!strcmp(Concat("3-5", "=5"), "3-5=5"));
    assert(!strcmp(Concat("25", "*2=2"), "25*2=2"));
    return;
}
#undef main

int main(){
    testCreateBinaryNumber();
    testConcat();
    return 0;
}