#include "main.h"
#include <assert.h>
#include <math.h>
#define eps  0.000001

void testSum(){
    assert(fabs(Sum(0, 0) - 0) < eps);
    assert(fabs(Sum(1, 5) - 6) < eps);
    assert(fabs(Sum(0.5, 0.5) - 1) < eps);
    assert(fabs(Sum(-0.5, 0.5) - 0) < eps);
    return;
}
void testSubstract(){
    assert(fabs(Substract(0, 0) - 0) < eps);
    assert(fabs(Substract(0.25, 0.5) + 0.25) < eps);
    assert(fabs(Substract(14, 36.6) + 22.6) < eps);
    assert(fabs(Substract(0.256, -0.256) - 0.512) < eps);
    return;
}
void testMultiplying(){
    assert(fabs(Multiplying(0, 0) - 0) < eps);
    assert(fabs(Multiplying(2, 2.5) - 5) < eps);
    assert(fabs(Multiplying(-2.3, 0) - 0) < eps);
    assert(fabs(Multiplying(1, 14) - 14) < eps);
    return;
}
void testDivision(){
    assert(fabs(Division(0, 1) - 0) < eps);
    assert(fabs(Division(5.5, 1.1) - 5) < eps);
    assert(fabs(Division(360, 10) - 36) < eps);
    assert(fabs(Division(1450, 1450) - 1) < eps);
    return;
}
void testAverage(){
    assert(fabs(AverageGarmonic(1, 1) - 1) < eps);
    assert(fabs(AverageGarmonic(3, 6) - 4) < eps);
    assert(fabs(AverageGarmonic(1.5, 1.5) - 1.5) < eps);
    assert(fabs(AverageGarmonic(36, 12) - 18) < eps);
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