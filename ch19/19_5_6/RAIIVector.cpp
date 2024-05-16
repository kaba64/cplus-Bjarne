#include <iostream>
#include "vector.h"

vector<int> createVector(int size,int value) {
  vector<int> temp(size,value);
  return temp;
}
void useVector(vector<int> src,const std::string & name){
  src.print_vector(name);
}
int main(int argc,char** argv){
  
  vector<int> vInt = createVector(3,10);
  useVector(vInt,"vInt");
  vector<int> vInt2(10,1);
  vInt2 = std::move(vInt); // Move assignment called
  useVector(vInt2,"vInt2");
  return 0;
}
