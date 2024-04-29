#include <iostream>
#include "vector.h"


int main(int argc,char** argv){

  vector v1;
  std::cout<<"\nBefor push_back\n\n";
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.print_vector("v1");
  v1.push_back(15.0);
  std::cout<<"\nAfter push_back\n\n";
  std::cout<<"v1.size() = "<<v1.size()<<"\tv1.capacity() = "<<v1.capacity()<<"\n";
  v1.print_vector("v1");
  return 0;
}
