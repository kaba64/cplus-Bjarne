#include <iostream>

auto main() -> int
{
  
  double* p = new double;
  double* q = new double[1000];
  q[700] = 800.;
  std::cout<<"q[0] = "<<q[0]<<std::endl;
  std::cout<<"q[700] = "<<q[700]<<std::endl;
  q=p;
  std::cout<<"q is assigned by p; "<<"q[700] = "<<q[700]<<std::endl;
}
