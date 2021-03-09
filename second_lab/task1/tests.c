#include "main.h"
#include <assert.h>

void testSum(){
    assert(Sum(0, 0) == 0);
    assert(Sum(1, 5) == 6);
    assert(Sum(0.5, 0.5) == 1);
    assert(Sum(-0.5, 0.5) == 0);
    return;
}
void testSubstract(){
    assert(Substract(0, 0) == 0);
    assert(Substract(0.25, 0.5) == -0.25);
    assert(Substract(14, 36.6) == -22.6);
    assert(Substract(0.256, -0.256) == 0.512);
    return;
}
void testMultiplying(){
    assert(Multiplying(0, 0) == 0);
    assert(Multiplying(2, 2.5) == 5);
    assert(Multiplying(-2.3, 0) == 0);
    assert(Multiplying(1, 14) == 14);
    return;
}
void testDivision(){
    assert(Division(0, 1) == 0);
    assert(Division(5.5, 1.1) == 5);
    assert(Division(360, 10) == 36);
    assert(Division(1450, 1450) == 1);
    return;
}
void testAverage(){
    assert(AverageGarmonic(1, 1) == 1);
    assert(AverageGarmonic(3, 6) == 4);
    assert(AverageGarmonic(1.5, 1.5) == 1.5);
    assert(AverageGarmonic(36, 12) == 18);
    return;
}
void testCorrect(){
    assert(IsCorrect("12") == true);
    assert(IsCorrect("12-6") == false);
    assert(IsCorrect("0") == true);
    assert(IsCorrect(".25") == false);
    return;
}
#undef main

void main(){
    testAverage();
    testDivision();
    testMultiplying();
    testSubstract();
    testSum();
    return;
}