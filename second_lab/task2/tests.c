#include "main.h"
#include <assert.h>

void testFactorial(){
    assert(Factorial(0) == 1);
    assert(Factorial(5) == 120);
    assert(Factorial(4) == 24);
    assert(Factorial(3) == 6);
    return;
}
void testCorrect(){
    assert(IsCorrect("0.25") == true);
    assert(IsCorrect("-25") == true);
    assert(IsCorrect("d0.25") == false);
    assert(IsCorrect("0.25.25") == false);
    return;
}
/*void testMySin(){
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
*/
#undef main

void main(){
    testCorrect();
    testFactorial();
   /* testMySin();*/
    return;
}