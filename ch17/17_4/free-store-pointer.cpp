#include <iostream>
#include <cstdint>

int main(int argc, char** argv) {
  double* Dptr = new double[4];
  std::cout << "size of Dptr (double* Dptr = new double[4]): " << sizeof(Dptr) << std::endl;
  
  uintptr_t decimalDPtr = reinterpret_cast<uintptr_t>(Dptr);
  std::cout << "The value of Dptr: " << Dptr << std::endl;
  std::cout << "The decimal value of Dptr: " << decimalDPtr << std::endl;

  
  uintptr_t decimalDPtrPlusOne = reinterpret_cast<uintptr_t>(Dptr + 1);
  std::cout << "The value of Dptr+1 : " << Dptr+1 << std::endl;
  std::cout << "The decimal value of Dptr + 1: " << decimalDPtrPlusOne << std::endl;

  std::cout<<"\n\n";
  int* Iptr = new int[4];
  std::cout << "size of Iptr (double* Iptr = new int[4]): " << sizeof(Iptr) << std::endl;
  
  uintptr_t decimalIPtr = reinterpret_cast<uintptr_t>(Iptr);
  std::cout << "The value of Iptr: " << Iptr << std::endl;
  std::cout << "The decimal value of Iptr: " << decimalIPtr << std::endl;
  
  uintptr_t decimalIPtrPlusOne = reinterpret_cast<uintptr_t>(Iptr + 1);
  std::cout << "The value of Iptr+1 : " << Iptr+1 << std::endl;
  std::cout << "The decimal value of Iptr + 1: " << decimalIPtrPlusOne << std::endl;
  
  delete[] Dptr;
  delete[] Iptr;
  return 0;
}
