#include <iostream>
#include <cstdint>
#include <cmath>
//#pragma pack(4)

struct MyMap{
    int key;
    char aligment[4];
    double val;
};

void init_print(MyMap* arr, uint32_t N)
{
    for (uint32_t i=0; i<N;i++)
    {
        arr[i].key = i%4+1;
        arr[i].val = (double)(i%10+1)/5;
        std::cout<<arr[i].key<<"->"<<arr[i].val<<std::endl;
    }
}

double ProductArrayCPP(MyMap *arr, uint32_t N, int k)
{
    double PR=1;
    for (uint32_t i=0; i<N;i++)
    {
        if (arr[i].key==k)
            PR*=arr[i].val;
    }
    return PR;
}

double ProductArrayASM(MyMap *arr, uint32_t N, int k)
{
  uint32_t i, idx = 0;
  double volatile product = 1.0;
  asm(
      "xorl %[IDX], %[IDX]\n"
      "fldl %[PR]\n"

      "xorl %[I], %[I]\n"
      "loop_begin:\n"
      "cmpl %[LEN], %[I]\n"
      "jge loop_end\n"

      "movl (%[ARR], %q[IDX]), %%ebx\n"
      "cmpl %[k], %%ebx\n"
      "jne not_equal\n"

      "movq 8(%[ARR], %q[IDX]), %%rax\n"
      "push  %%rax\n"
      "fldl (%%rsp)\n"
      "pop %%rax\n"
      "fmulp %%st(1), %%st(0)\n"
      "jmp not_equal\n"

      "not_equal:\n"
      "addl $16, %[IDX]\n"
      "incl %[I]\n"
      "jmp loop_begin\n"
      "loop_end:\n"
      "fstpl %[PR]\n"
      : [I] "=&r"(i), [PR] "=m"(product)
      : [LEN] "c"(N), [ARR] "r"(arr), [k] "r"(k), [IDX] "r"(idx)
      : "cc", "memory", "ebx", "rax");
  return product;
}

int main()
{
  std::cout<<"Size of structure: "<<sizeof(MyMap)<<std::endl;
  std::cout<<"Size of fields: "<<sizeof(int)+sizeof(double)<<std::endl;
  int k = 3;
  uint32_t N = 20;
  MyMap array[N];
  init_print(array, N);
  std::cout<<"Product by CPP of elements with key = "<<k<<" is "<<ProductArrayCPP(array, N, k)<<std::endl;
  std::cout<<"Product by ASM of elements with key = "<<k<<" is "<<ProductArrayASM(array, N, k)<<std::endl;
  return 0;
}
