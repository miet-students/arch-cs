#include <iostream>
#include <cstdint>
#include <cmath>

double f(double x)
{
    return (double)(7.9-sin(x))/(1-cos(x));
}

void calc(double x)
{
  std::cout << "x: " << x << std::endl;
  std::cout << "C++ y(x): " << f(x) << std::endl;
  const volatile double y = 7.9;
  double res;
  asm(                                // st(0), st(1), st(2), st(3)
      "fldl %[y]\n"                   // в стеке: y
      "fld1\n"                        // в стеке: 1, y
      "fldl %[x]\n"                   // в стеке: x, 1, y
      "fsincos\n"                     // в стеке: cos, sin, 1, y
      "fsubrp %%st(0), %%st(2)\n"     // в стеке: sin, 1-cos, y
      "fsubrp %%st(0), %%st(2)\n"     // в стеке: 1-cos, y-sin
      "fdivr\n"                       // в стеке: (y-sin)/(1-cos)
      "fstpl %[res]\n"                // стек пуст, y = (y-sin)/(1-cos)

       :[res]"=m"(res)
       :[x]"m"(x), [y]"m"(y)
       :"cc"
       );

  std::cout << "ASM y(x): " << res << std::endl;
  std::cout << std::endl;
}

int main()
{
  calc(0);
  calc(3.14159265);
  calc(1.57079632679);
  return 0;
}
