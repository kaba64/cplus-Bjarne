#include <iostream>
#include <exception>
#include <vector>
#include "init-write.h"

auto main() -> int
{
  std::vector<int> v;
  try{
    for(int x;std::cin>>x;)
      v.push_back(x);
    for(unsigned int i=0;i<=v.size();++i)
      std::cout<<"v["<<i<<"]=="<<v.at(i)<<"\n";
  }catch(std::out_of_range &e){
    std::cerr<<"Out of range error :"<<e.what()<<"\n";
    return 1;
  }catch(...){
    std::cerr<<"Exception : something went wrong!\n";
    return 2;
  }
}
