#include <iostream>
#include <cstdint>
#include <cmath>

void init_printArray(double *arr, uint32_t N, uint32_t M)
{
  for (uint32_t i = 0; i < N; i++)
  {
    for (uint32_t j = 0; j < M; j++)
    {
        *(arr + i*M+j) = (double)((i+j)%10+5)/10;
        std::cout <<*(arr + i*M+j) << " " ;
    }
    std::cout<<std::endl;
  }
  std::cout << std::endl;
}

double ProductArrayCPP(double *arr, uint32_t N, uint32_t M)
{
    double product = 1;
    for (uint32_t i = 0; i < N; i++)
    {
      for (uint32_t j = 0; j < M; j++)
      {
          product*= *(arr + i*M+j);
      }
    }
    return product;
}

double ProductArrayASM(double *arr, uint32_t N, uint32_t M)
{
  uint32_t j, i, idx = 0;
  double volatile product = 1.0;
  asm(
      "xorl %[IDX], %[IDX]\n"
      "fldl %[PR]\n"

      "xorl %[I], %[I]\n"
      "loop_begin_row:\n"
      "cmpl %[ROW], %[I]\n"
      "jge loop_end_row\n"

      "xorl %[J], %[J]\n"
      "loop_begin_col:\n"
      "cmpl %[COL], %[J]\n"
      "jge loop_end_col\n"

      "movq (%[ARR], %q[IDX]), %%rax\n"
      "push  %%rax\n"
      "fldl (%%rsp)\n"
      "pop %%rax\n"

      "fmulp %%st(1), %%st(0)\n"

      "addl $8, %[IDX]\n"

      "incl %[J]\n"
      "jmp loop_begin_col\n"
      "loop_end_col:\n"
      "incl %[I]\n"
      "jmp loop_begin_row\n"
      "loop_end_row:\n"
      "fstpl %[PR]\n"
      : [I] "=&r"(i), [J] "=&r"(j), [PR] "=m"(product)
      : [ROW] "c"(N), [COL] "d"(M), [ARR] "r"(arr), [IDX] "r"(idx)
      : "cc", "memory", "eax");
  return product;
}

int main()
{
    double *array;
    uint32_t N=4, M=7;

    array = new double [N*M];

    init_printArray(array, N, M);
    std::cout<<"Product from cpp= "<<ProductArrayCPP(array, N, M)<<std::endl;
    std::cout<<"Product from asm= "<<ProductArrayASM(array, N, M)<<std::endl;

    delete[] array;
  return 0;
}
