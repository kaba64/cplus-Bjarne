#include <iostream>

struct Date{
  int y,m,d;
  Date(int yi,int mi,int di){y=yi;m=mi;d=di;}
};

auto main() -> int
{
  Date today{2022,7,31};
  //std::cout<<"Please enter Year Month Day"<<"\n";
  //std::cin>>today.y>>today.m>>today.d;
  std::cout<<today.y<<"/"<<today.m<<"/"<<today.d<<"\n";
}
