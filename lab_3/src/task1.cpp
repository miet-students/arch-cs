#include <cstdint>
#include <iostream>

void wzAsm(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
  asm(
      "addl $79, %%eax\n"
      "xor %%edx, %%edx\n"
      "divl %%ecx\n" // частное в A. остаток в D
      : "=a"(z), "=d"(w)
      : "a"(x), "c"(y)
      : "cc");

  std::cout << "ASM:" << std::endl;
  std::cout << "z: " << z << " w: " << w << "\n\n";
}

void wzAsmWithPointers(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
  uint32_t *p = &x, *q = &y;
  asm(
      "movl (%[P]), %%edx\n" //edx = *eax и по какой-то причине просто с (%%eax) оно не работало
      "movl %%edx, %%eax\n"  //eax = edx
      "movl (%[Q]), %%edx\n" //edx = *ecx
      "movl %%edx, %%ecx\n"  //ecx = edx
      "addl $79, %%eax\n"
      "xor %%edx, %%edx\n"
      "divl %%ecx\n"
      : "=a"(z), "=d"(w)
      : [P] "a"(p), [Q] "c"(q) // пришлось добавить алиасы (см. выше)
      : "cc");

  std::cout << "ASM with pointers:" << std::endl;
  std::cout << "z: " << z << " w: " << w << "\n\n";
}

void wz(uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
  z = (x + 79) / y;
  w = (x + 79) % y;

  std::cout << "C++" << std::endl;
  std::cout << "z: " << z << " w: " << w << std::endl;
}

int main(int argc, char **argv)
{
  uint32_t x = 10, y = 5, z, w;

  wzAsm(x, y, z, w);
  wzAsmWithPointers(x, y, z, w);
  wz(x, y, z, w);

  return 0;
}
