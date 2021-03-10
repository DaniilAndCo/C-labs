#include "main.h"
#include <assert.h>
#define inf  0.000001

void testSum(){
    assert(Sum(0, 0) - 0 < inf);
    assert(Sum(1, 5) - 6 < inf);
    assert(Sum(0.5, 0.5) - 1 < inf);
    assert(Sum(-0.5, 0.5) - 0 < inf);
    return;
}
void testSubstract(){
    assert(Substract(0, 0) - 0 < inf);
    assert(Substract(0.25, 0.5) + 0.25 < inf);
    assert(Substract(14, 36.6) + 22.6 < inf);
    assert(Substract(0.256, -0.256) - 0.512 < inf);
    return;
}
void testMultiplying(){
    assert(Multiplying(0, 0) - 0 < inf);
    assert(Multiplying(2, 2.5) - 5 < inf);
    assert(Multiplying(-2.3, 0) - 0 < inf);
    assert(Multiplying(1, 14) - 14 < inf);
    return;
}
void testDivision(){
    assert(Division(0, 1) - 0 < inf);
    assert(Division(5.5, 1.1) - 5 < inf);
    assert(Division(360, 10) - 36 < inf);
    assert(Division(1450, 1450) - 1 < inf);
    return;
}
void testAverage(){
    assert(AverageGarmonic(1, 1) - 1 < inf);
    assert(AverageGarmonic(3, 6) - 4 < inf);
    assert(AverageGarmonic(1.5, 1.5) - 1.5 < inf);
    assert(AverageGarmonic(36, 12) - 18 < inf);
    return;
}

#undef main

int main(){
    testAverage();
    testDivision();
    testMultiplying();
    testSubstract();
    testSum();
    return 0;
}