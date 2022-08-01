#include <iostream>

class X{
private:
  int m;
  int mf(int v){int old=m;m=v;return old;}
public:
  int f(int i){return mf(i);}
};

auto main() -> int
{
  X y;
  int num{5};
  std::cout<<"num = "<<num<<" old num = "<<y.f(num)<<"\n";
}
