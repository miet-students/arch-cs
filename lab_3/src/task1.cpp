#include <cstdint>
#include <iostream>

void wzAsm(uint64_t x, uint64_t y, uint64_t z, uint64_t w)
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

void wzAsmWithPointers(uint64_t x, uint64_t y, uint64_t z, uint64_t w)
{
  uint64_t *p = &x, *q = &y;
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

void wzAsmWithoutReferences(uint64_t x, uint64_t y, uint64_t z, uint64_t w)
{
  std::cout << "ASM without references:" << std::endl;
  std::cout << "z: " << z << " w: " << w << "\n\n";
}

void wz(uint64_t x, uint64_t y, uint64_t z, uint64_t w)
{
  z = (x + 79) / y;
  w = (x + 79) % y;

  std::cout << "C++" << std::endl;
  std::cout << "z: " << z << " w: " << w << std::endl;
}

int main(int argc, char **argv)
{
  uint64_t x = 10, y = 5, z, w;

  wzAsm(x, y, z, w);
  wzAsmWithPointers(x, y, z, w);
  wz(x, y, z, w);
  return 0;
}
