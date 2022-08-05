#include <iostream>

auto main() -> int
{
  constexpr double yen_to_dollar = 0.0075;
  constexpr double euro_to_dollar = 1.02;
  constexpr double pound_to_dollar = 1.22;
  double money{1.};
  char unit = 'a';
  std::cout<<"Please enter an amount of money followed by a unit (y, e or p):\n";
  std::cin>>money>>unit;
  switch(unit){ // usable for integer, character, and enumeration.
  case 'y':
    std::cout<<money<<" yen == "<< yen_to_dollar*money << " dollar\n";
    break;
  case 'e':
    std::cout<<money<<" euro == "<< euro_to_dollar*money << " dollar\n";
    break;
  case 'p':
    std::cout<<money<<" pound == "<< pound_to_dollar*money << " dollar\n";
  default:
    std::cout<<"The entered unit was not in the list!\n";
    break;
  } 
}
