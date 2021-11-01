#include <iostream>
#include <cstdint>

void printSequence(int N, int x0)
{
  int xi = x0;
  std::cout << xi << " ";
  for (int i = 1; i <= N; i++)
  {
    if (xi % 2 == 0)
    {
      xi = xi / 2;
    }
    else
    {
      xi = 3 * xi + 1;
    }

    std::cout << xi << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  int N, x0;
  std::cout << "Enter N:\n>>> ";
  std::cin >> N;
  std::cout << "Enter x0:\n>>> ";
  std::cin >> x0;
  printSequence(N, x0);
  return 0;
}
