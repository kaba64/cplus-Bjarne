#include <iostream>

int main(int argc,char** argv){
  
  int x{2};
  int& x1=x;
  std::cout<<"x = "<<x<<", x1 = "<<x1<<"\n";
  std::cout<<"&x = "<<reinterpret_cast<uintptr_t>(&x)<<", &x1 = "<<reinterpret_cast<uintptr_t>(&x1)<<"\n";
  int y{3};
  int& y1 = y;
  std::cout<<"y = "<<y<<", y1 = "<<y1<<"\n";
  std::cout<<"&y = "<<reinterpret_cast<uintptr_t>(&y)<<", &y1 = "<<reinterpret_cast<uintptr_t>(&y1)<<"\n";
  std::cout<<"\nThe value of y is assigned to x via their references, but the memory locations of references are immutable\n\n";
  x1=y1;
  std::cout<<"x = "<<x<<", x1 = "<<x1<<"\n";
  std::cout<<"&x = "<<reinterpret_cast<uintptr_t>(&x)<<", &x1 = "<<reinterpret_cast<uintptr_t>(&x1)<<"\n";
  std::cout<<"y = "<<y<<", y1 = "<<y1<<"\n";
  std::cout<<"&y = "<<reinterpret_cast<uintptr_t>(&y)<<", &y1 = "<<reinterpret_cast<uintptr_t>(&y1)<<"\n";
  
  //x1=&y; /*error */
  return 0;
}
