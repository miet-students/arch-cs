#include <iostream>
#include <cstdint>

#define N 10

void print(uint64_t a[], uint64_t size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  uint64_t arr[N] = {0};
  uint64_t k = 5;
  uint64_t j = 8;
  uint64_t x = 42;

  std::cout << "Before:\n";
  print(arr, N);

  asm(
      "movq %[X], (%[array], %[K],8)\n"
      : "=m"(*(uint64_t(*)[N])arr)
      : [array] "r"(arr), [X] "r"(x), [K] "r"(k)
      : "memory");

  std::cout << "After task 4:\n";
  print(arr, N);

  asm(
      "movq $0xff, -5(%[array], %[J], 8)\n"
      : "=m"(*(uint64_t(*)[N])arr)
      : [array] "r"(arr), [J] "r"(j)
      : "memory");

  std::cout << "After task 5:\n";
  print(arr, N);

  return 0;
}
