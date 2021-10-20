#include <cstdint>
#include <iostream>

#define float double //change to either float or double

#define START 1000
#define STOP 1000000000
#define STEP 1000 // multiply by

float sumForward(uint64_t N)
{
  float S = 0;
  for (uint64_t i = 1; i <= N; i++)
  {
    S += (float)1 / i;
  }
  return S;
}

float sumBackward(uint64_t N)
{
  float S = 0;
  for (uint64_t i = N; i >= 1; i--)
  {
    S += (float)1 / i;
  }
  return S;
}

int main(int argc, char **argv)
{
  for (uint64_t i = START; i <= STOP; i *= STEP)
  {
    std::cout << "N: " << i << std::endl;
    std::cout << "Forward: " << sumForward(i) << std::endl;
    std::cout << "Backward: " << sumBackward(i) << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
