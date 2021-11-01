#include <iostream>
#include <cstdint>

void printArray(uint32_t *arr, uint32_t N)
{
  for (uint32_t i = 0; i < N; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void initArray(uint32_t *arr, uint32_t N, uint32_t x0)
{
  uint32_t tmp, i;
  asm(
      "xorl %[I], %[I]\n"
      "xorl %[TMP], %[TMP]\n"
      "movl %[X0], %[TMP]\n"

      "loop_begin:\n"
      "cmp %[LEN], %[I]\n"
      "jge loop_end\n"

      "test $0b1, %[TMP]\n"
      "jne if_else\n"

      "shrl $1, %[TMP]\n"
      "jmp if_end\n"

      "if_else:\n"
      "xorl %%eax, %%eax\n"
      "movl %[TMP], %%eax\n"
      "mul %[Three]\n"
      "lea 1(%%eax), %[TMP]\n"

      "if_end:\n"

      "movl %[TMP], (%[ARR], %q[I], 4)\n"

      "incl %[I]\n"
      "jmp loop_begin\n"
      "loop_end:\n"
      : [I] "=&r"(i), [TMP] "=r"(tmp)
      : [LEN] "r"(N), [ARR] "r"(arr), [X0] "r"(2 * x0), [Three] "r"(3)
      : "cc", "memory", "%eax");
}

int main(int argc, char **argv)
{
  uint32_t *array;
  uint32_t N, x0, tmp, i;

  std::cout << "Enter N:\n>>> ";
  std::cin >> N;
  std::cout << "Enter x0:\n>>> ";
  std::cin >> x0;

  array = new uint32_t[N];

  initArray(array, N, x0);
  printArray(array, N);

  delete[] array;
  return 0;
}
