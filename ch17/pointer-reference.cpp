#include <iostream>

auto main() -> int
{
  int y = 10;
  int& r = y;
  std::cout<<"*y = "<<&y<<" ; *r = "<<&r<<std::endl;
  int z = 7;
  r = &z;
  //std::cout<<"*y = "<<&y<<" ; *r = "<<&r<<std::endl;
  //std::cout<<"y = "<<y<<" ; r = "<<r<<std::endl;
}
