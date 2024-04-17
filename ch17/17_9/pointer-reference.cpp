#include <iostream>

int main(int argc,char** argv){
  int y = 10;
  int& r = y;
  std::cout<<"pointer : &y = "<<reinterpret_cast<uintptr_t>(&y)<<" ;pointer : &r = "<<reinterpret_cast<uintptr_t>(&r)<<std::endl;
  int z = 7;
  int& r2 = z;
  std::cout<<"pointer : &z = "<<reinterpret_cast<uintptr_t>(&z)<<" ;pointer : &r2 = "<<reinterpret_cast<uintptr_t>(&r2)<<std::endl;
  /* generates error since we cannot change the value of a reference
  r2 = r1;
  */
  return 0;
}
