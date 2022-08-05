#include <iostream>
#include <vector>

void init(std::vector<double> &vi,int n){
  for(int i=0;i<n;++i){
    vi.push_back(2.*i);
  }
}

void printv(std::vector<double> vi){
  for(unsigned int i=0;i<vi.size();++i){
    std::cout<<"vi["<<i<<"] =\t"<<vi[i]<<"\n";
  }
}

auto main() -> int
{
  std::vector<double> v;
  int element=10;
  init(v,element);
  printv(v);
  
}
