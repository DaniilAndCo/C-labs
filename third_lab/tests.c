#include "main.h"
#include <math.h>
#include <assert.h>

void testWaterFlow(){
    unsigned int s = 1, h = 1, v = 1;
    double inf = 0.01;
    assert(fabs(CalculateWaterFlow(&h, &s, &v) - 1.5708) < inf);
    h = 2;
    s = 1;
    v = 36;
    assert(fabs(CalculateWaterFlow(&h, &s, &v) - 113.097) < inf);
    h = 4;
    s = 20;
    v = 6;
    assert(fabs(CalculateWaterFlow(&h, &s, &v) - 753.982) < inf);
    h = 6;
    s = 150;
    v = 2;
    assert(fabs(CalculateWaterFlow(&h, &s, &v) - 2827.433) < inf);
    return;
}

#undef main

int main(){
    testWaterFlow();
    return 0;
}