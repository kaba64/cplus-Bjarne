#include <iostream>
#include "vector.h"


int main(int argc,char** argv){

  vector v1(7,6);
  vector v2(4,10);
  std::cout<<"\nBefor copy assignment\n\n";
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.print_vector("v1");
  std::cout<<"v2.size() = "<<v2.size()<<"\tv2.capacity() = "<<v2.capacity()<<"\n";
  v2.print_vector("v2");
  v1=v2;
  std::cout<<"\nAfter copy assignment\n\n";
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.print_vector("v1");
  return 0;
}
