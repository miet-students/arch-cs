#include <iostream>
#include <cstdint>

double task3(double x)
{
  double y;

  asm(
      ".data\n"
      "a: .double 3.3\n"
      "b: .double 4.6\n"
      "c: .double 6.9\n"
      ".text\n"
      "fldl a(%%rip)\n" // в стеке A
      "fldl %[X]\n"     // в стеке X, A
      "fcomi\n"         // в стеке X, A
      "fstp %%st(0)\n"  // стек пустой
      "jnbe more_than_3\n"
      "fldl b(%%rip)\n" // в стеке B
      "fstpl %[Y]\n"    // стек пустой
      "jmp end\n"
      "more_than_3:\n"
      "fldl %[X]\n"      // в стеке X
      "faddl c(%%rip)\n" // в стеке C+X
      "fstpl %[Y]\n"     // стек пустой
      "end:\n"
      : [Y] "=m"(y)
      : [X] "m"(x)
      : "cc");

  return y;
}

double f(double x)
{
  if (x < 3.3)
  {
    return 4.6;
  }
  else
  {
    return x + 6.9;
  }
}

void calc(double x)
{
  std::cout << "x: " << x << std::endl;
  std::cout << "C++ y(x): " << f(x) << std::endl;
  std::cout << "ASM y(x): " << (double)task3(x) << std::endl;
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  calc(0);
  calc(3);
  calc(7.1);
  calc(10.7514);
  return 0;
}
