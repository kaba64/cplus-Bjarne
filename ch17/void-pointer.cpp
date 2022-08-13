#include <iostream>

auto main() -> int
{
  void* ptri = new int;
  void* ptri2{ptri};
  int* ptri3 = static_cast<int*>(ptri);
  *ptri3 = 5;
  std::cout<<ptri<<"\n";
  std::cout<<"ptri3 = "<<ptri<<", and *ptri3 = "<<*ptri3<<"\n";
}
