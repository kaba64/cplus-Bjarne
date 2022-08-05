#include <iostream>
#include <vector>

void init(std::vector<int> &vi){
  for(unsigned int i=0;i<vi.size();++i){
    vi[i]=2*i;
  }
}

void printv(std::vector<int> vi){
  for(unsigned int i=0;i<vi.size();++i){
    std::cout<<"vi["<<i<<"] =\t"<<vi[i]<<"\n";
  }
}

auto main() -> int
{
  std::vector<int> v(5);
  init(v);
  //printv(v);
  for(int x:v){
    std::cout<<x<<"\n";
  }
}
