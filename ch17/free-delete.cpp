#include <iostream>

auto main() -> int
{

  //double* ptr=new double{5.};
  double* ptr=nullptr;
  std::cout<<std::hex<<ptr<<"\n";
  delete ptr;
  std::cout<<std::hex<<ptr<<"\n";
  delete ptr; /* This will give an error */
}
