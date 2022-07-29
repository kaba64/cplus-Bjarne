#include <iostream>

auto main() -> int
{
  void* ptr1 = new int;
  void* ptr2 = new double[10];
  void* ptr3 = ptr2;
  //double* ptr4 = ptr2; // You will get error
  double* ptr4 = static_cast<double *>(ptr2);
}
