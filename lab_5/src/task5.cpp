#include <iostream>
#include <cstdint>
#include <cmath>
#define N 4
void print(double* arr)
{
    for (int i=0;i<4;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void Cpp(double* x, double* y)
{
    std::cout<<"Cpp z: ";
    for (int i=0;i<4;i++)
    {
        std::cout<<(x[i]+y[i])*(x[i]-y[i])<<" ";
    }
    std::cout<<std::endl;
}

void calc(double x[N], double y[N], double z[N])
{
  std::cout << "x: "; print(x);
  std::cout << "y: "; print(y);
  Cpp(x, y);
  asm volatile(
      "vmovupd (%[x]), %%ymm0\n"
      "vmovupd (%[y]), %%ymm1\n"
      "vsubpd %%ymm1, %%ymm0, %%ymm0\n"
      "vaddpd %%ymm0, %%ymm1, %%ymm2\n"
      "vaddpd %%ymm1, %%ymm2, %%ymm2\n"
      "vmulpd %%ymm0, %%ymm2, %%ymm0\n"
      "vmovupd %%ymm0, (%[z])\n"

       :[z]"=d"(z)
       :[x]"a"(x), [y]"c"(y)
       :"cc"
       );

  std::cout << "ASM z: "; print(z);
}

int main()
{
  double x[N];
  double y[N];
  double z[N];
  for(int i=0; i<N; i++)
  {
      x[i] = i-8;
      y[i] = i+3;
  }
  calc(x, y, z);
  return 0;
}
