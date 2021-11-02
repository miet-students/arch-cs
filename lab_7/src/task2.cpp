#include <iostream>
#include <cstdint>
#include <cmath>

void init_printArray(int *arr, uint32_t N, uint32_t M)
{
  for (uint32_t i = 0; i < N; i++)
  {
    for (uint32_t j = 0; j < M; j++)
    {
        *(arr + i*M+j) = (i+j)%4+1;
        std::cout <<*(arr + i*M+j) << " " ;
    }
    std::cout<<std::endl;
  }
  std::cout << std::endl;
}

int ProductArrayCPP(int *arr, uint32_t N, uint32_t M)
{
    int product = 1;
    for (uint32_t i = 0; i < N; i++)
    {
      for (uint32_t j = 0; j < M; j++)
      {
          product*= *(arr + i*M+j);
      }
    }
    return product;
}

int ProductArrayASM(int *arr, uint32_t N, uint32_t M)
{
  uint32_t j, i, idx = 0;

  int product = 1;
  asm(
      "xorl %[IDX], %[IDX]\n"
      "movl $1, %[PR]\n"

      "xorl %[I], %[I]\n"
      "loop_begin_row:\n"
      "cmpl %[ROW], %[I]\n"
      "jge loop_end_row\n"

      "xorl %[J], %[J]\n"
      "loop_begin_col:\n"
      "cmpl %[COL], %[J]\n"
      "jge loop_end_col\n"

      "xorl %%eax, %%eax\n"                 //TODO
      "movl (%[ARR], %q[IDX]), %%eax\n"     //don't no how to get the value
      "imull %%eax, %[PR]\n"              //END TODO

      "addl $4, %[IDX]\n"

      "incl %[J]\n"
      "jmp loop_begin_col\n"
      "loop_end_col:\n"

      "incl %[I]\n"
      "jmp loop_begin_row\n"
      "loop_end_row:\n"
      : [I] "=&r"(i), [J] "=&r"(j), [PR] "=&r"(product)
      : [COL] "c"(N), [ROW] "d"(M), [ARR] "r"(arr), [IDX] "r"(idx)
      : "cc", "memory", "%eax");
  return product;
}

int main()
{
    int *array;
    uint32_t N=4, M=7;

    array = new int [N*M];

    init_printArray(array, N, M);
    std::cout<<"Product from cpp= "<<ProductArrayCPP(array, N, M)<<std::endl;
    std::cout<<"Product from asm= "<<ProductArrayASM(array, N, M)<<std::endl;

    delete[] array;
  return 0;
}
