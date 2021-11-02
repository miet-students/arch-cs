#include <iostream>
#include <cstdint>
#include <cmath>

#define COL 50
#define ROW 100

int main()
{
  int arr[ROW][COL];
  std::cout << "1) Size of element: " << sizeof(arr[0][0]) << std::endl;
  std::cout << "2) Adress of arr[" <<ROW/2<<"]["<<COL/2<<"] : "<< &arr[ROW/2][COL/2] << std::endl;
  std::cout << "   Adress of arr[" <<ROW/2<<"]["<<COL/2+1<<"] : "<< &arr[ROW/2][COL/2+1] << std::endl;
  std::cout << "3) Adress of arr[" <<ROW/2<<"]["<<COL/2<<"] : "<< &arr[ROW/2][COL/2] << std::endl;
  std::cout << "   Adress of arr[" <<ROW/2+1<<"]["<<COL/2<<"] : "<< &arr[ROW/2+1][COL/2] << std::endl;
  std::cout << "4) Size of matrix: " << sizeof(arr) << std::endl;
  std::cout << "5) i= 5, j= 10" << std::endl;
  std::cout << "   &a[i][j] = " << &arr[5][10]<< std::endl;
  std::cout << "   &a[0][0]+i*COL+j = " <<(&arr[0][0]+5*COL+10)<< std::endl;
  return 0;
}
