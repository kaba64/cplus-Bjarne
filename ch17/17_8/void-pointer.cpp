#include <iostream>
#include <exception>
#include <iomanip>

int main(int argc,char** argv){
  std::cout<<"\nAssigning a int* to a void*\n\n";
  void* ptri = new int;
  try{
    void* ptri2{ptri};
    int* ptri3 = static_cast<int*>(ptri);
    *ptri3 = 5;
    std::cout<<"ptri = "<<reinterpret_cast<uintptr_t>(ptri)<<"\n";
    std::cout<<"ptri3 = "<<reinterpret_cast<uintptr_t>(ptri3)<<", and *ptri3 = "<<*ptri3<<"\n";
    std::cout<<"\nAllocate void* ptrd = new double and assign to it *ptrd = 987654321987.0\n\n";
    void* ptrd = new double;
    double* ptrdU = static_cast<double*>(ptrd);
    *ptrdU = 987654321987.0;
    std::cout<<"ptrdU = "<<reinterpret_cast<uintptr_t>(ptrdU)<<std::setprecision(20)<<", and *ptrdU = "<<*ptrdU<<"\n";
    delete static_cast<double*>(ptrd);
  }catch(const std::exception& e){
    std::cerr<<"Error : "<<e.what()<<"\n";
  }
  delete static_cast<int*>(ptri);
  return 0;
}
