#include <iostream>

auto main() -> int
{
  int x{7};
  int y{1};
  {
    int x=y;
    ++x;
    std::cout<<"inner x = "<<x<<std::endl;
  }
  ++x;
  std::cout<<"outer x = "<<x<<std::endl;
}
