#include <iostream>

auto main() -> int
{
  char c1='x';
  int i1=c1;
  int i2='x';
  char c2=i1;
  std::cout<<"Char1 = "<<c1<<"\n";
  std::cout<<"Char2 = "<<c2<<"\n";
  std::cout<<"Int1  = "<<i1<<"\n";
  std::cout<<"Int2  = "<<i2<<"\n";
}
