#include <iostream>
#include <cstdint>
extern "C" uint32_t print(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
uint32_t print(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;
  std::cout << "d: " << d << std::endl;
  std::cout << "e: " << e << std::endl;
  return e;
}
