#include "main.h"
#include <assert.h>
#include <math.h>

void testFactorial(){
    assert(Factorial(0) == 1);
    assert(Factorial(5) == 120);
    assert(Factorial(4) == 24);
    assert(Factorial(3) == 6);
    return;
}
void testMySin(){
    double x = 0.25, eps = 0.01;
    assert(fabs(MySin(&x, &eps)[0] - sin(x)) < eps);
    x = 0.14, eps = 0.014;
    assert(fabs(MySin(&x, &eps)[0] - sin(x)) < eps);
    x = 0.256, eps = 0.0256;
    assert(fabs(MySin(&x, &eps)[0] - sin(x)) < eps);
    x = -25, eps = 0.002;
    assert(fabs(MySin(&x, &eps)[0] - sin(x)) < eps);
    return;
}

#undef main

int main(){
    testFactorial();
    testMySin();
    return 0;
}