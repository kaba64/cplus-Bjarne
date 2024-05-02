#include <iostream>
#include "vector.h"

int main(int argc,char** argv){
  
  vector<int> vInt;
  vInt.resize(5);
  vInt.resize(10,10);
  vInt.print_vector("vInt");
  
  vector<double> vDouble;
  vDouble.resize(5);
  vDouble.resize(10,10.5);
  vDouble.print_vector("vDouble");
  return 0;
}
