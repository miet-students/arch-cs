#include <iostream>
#include <cstdint>

extern "C" uint32_t task1(uint32_t x, uint32_t y);

int main(int argc, char **argv)
{
  uint32_t x = 5, y = 10, z;

  z = task1(x, y);
  std::cout << "ASM: " << z << std::endl;

  z = 657 + 5 * x + 2 * y;
  std::cout << "C++: " << z << std::endl;

  return 0;
}
