#include <iostream>
#include <exception>
#include <vector>
#include "init-write.h"

void init(std::vector<int> &v)
{
  for(int x;std::cin>>x;)
    v.push_back(x);
}

void printv(std::vector<int> v)
{
  for(unsigned int i=0;i<=v.size();++i)
    std::cout<<"v["<<i<<"]=="<<v[i]<<"\n";
}
