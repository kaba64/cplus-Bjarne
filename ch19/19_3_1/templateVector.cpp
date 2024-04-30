#include <iostream>
#include "vector.h"

int main(int argc,char** argv){

  vector<int> v1(5,10);
  vector<double> v2(5,0.5);
  v1.print_vector("v1");
  v2.print_vector("v2");
  return 0;
}
