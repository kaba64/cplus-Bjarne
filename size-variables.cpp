#include <iostream>
#include <vector>

auto main() -> int
{
  char a ;
  int var;
  int *ptr;
  std::vector<int> v(1000);
  std::cout<<"The sizeof reports the number of bytes occupied by an object."<<std::endl;
  std::cout<<"size of char = "<<sizeof(a)<<std::endl;
  std::cout<<"size of integer = "<<sizeof(var)<<std::endl;
  std::cout<<"size of integer pointer = "<<sizeof(ptr)<<std::endl;
  std::cout<<"size of a vector = "<<sizeof(v)<<std::endl;
}
