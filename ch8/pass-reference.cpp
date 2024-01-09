#include <iostream>
#include <vector>

void init(std::vector<double>&x){
  for(size_t i=0;i<x.size();++i){
    x[i]=1.*i;
  }
}

void printv(const std::vector<double>& x){
  std::cout<<"{";
  for(size_t i=0;i<x.size();++i){
    std::cout<<x[i];
    if(i<x.size()-1) std::cout<<", ";
  }
  std::cout<<"}\n";
}

auto main() -> int
{
  std::vector<double> a(5);
  init(a);
  printv(a);
}
