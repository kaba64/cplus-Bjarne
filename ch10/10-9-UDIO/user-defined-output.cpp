#include <iostream>
#include <fstream>

class Date{
public:
  Date(int yi,int mi,int di)
    :y{yi},m{mi},d{di}{}
  int y,m,d;
};

std::ostream& operator<<(std::ostream& os, const Date& d){
    return os<<"("<<d.y<<","<<d.m<<","<<d.d<<")\n";
  }
auto main() -> int
{
  Date today{2022,8,7}, tomorrow{2022,8,8};
  std::cout<<today<<tomorrow;
}
