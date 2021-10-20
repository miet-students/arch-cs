#include <iostream>
#include <cstdint>

double leibnizSeriesSum(double eps)
{
  double s1;
  double s2 = 2 * eps;
  double sum = 0;
  uint64_t i = 1;
  // Свойство: остаток ряда по модулю меньше первого отброшенного члена
  while (s2 > eps)
  {
    s1 = -(double)(i * i - 1) / (i * i * i);
    s2 = (double)((i + 1) * (i + 1) - 1) / ((i + 1) * (i + 1) * (i + 1));
    sum += s1 + s2;
    i += 2;
  }
  return sum;
}

int main(int argc, char **argv)
{
  double eps, leibnizSum;
  eps = 0.0001;
  leibnizSum = leibnizSeriesSum(eps);
  std::cout << "Accuracy:              " << eps << std::endl;
  std::cout << "Sum of Leibniz series: " << leibnizSum << std::endl;
  return 0;
}
