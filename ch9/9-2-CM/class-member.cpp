#include <iostream>

class X{
public:
  int m; // data function
  int mf(int v){int old=m;m=v;return old;} // member function
};


auto main() -> int
{
  X y;
  int num{5};
  y.m = 2;
  std::cout<<"num = "<<num<<" old num = "<<y.mf(num)<<"\n";
}
