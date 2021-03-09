#include "main.h"
#include <assert.h>

void testCreateBinaryNumber(){
    assert(CreateBinaryNumber(0, "") == "111");
    assert(CreateBinaryNumber(1, "111") == "111000");
    assert(CreateBinaryNumber(2, "111000") == "111000111");
    assert(CreateBinaryNumber(3, "111000111") == "111000111000");
    return;
}

void testConcat(){
    assert(Concat("1", "2") == "12");
    assert(Concat("", "2") == "2");
    assert(Concat("3-5", "=5") == "3-5=5");
    assert(Concat("25", "*2=2") == "25*2=2");
    return;
}
#undef main

void main(){
    testCreateBinaryNumber();
    testConcat();
    return;
}