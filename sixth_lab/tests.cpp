#include <cassert>
#include "main.h"

#undef main

void Test()
{
   assert(IsStrEven("b") == true);
   assert(IsStrEven("a") == false);
   assert(IsStrEven("ac") == true);
   assert(IsStrEven("ab") == false);
}

int main()
{
    Test();
    return 0;
}