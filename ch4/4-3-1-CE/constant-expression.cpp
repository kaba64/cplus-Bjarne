#include <iostream>
#include <cmath>

constexpr double pi = acos(-1.);

auto main() -> int
{
  double halfpi{pi*0.5},a;
  //pi = 1.; It will generate error
  std::cout<<"Please enter the value for the gravity :"<<"\n";
  std::cin>>a;
  const double gravity=a;  // use const when the value is not known at compile time
  std::cout<<"pi = "<<pi<<" half_pi = "<<halfpi<<"\n";
  std::cout<<"pi difference = "<<pi-3.141592653<<"\n";
  std::cout<<"gravity = "<<gravity<<"\n";
}
