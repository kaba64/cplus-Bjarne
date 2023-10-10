#include <iostream>
#include <vector>

auto main() -> int
{
  std::vector<int> v(1000);
  std::cout<<"The sizeof reports the number of bytes occupied by an object."<<std::endl;
  std::cout<<"size of char = "<<sizeof(char)<<std::endl;
  std::cout<<"size of integer = "<<sizeof(int)<<std::endl;
  std::cout<<"size of integer pointer = "<<sizeof(int*)<<std::endl;
  std::cout<<"size of double = "<<sizeof(double)<<std::endl;
  std::cout<<"size of a vector = "<<sizeof(v)<<std::endl;
}
