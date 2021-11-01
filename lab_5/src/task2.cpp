#include <iostream>
#include <cstdint>

double leibnizSeriesSum(double eps)
{
  double s1;
  double s2 = 2 * eps;
  double sum = 0;
  uint64_t end = 2;
  // Свойство: остаток ряда по модулю меньше первого отброшенного члена
  while(1)
  {
      s1 = (double)(end * end - 1) / (end * end * end);
      if (s1<eps)
          break;
      end+=2;
  }

  for (uint64_t i = end; i >= 1; i-=2)
  {
    s1 = (double)(i * i - 1) / (i * i * i);
    s2 = -(double)((i - 1) * (i - 1) - 1) / ((i - 1) * (i - 1) * (i - 1));
    sum += s1 + s2;
  }
  return sum;
}

int main()
{
  double eps, leibnizSum;
  eps = 0.000001;
  leibnizSum = leibnizSeriesSum(eps);
  std::cout << "Accuracy:              " << eps << std::endl;
  std::cout << "Sum of Leibniz series: " << leibnizSum << std::endl;
  std::cout << "Actual:\t\t   0.208395496809750404632571499675" << std::endl;
  return 0;
}

