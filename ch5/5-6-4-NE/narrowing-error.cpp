#include <iostream>
#include <std_lib_facilities.h>

auto main() -> int
{
  int x1 = narrow_cast<int>(2.0);
  int x2 = narrow_cast<int>(2.9);
  char c1 = narrow_cast<char>(55);
  char c2 = narrow_cast<char>(1155);
  std::cout<<"Int1 = "<<x1<<" char1 = "<<c1<<"\n";
  std::cout<<"Int2 = "<<x2<<" char2 = "<<c2<<"\n";
}
