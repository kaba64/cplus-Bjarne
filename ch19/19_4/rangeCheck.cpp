#include <iostream>
#include "vector.h"

int main(int argc,char** argv){
  
  vector<int> vInt(5,10);
  vInt.print_vector("vInt");
  std::cout<<"Access the out of range : vInt.at(vInt.size()) \n";
  std::cout<<vInt.at(vInt.size())<<"\n";
  return 0;
}
