#include <iostream>
#include <vector>
#include <exception>


int main(int argc,char** argv){

  const int N = 1<<12;
  int* p{nullptr};
  try{
    p = new int[N];
  }catch(...){
    delete[] p;
    throw;
  }
  std::vector<int> v1;
  double* d{nullptr};
  try{
    d = new double[N];
  }catch(...){
    delete[] d;
    throw;
  }
  std::vector<double> d1;

  delete[] p;
  delete[] d;
  
  return 0;
}
