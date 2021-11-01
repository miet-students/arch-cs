#include <iostream>
#include <cstdint>

extern "C" int32_t task1(int32_t x);

bool f(int32_t x)
{
  return x < 7;
}

void calc(int32_t x)
{
  std::cout << "x: " << x << std::endl;
  std::cout << "C++ x < 7: " << (f(x) ? "True" : "False") << std::endl;
  std::cout << "ASM x < 7: " << (task1(x) ? "True" : "False") << std::endl;
}

int main(int argc, char **argv)
{
  calc(-10);
  calc(0);
  calc(3);
  calc(7);
  calc(10);
  return 0;
}
