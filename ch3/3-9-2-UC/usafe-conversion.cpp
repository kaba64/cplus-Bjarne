#include <iostream>

auto main() -> int
{
  int a;
  while(std::cin>>a){
    char c{a};
    int b{c};
    if(a!=b){
      std::cout<<a<<"!="<<b<<"\n";
    }else{
      std::cout<<a<<"=="<<b<<"\n";
    }
  }
}
