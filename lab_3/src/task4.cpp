#include <iostream>
#include <cstdint>

#define N 10

void print(uint32_t a[], uint32_t size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  uint32_t arr[N] = {0};
  uint32_t k = N / 2;
  uint32_t x = 42;

  std::cout << "Before:\n";
  print(arr, N);

  asm(
      "movl %%eax, (%%ecx, %%edx, 4)\n"
      : /* No output */
      : "a"(x), "c"(arr), "d"(k)
      : "memory");

  std::cout << "After:\n";
  print(arr, N);

  return 0;
}
