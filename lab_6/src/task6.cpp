#include <iostream>
#include <cstdint>

extern "C" double task6();

void printArray(uint32_t *arr, uint32_t N)
{
  for (uint32_t i = 0; i < N; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  double res = task6();
  std::cout << "Sum of Leibniz series by ASM: " <<res<<  std::endl;
  std::cout << "Actual:\t\t\t0.208395496809750404632571499675" << std::endl;
  return 0;
}
