#include <iostream>
#include <vector>

auto main() -> int
{
  std::vector<int> x(5);
  int i{2};
  //x[i]=++i;
  x[++i]=i;
  std::cout<<"i = "<<i<<"x = "<<x[i]<<"\n";
  
}
