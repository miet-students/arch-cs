#include <iostream>
#include <cstdint>

extern "C" int32_t task2(int32_t x);

int32_t f(int32_t x)
{
  if (x < 3)
  {
    return 4;
  }
  else
  {
    return 8 * x - 52;
  }
}

void calc(int32_t x)
{
  std::cout << "x: " << x << std::endl;
  std::cout << "C++ y(x): " << f(x) << std::endl;
  std::cout << "ASM y(x): " << task2(x) << std::endl;
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  calc(-10);
  calc(0);
  calc(3);
  calc(6);
  calc(10);
  return 0;
}
