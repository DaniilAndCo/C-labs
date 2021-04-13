#include <cassert>
#include "main.h"

#undef main

void TestGCD()
{
    BigInt A("25");
    BigInt B("17");
    assert(GCD(A,B) == BigInt("1"));
    A.Set("25");
    B.Set("5");
    assert(GCD(A,B) == BigInt("5"));
    A.Set("15");
    B.Set("45");
    assert(GCD(A,B) == BigInt("15"));
    A.Set("170");
    B.Set("17");
    assert(GCD(A,B) == BigInt("17"));
}
void TestABS()
{   
    string str = "25";
    ABS(str);
    assert(str == "25");
    str = "-25";
    ABS(str);
    assert(str == "25");
    str = "0";
    ABS(str);
    assert(str == "0");
    str = "-256";
    ABS(str);
    assert(str == "256");
}

int main()
{
    TestGCD();
    TestABS();
    return 0;
}