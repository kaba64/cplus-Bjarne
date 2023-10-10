#include <iostream>

auto main() -> int
{
  double* ptr = new double[4];
  std::cout<<"size of double pointer = "<<ptr<<std::endl;
  std::cout<<"size of double pointer = "<<ptr+1<<std::endl;
}
