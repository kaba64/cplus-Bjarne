#include <iostream>

int absva(int x){
  if(x<0){
    return -x;
  }else if(x>=0){
    return x;
  }
}

auto main() -> int
{
  int a{-1};
  std::cout<<absva(a)<<"\n";
}
