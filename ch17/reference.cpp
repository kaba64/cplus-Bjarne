#include <iostream>

auto main() -> int
{
  int x{2};
  int& x1=x;
  std::cout<<"x = "<<x<<", x1 = "<<x1<<"\n";
  std::cout<<"&x = "<<&x<<", &x1 = "<<&x1<<"\n";
  int y{3};
  int& y1 = y;
  std::cout<<"y = "<<y<<", y1 = "<<y1<<"\n";
  std::cout<<"&y = "<<&y<<", &y1 = "<<&y1<<"\n";
  x1=y1;
  std::cout<<"x = "<<x<<", x1 = "<<x1<<"\n";
  std::cout<<"&x = "<<&x<<", &x1 = "<<&x1<<"\n";
  std::cout<<"y = "<<y<<", y1 = "<<y1<<"\n";
  std::cout<<"&y = "<<&y<<", &y1 = "<<&y1<<"\n";
  //x1=&y; /*error */
}
