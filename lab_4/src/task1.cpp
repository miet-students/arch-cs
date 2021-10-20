#include <iostream>
#include <cstdint>

extern "C" uint32_t task1(uint32_t x, uint32_t y);

int main(int argc, char **argv)
{
  uint32_t x = 1, y = 0, z;

  z = task1(x, y);
  std::cout << "ASM: " << z << std::endl;

  z = 4 * x + 234 + y;
  std::cout << "C++: " << z << std::endl;

  return 0;
}
