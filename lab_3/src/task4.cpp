#include <iostream>
#include <cstdint>

#define N 10

void print(uint32_t a[], uint32_t size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << std::hex << a[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  uint32_t arr[N] = {0};
  uint32_t k = 5;
  uint32_t j = 1;
  uint32_t x = 42;

  std::cout << "Before:\n";
  print(arr, N);

  asm(
      "mov %[X], (%[array], %q[K], 4)\n"
      :
      : [array] "r"(arr), [X] "r"(x), [K] "r"(k)
      : "memory");

  std::cout << "After task 4:\n";
  print(arr, N);

  asm(
      "movl $0xff, 3(%[array], %q[J], 4)\n"
      :
      : [array] "r"(arr), [J] "r"(j)
      : "memory");

  std::cout << "After task 5:\n";
  print(arr, N);

  return 0;
}
