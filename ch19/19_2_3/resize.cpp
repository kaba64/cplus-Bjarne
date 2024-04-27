#include <iostream>
#include "vector.h"


int main(int argc,char** argv){

  vector v1(10,1);
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.resize(2);
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.resize(-1);
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  return 0;
}
