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
    double x = 0.25, inf = 0.01;
    assert(fabs(MySin(&x, &inf)[0] - sin(x)) < inf);
    x = 0.14, inf = 0.014;
    assert(fabs(MySin(&x, &inf)[0] - sin(x)) < inf);
    x = 0.256, inf = 0.0256;
    assert(fabs(MySin(&x, &inf)[0] - sin(x)) < inf);
    x = -25, inf = 0.002;
    assert(fabs(MySin(&x, &inf)[0] - sin(x)) < inf);
    return;
}

#undef main

int main(){
    testFactorial();
    testMySin();
    return 0;
}