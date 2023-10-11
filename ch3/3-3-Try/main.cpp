#include <iostream>
/*The try this of book page 65
  Kazem Bazesefidpar
  11 October, 2023 
*/
auto main() -> int
{
  std::cout<<"PLease enter your first fist name, surname, and age\n";
  std::string first_name, last_name;
  double age;
  std::cin>>first_name>>last_name;
  std::cin>>age;
  // Conver the age to month
  age*=12;
  std::cout<<"Hello, "<<first_name<<" "<<last_name<<"(age in month "<<age<<")\n";
}
