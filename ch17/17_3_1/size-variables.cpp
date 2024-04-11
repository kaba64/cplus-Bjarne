#include <iostream>
#include <vector>

int main(int argc,char **argv){

  std::vector<int> v(1000);
  
  std::cout<<"The sizeof reports the number of bytes occupied by an object."<<std::endl;
  std::cout<<"size of char = "<<sizeof(char)<<std::endl;
  std::cout<<"size of char* = "<<sizeof(char*)<<std::endl;
  std::cout<<"size of int = "<<sizeof(int)<<std::endl;
  std::cout<<"size of int* = "<<sizeof(int*)<<std::endl;
  std::cout<<"size of uint32_t = "<<sizeof(uint32_t)<<std::endl;
  std::cout<<"size of uint32_t* = "<<sizeof(uint32_t*)<<std::endl;
  std::cout<<"size of uint64_t = "<<sizeof(uint64_t)<<std::endl;
  std::cout<<"size of uint64_t* = "<<sizeof(uint64_t*)<<std::endl;
  std::cout<<"size of double = "<<sizeof(double)<<std::endl;
  std::cout<<"size of double* = "<<sizeof(double*)<<std::endl;
  std::cout<<"size of a vector = "<<sizeof(v)<<std::endl;
  return 0;
}
